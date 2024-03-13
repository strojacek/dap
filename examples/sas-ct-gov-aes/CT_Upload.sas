/*----------------------------------------------------------------------------------*

   *******************************************************
   *** Copyright 2017, Rho, Inc.  All rights reserved. ***
   *******************************************************

   MACRO:      CT_Upload
   
   PURPOSE:    Generate ADAE data to upload to CT.gov 

   DESCRIPTION: Generate CT.gov AE summary deliverable. 
                (For dataset specs, see S:\RhoFED\NIAID\DAIT\General\DataSharing\ClinicalTrials.gov\Templates\Adverse Events\Adverse Event Table Specs.docx)
                Requires a coded AE dataset to run.
                Macro accounts for (non-)randomized studies, # of treatment groups, names of ID and AE variables.
               
   ARGUMENTS:  SUBJLVLDS      => <Dataset>         name of subject-level dataset in the &SUBJLVLDS directory
               SUBJFLDR       => <Folder Path>     complete path to the folder where &SUBJLVLDS resides
               ADAEDS         => <Dataset>         name of coded AE dataset
               ADAEFLDR       => <Folder Path>     complete path to the folder where &ADAEDS resides
               RANDDS         => <Dataset>         name of dataset which contains randomization variable (defaults to &SUBJLVLDS)
               RANDFLDR       => <Folder Path>     complete path to where resides (defaults to &SUBJFLDR)
               RAND           => <Variable name>   name of randomization flag variable in &SUBJLVLDS (defaults to RAND)
                                                   &RAND should be a character variable that takes on positive values such as 'Yes', 'Y', '1', 'randomized' (any case works).
                                                   if your study does not have randomized subjects, set this to NO (any case works)
               TRT            => <Variable name>   name of treatment group variable in &SUBJLVLDS
               SUBJID         => <Variable name>   name of ID variable in &SUBJLVLDS (defaults to USUBJID)
               SUBJIDAE       => <Variable name>   name of ID variable in &ADAEDS (defaults to &SUBJID)
               SUBJIDRAND     => <Variable name>   name of ID variable in &RANDDS (defaults to &SUBJID)
               SERIOUS        => <Variable name>   name of SAE flag variable in &ADAEDS (defaults to AESER)
                                                   &SERIOUS should be a character variable that takes on values such as 'Yes' or 'N' (any case works)
               DEATH          => <Variable name>   name of death flag variable in &ADAEDS (defaults to AEDTH)
               PT             => <Variable name>   name of preferred term variable in &ADAEDS (defaults to AEPT)
               SOC            => <Variable name>   name of system organ class variable in &ADAEDS (defaults to AESOC)
               FREQTHRESH     => <Number>          frequency threshold for non SAEs (defaults to .05)
               SOURCEVOCAB    => <Number>          Source vocabulary 
               OUTPATH        => <Output Path>     complete path to the desired output folder (REQUIRED)
               
   DETAILS:    Searches through &SUBJLVLDS, identifying the treatment group to which each participant belongs.
               Counts the number of participants in each treatment group.
               Merges together subject-level and ADAE data to create a table of AE frequencies by &SERIOUS, &SOC, &PT, and &TRT.
               Outputs the dataset aefreq.sas7bdat, which contains the frequencies.

   NOTES:      Unless &RAND = no, only randomized subjects are considered.
               If the study's existing subject-level and/or AE datasets are not fit for use in this macro,
               a modified version can be made in the work directory. You may reference this modified dataset
               by setting &SUBJFLDR and/or &ADAEFLDR to WORK.

   PROGRAM HISTORY:

   Date        Programmer        Description
   ---------   ---------------   ----------------------------------------------------
   26MAY2016   Andrew Moseby     Adapted original from Maya Barton    
   06Sep2016   MB Herring        Remove DMReset code, which does not work on the grid.
   27SEP2016   Andrew Moseby     Now, subjects whose only non-SAEs were among those omitted by FREQTHRESH do not contribute to totals.
   03NOV2017   Andrew Moseby     Rename SUBJID variables to have SUBJID at the beginning of the name
   30MAR2018   Andrew Moseby     Fix bug in which 'Total AE' rows would sometimes be 0. 
                                 NOTE: Please make sure &serious has consistent case - use 'Yes' and 'No' instead of 'yes' and 'NO', for example.
   11SEP2018   Andrew Moseby     Fix bug in which the program looks for an undefined library when TRT = No and ADAEFLDR = Work
   27MAR2019   Andrew Moseby     Fix bug in which deaths are not split by treatment group
*-----------------------------------------------------------------------------------*/

