/* CDA pp. 49 - 50 using SBS */

data;
 infile "cda50.dat" firstobs=2;
 length income $ 5 jobsat $ 10;
 input income jobsat count;

proc freq;
 tables income * jobsat / measures chisq expected
                          norow nocol nopercent;
 weight count;
