/* Rao, C.R. and Toutenberg, H. 1995 using SBS
 * Linear Models: Least Squares and Alternatives
 * Springer-Verlag: New York. 352 pp.
 * Example pp. 50 - 60.
 */
data;
  infile "lm50.dat" firstobs=2;
  input y x1 x2 x3 x4;

proc corr;
 var x1 x2 x3 x4 y;
 title "Correlations";

proc reg;
 model y = x4;
 title "Model building";

proc reg;
 model y = x4;
 add x1;

proc reg;
 model y = x4 x1;
 add x3;

proc reg;
 model y = x4 x1 x3;
 add x2;