%macro CT_Upload
   (SUBJLVLDS =               /* Name of subject-level dataset. Used for # of treatment groups, # of subjects in each treatment group. */
   ,SUBJFLDR =                /* Complete path to the folder where &SUBJLVLDS resides. 
                                 If &SUBJFLDR = work, the macro looks in the work directory for &SUBJLVLDS. */
   ,ADAEDS =                  /* Name of ADAE-equivalent dataset. */
   ,ADAEFLDR =                /* Complete path to the folder where &ADAEDS resides. 
                                 If &ADAEFLDR = work, the macro looks in the work directory for &ADAEDS. */
   ,RANDDS = &SUBJLVLDS       /* *Only define if you need a randomization variable that does not exist in &SUBJLVLDS* 
                                 Name of dataset which contains randomization variable. Default is &SUBJLVLDS. */
   ,RANDFLDR = &SUBJFLDR      /* *Only define if you need a randomization variable from a different folder than &SUBJFLDR* 
                                 Complete path to the folder where &RANDDS resides. Default is &SUBJFLDR. 
                                 If &RANDFLDR = work, the macro looks in the work directory for &RANDDS. */
   ,RAND = rand               /* Name of randomization variable. Default is RAND.
                                 &RAND should be a character variable that takes on positive values such as 'Yes', 'Y', '1', 'randomized' (any case works).
                                 If your AEs are to be subset to Safety population instead of Randomized, you may set &RAND to your safety flag variable (SAFETY or SAFFL, for example).
                                 If your study does not have randomized subjects, set this to NO (any case works). */
   ,TRT = trt                 /* Name of treatment group variable in &SUBJLVLDS. Default is TRT. 
                                 If there is no treatment group variable (i.e., the study has only one treatment arm), set this to NO (any case works). */
   ,SUBJID = usubjid          /* Name of ID variable in &SUBJLVLDS. Default is USUBJID. */
   ,SUBJIDAE = &SUBJID        /* Name of ID variable in &ADAEDS. Default is &SUBJID. */
   ,SUBJIDRAND = &SUBJID      /* Name of ID variable in &RANDDS. Default is &SUBJID. */
   ,SERIOUS = aeser           /* Name of SAE flag variable in &ADAEDS. Default is AESER.
                                 &SERIOUS should be the name of a character variable that takes on values such as 'Yes'/'No', 'Y'/'N', '1'/'0' (any case works). */
   ,DEATH = aedth             /* Name of death flag variable in &ADAEDS. Default is AEDTH. 
                                 &DEATH should be the name of a character variable that takes on positive values such as 'Yes', 'Y', '1' (any case works). */
   ,PT = aept                 /* Name of preferred term variable in &ADAEDS. Default is AEPT. */
   ,SOC = aesoc               /* Name of system organ class variable in &ADAEDS. Default is AESOC. */
   ,FREQTHRESH = .05          /* Frequency threshold for non SAEs - non SAEs occurring in a smaller proportion of subjects than &FreqThresh in every treatment group are not included in the output. Default is 5% (.05). */
   ,SOURCEVOCAB =             /* Source vocabulary, usually found in a coded AE dataset. (Sample value: MedDRA 13.1) */
   ,OUTPATH =                 /* Complete path to desired output folder */
   );


%*--------------------------------------------------;
%*------------ SETUP AND INITIALIZATION ------------;
%*--------------------------------------------------;

options symbolgen mlogic mprint;

