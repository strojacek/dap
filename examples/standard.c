/* Using plotmeans to plot means, both as symbols
 * and joined by lines, and 95% confidence intervals
 * of two groups of data together.
 */
#include <dap.h>

void main()
{
infile("standard.dat", " ")
  {
    int part;
    double x, y;

    input("x y part");
    outset("mtest", "");
    while (step())
      output();
  }

title("Means of y\nError bars are 95% confidence for means");
  {
    pict *p;

    sort("mtest", "part x", "");
    p = plotmeans("mtest.srt", "y", "x", "SEM 1.96", "==", "part", 2);
/* p[0] and p[1] are error bars and means as points for group 1 */
    strcpy(p[1].pict_type, "TRIA");
/* p[2] and p[3] are error bars and means as points for group 2 */
    strcpy(p[3].pict_type, "SQUA");

    nport(p, 4, 4);
  }
}
