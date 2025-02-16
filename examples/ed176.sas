/* ED pp. 176 using SBS and proc dap
 * Without covariate, with contrasts
 */

data muscle;
 infile "ed176.dat" dlm="\t" firstobs=3;
 length rep $ 1 time $ 1 current $ 1 number $ 1;
 input rep time current number y;

proc glm;
 class rep current time number;
 model y=rep current time number current*time current*number time*number current*time*number;
 contrast "curr 1 vs curr 2" current 1 -1;

/* To construct the constrast for testing "time in current 3",
 * we have to modify the muscle.srt.mns.con file produced by glm.
 */
proc dap;
{ /* start with brace to enclose everything */
  title("Testing time within level 3 of current");
  inset("muscle.srt.mns.con")
   {
     char rep[2], current[2], time[2];
     double y;
     char _type_[9]; /* N, MEAN, VAR, ERROR, CONTR, LSMEAN */
     int _term_; /* specifies term to which contrast applies */
     int more; /* to control stepping through dataset */
     double c1[4], c2[4], c3[4]; /* contrast with 3 df */
     outset("muscle.con", ""); /* datast for the F-test */
     /* set up the contrast coefficients */
     c1[0] = 1; c1[1] = 0; c1[2] = 0; c1[3] = -1;
     c2[0] = 0; c2[1] = 1; c2[2] = 0; c2[3] = -1;
     c3[0] = 0; c3[1] = 0; c3[2] = 1; c3[3] = -1;
     for (more = step(); more; )
      {
	output(); /* N, MEAN, VAR */
	step();
        output();
	step();
        output();
	for (step(); strcmp(_type_, "CONTR"); step()) /* get to CONTR lines */
          output();
	_term_ = 4; /* bits: 1 is rep, 2 is current, 4 is time */
        if (!strcmp(current, "3")) /* only in current 3 */
         {
           y = c1[time[0] - '1']; /* convert time to index */
           output();
           y = c2[time[0] - '1'];
           output();
           y = c3[time[0] - '1'];
           output();
         }
        else
         {
           y = 0.0;
           output();
           output();
           output();
         }
        while (more && !strcmp(_type_, "CONTR")) /* look for the ones we want */
           more = step();
	while (more && !strcmp(_type_, "LSMEAN")) /* get to next cell or end */
         {
           output();
           more = step();
         }
      }
   }
  /* muscle.con only has time in numerator so don't need to specify it */
  ftest("muscle.con", "y rep current time number", "", "", "");
}
