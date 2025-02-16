/* Agresti, A.  1990.  Categorical Data Analysis.
 * John Wiley & Sons: New York.  558pp.
 * Example pp. 87 - 89.
 */
data cda88;
  infile "cda88.dat" firstobs=2;
  input labind ncases nremiss;

proc dap;
nport(plotlogreg("cda88", "nremiss/ncases", "labind",
                 "== MAXX40 NXTICKS5 MAXY1 NYTICKS6 NYDIGITS2 NXDIGITS1",
                 5, "", 1, 0.95), 4, 4);
