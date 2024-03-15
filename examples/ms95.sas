data;
  infile "ms95.dat" firstobs=2;
  input soilphos plantphos;
run;

proc reg;
 model plantphos = soilphos;
 plot phantphos * soilphos;
run;
