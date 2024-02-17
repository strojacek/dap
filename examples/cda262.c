#include <dap.h>

double expect(double param[8], double class[2]);

void main()
{
  infile("cda262.dat", " ")
    {
      char Income[6], JobSat[10];
      double income, jobsat, count;
      input("Income JobSat count");
      outset("cda262", "");
      skip(1);
      while (step())
	{
	  /* we have to convert to double for categ */
          if (!strcmp(Income, "<6"))
	    income = 0.0;
          else if (!strcmp(Income, "6-15"))
	    income = 1.0;
          else if (!strcmp(Income, "15-25"))
	    income = 2.0;
          else if (!strcmp(Income, ">25"))
	    income = 3.0;
	  if (!strcmp(JobSat, "VeryDis"))
	    jobsat = 0.0;
	  else if (!strcmp(JobSat, "LittleDis"))
	    jobsat = 1.0;
	  else if (!strcmp(JobSat, "ModSat"))
	    jobsat = 2.0;
	  else if (!strcmp(JobSat, "VerySat"))
	    jobsat = 3.0;
	  output();
	}
    }

  {
    double param[8];
    int p;

    param[0] = 1.0;
    for (p = 1; p < 8; p++)
      param[p] = 0.0;
    categ("cda262", "count income jobsat", "", &expect, param,
	  "mu <6 6-15 15-25 VeryDis LittleDis ModSat ?Inc*Sat", "", "");
    sort("cda262.cat", "income _type_ jobsat", "");
    table("cda262.cat.srt", "income", "_type_ jobsat count", "6.2", "");
  }
}

/* We use an independent subset of the parameters in order to
   * incorporate the zero-sum constraints. Thus, if class[0] == 3,
   * for example, then we use the fact that lambda^{income}_{>25} is
   * minus the sum of the other lambda^{income} parameters.
   */
double expect(double param[8], double class[2])
{
  double lx, ly;

  if (class[0] < 3.0)
    lx = param[1 + (int) class[0]];
  else
    lx = -(param[1] + param[2] + param[3]);
  if (class[1] < 3.0)
    ly = param[4 + (int) class[1]];
  else
    ly = -(param[4] + param[5] + param[6]);
  return exp(param[0] + lx + ly + param[7] * class[0] * class[1]);
}
