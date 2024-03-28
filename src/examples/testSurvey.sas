/*%let  PATH = C:\Users\Sebastien\Desktop\Presidentielles2007SAS\; 
libname  lib  "&PATH" ;*/
PROC IMPORT  out = tPres2007 datafile =  "Pres2007Clustered.csv"  dbms  = csv
delimiter = ',' replace ;  
run ;


proc sort data=tPres2007;
 by Strate ;

proc means data=tPres2007 N MEAN VAR ;
 var PctBAYR;
 by Strate;
 output out=tPres2007.mns;

 proc freq;
     tables PctBAYR * Strate / measures chisq expected
                               norow nocol nopercent;

/* echantillonage Sas sur 220  echantillons */   
proc surveyselect   data =tPres2007 method=SRS  n = 220  reps= 50  seed= 1213   out=sasPres2007 stats;  
run ;

proc means data=sasPres2007 N MEAN VAR ;
  var PctBAYR;
  by Strate;
  output out=tPres2007sas.mns;

proc surveyselect   data =tPres2007 method=SYS  n = 220  reps= 50  seed= 1213
out=sysPres2007 stats;
run ;


proc means data=sysPres2007 N MEAN VAR ;
  var PctBAYR;
  by Strate;
  output out=tPres2007sys.mns;

