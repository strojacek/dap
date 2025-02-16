/* CDA pp. 232 - 233 using SBS */

data;
 infile "cda233.dat" firstobs=2;
 length penicillin $ 5 delay $ 4 response $ 5;
 input penicillin delay response count;

proc freq;
 tables penicillin * delay * response / norow nocol nopercent cmh;
 weight count;