%*Terminate processing if required macro variables are not defined correctly;
%*However, circumvent this check if the user indicates they want to use a dataset
   from the WORK directory by setting one of the folder variables to WORK;

%local fn fileref;
%if %sysevalf(%superq(SUBJLVLDS) = , boolean) = 1 %then 
   %do;
      %put %nrstr(%CT_Upload) => ERROR: Required argument SUBJLVLDS is not defined;
      %put %nrstr(%CT_Upload) => Execution terminated.;
      %goto ENDMAC;
   %end;

%if %sysevalf(%superq(ADAEDS) = , boolean) = 1 %then
   %do;
      %put %nrstr(%CT_Upload) => ERROR: Required argument ADAEDS is not defined;
      %put %nrstr(%CT_Upload) => Execution terminated.;
      %goto ENDMAC; 
   %end;

%let fn = %sysfunc(filename(fileref, &SUBJFLDR));
%if 
   (%sysevalf(%superq(SUBJFLDR) = , boolean) = 1 or /*&SUBJFLDR is missing*/
   %sysfunc(fexist(&fileref)) = 0) and /*&SUBJFLDR does not identify an existing folder*/
   %upcase("&SUBJFLDR") ^= "WORK" %then 
      %do;
         %put %nrstr(%CT_Upload) => ERROR: Required argument SUBJFLDR is not defined or does not identify an existing folder;
         %put %nrstr(%CT_Upload) => Execution terminated.;
         %goto ENDMAC;
      %end;

%let fn = %sysfunc(filename(fileref, &ADAEFLDR));
%if 
   (%sysevalf(%superq(ADAEFLDR) = , boolean) = 1 or /*ADAEFLDR is missing*/
   %sysfunc(fexist(&fileref)) = 0) and /*&ADAEFLDR does not identify an existing folder*/
   %upcase("&ADAEFLDR") ^= "WORK" %then
      %do;
         %put %nrstr(%CT_Upload) => ERROR: Required argument ADAEFLDR is not defined or does not identify an existing folder;
         %put %nrstr(%CT_Upload) => Execution terminated.;
         %goto ENDMAC;
      %end;

%let fn = %sysfunc(filename(fileref, &RANDFLDR));
%if 
   %sysfunc(fexist(&fileref)) = 0 and
   %upcase("&RANDFLDR") ^= "WORK" %then
      %do;
         %put %nrstr(%CT_Upload) => ERROR: Argument RANDFLDR does not identify an existing folder;
         %put %nrstr(%CT_Upload) => Execution terminated.;
         %goto ENDMAC;
      %end;

%if %sysevalf(%superq(SOURCEVOCAB) = , boolean) = 1 %then
   %do;
      %put %nrstr(%CT_Upload) => ERROR: Required argument SOURCEVOCAB is not defined;
      %put %nrstr(%CT_Upload) => Execution terminated.;
      %goto ENDMAC;
   %end;

%if %sysevalf(%superq(OUTPATH) = , boolean) = 1 %then
   %do;
      %put %nrstr(%CT_Upload) => ERROR: Required argument OUTPATH is not defined;
      %put %nrstr(%CT_Upload) => Execution terminated.;
      %goto ENDMAC;
   %end;

%*Check whether &SUBJFLDR, &ADAEFLDR, and &RANDFLDR resolve to WORK.;
%*If they do, a modified dataset must have been defined in the work directory.;
%*Create a macro variable to account for this, serving as the libname.;

%local SUBJDIR;
%if %upcase("&SUBJFLDR") = "WORK" %then
   %do;
      %*The directory we want to look in is the work directory. Set &SUBJDIR = work;
      %let SUBJDIR = work;
   %end;
%else
   %do;
      %*&SUBJFLDR is defined. Set &SUBJDIR = subjfldr;
      %let SUBJDIR = subjfldr;
      libname subjfldr "&SUBJFLDR";
   %end;

%local ADAEDIR;
%if %upcase("&ADAEFLDR") = "WORK" %then
   %do;
      %*The directory we want to look in is the work directory. Set &ADAEDIR = work;
      %let ADAEDIR = work;
   %end;
