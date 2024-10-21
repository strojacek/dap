/* This example illustrates the construction
 * of custom graphics.  We create two distributions
 * and display them as a split histogram: the bars
 * of one distribution extend horizontally to the
 * left and the bars of the other extend
 * horizontally to the right and are shaded.
 */
#include <dap.h>

#define NBARS 10

void main()
{
 /* these variables are not in the datasets */
double min, max;  /* extremes of both
                   * distributions together
                   */
double width;     /* width of the bars */

infile("custom.dat", " ")
  {
    double x;
    int part;

    input("x part");
    outset("split", "");
    while (step())
      output();
  }
means("split", "x", "MIN MAX", ""); /* find min, max */
inset("split.mns")
  {
    double x;
    int n;
    char _type_[9];

    for (n = 0; n < 2; n++)
      {
        step();             /* and store them */
        if (!strcmp(_type_, "MIN"))
          min = x;
        else
          max = x;
      }
  }

width = (max - min) / ((double) NBARS);

inset("split")      /* compute class for each x */
  {
    double x;
    int class;

    outset("class", "x class part");
    while (step())
      {
        class = (int) floor((x - min) / width);
        if (class < 0)
          class = 0;
        else if (class > NBARS - 1)
          class = NBARS - 1;
        output();
      }
  }

sort("class", "part class", "");
/* compute counts in each class for each distribution */
means("class.srt", "count", "N", "part class");

  {
  pict p[21];  /* one pict for each class for each part
                * plus one for the axes
                */
  int pn;

  pict_initpict(NULL, p);  /* initialize the pict structs */
  for (pn = 1; pn < 21; pn++)
    pict_initpict(p + pn - 1, p + pn);

  inset("class.srt.mns")
    {
      int part, class;
      double classmin, count;

      while (step())
        {
          classmin = min + width * ((double) class);
          /* make a rectangle */
          pict_rectangle(p + NBARS * part + class,
              0.0, classmin, (part ? count : -count), width);
          /* shade the ones on the right */
          if (part)
            p[NBARS * part + class].pict_fgray = 0.8;
        }
    }
  /* set up the axes */
  pict_autoaxes(p, "Count", "X", "==", &fabs, NULL,
                          "Split histogram", 1);
  /* and make it all appear */
  pict_port(1);
  pict_page();
  pict_show(p);
  pict_end();
  }
}