%else
   %do;
      %*&ADAEFLDR is defined. Set &ADAEDIR = adaefldr;
      %let ADAEDIR = adaefldr;
      libname adaefldr "&ADAEFLDR";
   %end;

%local RANDDIR;
%if %upcase("&RANDFLDR") = "WORK" %then
   %do;
      %*The directory we want to look in is the work directory. Set &RANDDIR = work;
      %let RANDDIR = work;
   %end;
%else
   %do;
      %*&RANDFLDR is defined. Set &RANDDIR = randfldr;
      %let RANDDIR = randfldr;
      libname randfldr "&RANDFLDR";
   %end;

%*-----------------------------------------------------------;
%*----- Getting subject counts for each treatment group -----;
%*-----------------------------------------------------------;
%*1. Put together subject-level data and randomization data;
%*2. Only use subjects who were randomized;
%*3. Find out what treatment groups there are;
%*4. Count how many subjects are in each treatment group;
%*-----------------------------------------------------------;

libname out "&OUTPATH";

proc sort data = &SUBJDIR..&SUBJLVLDS out = _subj nodupkey dupout = _subjdups; by &SUBJID; run;

%*Check for duplicates;
%local DUPCOUNT;
proc sql;
   select count(&SUBJID) into: DUPCOUNT from _subjdups;
quit;
%if %eval(&DUPCOUNT > 0) %then
   %do;
      %put %nrstr(%CT_Upload) => WARNING: Duplicate subjects encountered in dataset &SUBJLVLDS.;
      %put %nrstr(%CT_Upload) => Duplicates have been removed but remaining records may not be the most recent.;
      %put %nrstr(%CT_Upload) => Execution will continue.;
   %end; 

%if "&RANDDS" ^= "&SUBJLVLDS" or "&RANDFLDR" ^= "&SUBJFLDR" %then %do;
   proc sort data = &RANDDIR..&RANDDS out = _rand; by &SUBJIDRAND; run;
%end;

data _subjInfo;
   merge 
      _subj
      %if %sysfunc(exist(_rand)) %then %do; %*bring in randomization dataset if it exists*;
      _rand (rename = (&SUBJIDRAND = &SUBJID) keep = &SUBJIDRAND &RAND)
      %end;
      ;
   by &SUBJID;
   %if %upcase("&RAND") ^= "NO" %then %do; %*if the study has randomized subjects then*;
      if upcase(&RAND) in ('YES', 'Y', '1', 'RANDOMIZED'); %*only include subjects who have been randomized*;
   %end;
run;

proc sort data = _subjInfo; by &SUBJID; run;

%*-----   Get values of treatment variable   -----*;

%if %upcase("&Trt") ^= "NO" %then 
   %do;
      proc sort data = _subjInfo; by &Trt; run;
   %end;

data _null_;
   length trtvalues $1000;
   set _subjInfo end = eof;
   %if %upcase("&Trt") ^= "NO" %then %do; %*if there is more than one treatment arm then*;
      by &Trt; %*sort by treatment*;
      retain trtvalues;
      if first.&Trt then trtvalues = strip(trtvalues) || '\' || strip(&Trt); %*add the trt value to a list*;
      if substr(trtvalues,1,1) = '\' then trtvalues = substr(trtvalues, 2); %*remove the leading backslash*;
   %end;
   %else trtvalues = 'StudyTreatment'; %*in the case that there is only one treatment arm*;;
   if eof then call symputx('TrtValues', trtvalues); %*assign the list of treatments to a macro variable*;
run;

%local n_trt;
%if %sysfunc(find("&TrtValues", \)) >= 1 %then 
   %let n_trt = %sysfunc(countw("&TrtValues", '\'));
%else
   %let n_trt = %sysfunc(countw("&TrtValues")); %*count the number of trt groups*;

%local alphabet;
%let alphabet = A B C D E F G H I J K L M N O P Q R S T U V W X Y Z; %*for procedurally generating macro var names*;

%*-----   Put individual values of treatment variable into macro variables   -----*;

data _null_;
   %do i = 1 %to &n_trt;
      %if %sysfunc(find("&TrtValues", \)) >= 1 %then %do;
         call symput("TrtValue&i", scan("&TrtValues", &i, '\')); %end;
      %else %do;
         call symput("TrtValue&i", scan("&TrtValues", &i)); %end;

      call symput("ltr&i", scan("&alphabet", &i));
   %end;
run;

%*-----   Count up number of subjects in each treatment group   -----*;

proc sql;
%do i = 1 %to &n_trt;
   %if %sysfunc(upcase(&Trt)) ^= NO %then 
      %do;
         select count(distinct &SUBJID) into: tot&&ltr&i from _subjInfo where &trt = "&&TrtValue&i"; 
      %end;
   %else 
      %do;
         select count(distinct &SUBJID) into: tot&&ltr&i from _subjInfo; 
      %end;
   %let tot&&ltr&i = &&&&tot&&ltr&i; %put &&&&tot&&ltr&i;
%end;
quit;

%*-----------------------------------------------------------------;
%*------------ Set up AE data and count up frequencies ------------;
%*-----------------------------------------------------------------;
%*1. Merge subject-level data and AE data together if there are multiple treatment arms;
%*2. If only one treatment arm, no need to pull treatment info from _subjInfo;
%*3. Make counts of AEs by seriousness and treatment group if applicable;
%*4. Format and output the dataset;
%*-----------------------------------------------------------------;

proc sort data = _subjInfo; by &SUBJID; run;
proc sort data = &ADAEDIR..&ADAEDS out = _adae0; by &SUBJIDAE; run;

%if %sysfunc(upcase(&Trt)) ^= NO %then 
   %do; %*if there are multiple treatment arms then*;

      data _adae1;
         length ser1 $5;
         merge 
            _adae0(keep = &SUBJIDAE &SERIOUS &PT &SOC rename = (&SERIOUS=ser1) in = ae)
            _subjInfo(keep = &SUBJID &trt rename = (&SUBJID=&SUBJIDAE));
         by &SUBJIDAE;
         if ae;
         %do i = 1 %to &n_trt;
            if &trt = "&&TrtValue&i" then trtc = "&&ltr&i"; %*trtc eventually becomes a transpose ID variable*;
         %end;
      run;
   %end;
      
%else 
   %do; %*if there is only one treatment arm then;
      data _adae1;
         length ser1 $5;
         set _adae0(keep = &SUBJIDAE &SERIOUS &PT &SOC rename = (&SERIOUS=ser1));
         trtc = "&ltr1";
      run;
   %end;

%*-----   Count up AE frequencies   -----;

proc sql noprint;
   %*total*;
   create table _stat1 as
      select count(&SUBJIDAE) as event, count(distinct &SUBJIDAE) as subject, trtc, ser1
      from _adae1
      group by ser1, trtc;
   %*by system organ class and term;
   create table _stat2 as
      select count(&SUBJIDAE) as event, count(distinct &SUBJIDAE) as subject, trtc, &soc, &pt, ser1
      from _adae1
      group by ser1, &soc, &pt, trtc;
quit;

proc transpose data = _stat2 out = _check (drop = _name_);
   id trtc;
   by ser1 &soc &pt;
   var subject;
run;

proc sort data = _stat2; by ser1 &soc &pt; run;

data _check;
   length ser1 $5;
   set _check;
   %do i = 1 %to &n_trt;
      if &&ltr&i = . then &&ltr&i = 0;
   %end;
   %*Applying frequency threshold for non SAEs;
   if upcase(ser1) in ('NO', 'N', '0') 
   %do i = 1 %to &n_trt;
      and ((&&ltr&i / &&&&tot&&ltr&i) < &freqthresh)
   %end;
   then delete;
run;

%*use only ppts with at least one non-SAE which was not omitted by freqthresh;
%*we do not want them to contribute to totals;
proc sort data = _check; by ser1 &soc &pt; run;
proc sort data = _adae1; by ser1 &soc &pt; run;
data test;
   merge
      _check(in = keep)
      _adae1(in = ae)
      ;
   by ser1 &soc &pt;
   if keep and upcase(ser1) in ('NO' 'N' '0');
run;

proc sql;
   %do i = 1 %to &n_trt;
      select count(distinct &SUBJIDAE) into: non_s_tot&&ltr&i from test where trtc = "&&ltr&i";
      %let non_s_tot&&ltr&i = &&&&non_s_tot&&ltr&i;
   %end;
run;

%*Formatting data for text file;
data _outtext0;
   length ser1 $5;
   set _stat1 (in = tot) _stat2;
   where not(missing(trtc));
   if tot then 
     do;
        &soc = 'Total AE';
        &pt = 'Total AE';
     end ;
run;

%*Determine data formatting conventions for &serious so that new rows for totals can be made;
proc sql;
   select distinct &serious into: _servals separated by ' ' from _adae0 where not missing(&serious);
quit;

%*Creating place holders for zeros;
data _blanks;
   set _check end = eof;
   %do i = 1 %to &n_trt;
      trtc = "&&ltr&i";
      output;
   %end;
   if eof then
      do;
         %if &_servals = %str(No Yes) or &_servals = %str(Yes No) %then 
            %do;
               %do i = 1 %to &n_trt;
                  ser1 = 'No';
                  &soc = 'Total AE';
                  &pt  = 'Total AE';
                  trtc = "&&ltr&i";
                  output;
                  ser1 = 'Yes';
                  &soc = 'Total AE';
                  &pt  = 'Total AE';
                  trtc = "&&ltr&i";
                  output;
               %end;
            %end;
         %if &_servals = %str(no yes) or &_servals = %str(yes no) %then
            %do;
               %do i = 1 %to &n_trt;
                  ser1 = 'no';
                  &soc = 'Total AE';
                  &pt  = 'Total AE';
                  trtc = "&&ltr&i";
                  output;
                  ser1 = 'yes';
                  &soc = 'Total AE';
                  &pt  = 'Total AE';
                  trtc = "&&ltr&i";
                  output;
               %end;
            %end;
         %if &_servals = %str(NO YES) or &_servals = %str(YES NO) %then
            %do;
               %do i = 1 %to &n_trt;
                  ser1 = 'NO';
                  &soc = 'Total AE';
                  &pt  = 'Total AE';
                  trtc = "&&ltr&i";
                  output;
                  ser1 = 'YES';
                  &soc = 'Total AE';
                  &pt  = 'Total AE';
                  trtc = "&&ltr&i";
                  output;
               %end;
            %end;
         %if &_servals = %str(n y) or &_servals = %str(y n) %then
            %do;
               %do i = 1 %to &n_trt;
                  ser1 = 'n';
                  &soc = 'Total AE';
                  &pt  = 'Total AE';
                  trtc = "&&ltr&i";
                  output;
                  ser1 = 'y';
                  &soc = 'Total AE';
                  &pt  = 'Total AE';
                  trtc = "&&ltr&i";
                  output;
               %end;
            %end;
         %if &_servals = %str(N Y) or &_servals = %str(Y N) %then
            %do;
               %do i = 1 %to &n_trt;
                  ser1 = 'N';
                  &soc = 'Total AE';
                  &pt  = 'Total AE';
                  trtc = "&&ltr&i";
                  output;
                  ser1 = 'Y';
                  &soc = 'Total AE';
                  &pt  = 'Total AE';
                  trtc = "&&ltr&i";
                  output;
               %end;
            %end;
         %if &_servals = %str(0 1) or &_servals = %str(1 0) %then
            %do;
               %do i = 1 %to &n_trt;
                  ser1 = '0';
                  &soc = 'Total AE';
                  &pt  = 'Total AE';
                  trtc = "&&ltr&i";
                  output;
                  ser1 = '1';
                  &soc = 'Total AE';
                  &pt  = 'Total AE';
                  trtc = "&&ltr&i";
                  output;
               %end;
            %end;

      end ;
run;

proc sort data = _blanks; by &soc &pt ser1 trtc; run;

proc sort data = _outtext0; by &soc &pt ser1 trtc; run;

%*Formatting - 1 count per row;
data _outtext (rename = (&soc = OrganSystemName &pt = Term));
   length SAE $5 AssessmentType SourceVocabulary $25 &soc &pt $200 ReportingGroupID $50 cat_var $25 Counts $15;
   merge _outtext0(in = data) _blanks (in = keep);
   by &soc &pt ser1 trtc;
   if keep;

      if event = . then event = 0;
      if subject = . then subject = 0;

      if upcase(ser1) in ('NO', 'N', '0') then
         do; 
            sae = 'False';
         end;
      else 
         do;
            sae = 'True'; %*separate data by SAE or non SAE;
         end;

      %do i = 1 %to &n_trt;
         if trtc = "&&ltr&i" then ReportingGroupID = "ReportedEvents-InterventionGroup.&i";
      %end;

      AssessmentType = "Systematic Assessment";
      SourceVocabulary = "&SourceVocab";

      if &soc = 'Total AE' then 
         do;
            cat_var = 'numSubjectsEvents';
            if sae = 'False' then
               do;
                  %do i = 1 %to &n_trt;
                     if trtc = "&&ltr&i" then counts = "&&&&non_s_tot&&ltr&i";
                  %end;
               end ;
            if sae = 'True' then counts = strip(put(subject, 8.));
            sort = 1;
            output;

            cat_var = 'partAtRiskEvents';
            %do i = 1 %to &n_trt;
               if trtc = "&&ltr&i" then counts = "&&&&tot&&ltr&i";
            %end;
            sort = 2;
            output;
         end;
      else
         do;
            cat_var = 'numEvents';
            counts = strip(put(event, 8.));
            sort = 1;
            output;

            cat_var = 'numSubjectsAffected'; 
            counts = strip(put(subject, 8.));
            sort = 2;
            output;

            cat_var = 'numSubjects';
            %do i = 1 %to &n_trt;
               if trtc = "&&ltr&i" then counts = "&&&&tot&&ltr&i";
            %end;
            sort = 3;
            output;
         end ;
   keep sae AssessmentType sourcevocabulary &soc &pt reportinggroupid cat_var counts sort;
run;

proc sort data = _outtext; by sae OrganSystemName Term ReportingGroupID sort; run;

%*Counting up deaths;
proc sql;
   %do i = 1 %to &n_trt;
      select count(distinct &SUBJIDAE) into: death&i trimmed from &ADAEDIR..&ADAEDS where upcase(&DEATH) in ('YES' '1' 'Y') 
         %if %upcase(&TRT) ^= NO %then and &TRT = "&&TrtValue&i";;
   %end;
quit;

data _deaths;
   length counts $10;
   %do i = 1 %to &n_trt;
      sae = 'True';
      assessmenttype = 'Systematic Assessment';
      sourcevocabulary = "&SOURCEVOCAB";
      organsystemname = 'All-Cause Mortality';
      term = 'All-Cause Mortality';
      reportinggroupid = "ReportedEvents-InterventionGroup.&i";
      cat_var = 'numSubjectsEvents';
      counts = strip("&&death&i");
      output;
      cat_var = 'partAtRiskEvents';
      counts = strip("&&&&tot&&ltr&i");
      output;
   %end;
run;

data _outtext;
   set _outtext _deaths;
run;

%*Outputting copy of dataset;
data out.aefreq; set _outtext; drop sort; run;

%*Outputting an XML file;
/*
filename schema 'S:\RhoFED\NIAID\DAIT\General\DataSharing\ClinicalTrials.gov\Development\AEMacro\AESchema.xml';

ods markup 
   body = 'S:\RhoFED\NIAID\DAIT\General\DataSharing\ClinicalTrials.gov\Development\AEMacro\Output\aefreq.xml'
   stylesheet = schema;

proc print data = out.aefreq; by sae organsystemname term reportinggroupid; run;

ods markup close;
*/
%ENDMAC:;

%mend;
