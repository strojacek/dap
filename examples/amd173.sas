/* AMD pp. 173 - 177:
 * missing treatment combinations
 */
data amd173;
 infile "amd173.dat" firstobs=2;
 length treat $ 2 block $ 2;
 input treat block y;

proc sort data=amd173;
 by treat block;

proc means data=amd173 N MEAN VAR noprint;
 var y;
 by treat block;
 output out=amd173.mns;

/* Now we have to create "by hand" the .con files for
 * the custom F-tests for the contrasts that are meaningful
 * in the presence of empty cells.
 */
/* The first F-test (p. 175-76) is the interaction:
 * m11 - m13 - m21 + m23 = 0 and m21 - m22 - m31 + m32 = 0
 */
proc dap;
{ /* start with a brace to enclose everything here */
  title("Test Ho:\nu11 - u21 - (u13 - u23) = 0\nu21 - u31 - (u22 - u32) = 0");
  inset("amd173.mns") /* file from model statement */
   {
     char treat[3], block[3]; /* we're in C here! */
     double y;
     char _type_[9]; /* set this to CONTR */
     int _term_;     /* bits specify the effect */
     double c1[7], c2[7]; /* coeffs of the contrasts */
     int c; /* cell number */
     outset("amd173.mns.con", "treat block y _term_");
     /* cells, in sort order, are:
     /*   11       13       21       22      23       31      32 */
     c1[0]=1;c1[1]=-1;c1[2]=-1;c1[3]= 0;c1[4]=1;c1[5]= 0;c1[6]=0;
     c2[0]=0;c2[1]= 0;c2[2]= 1;c2[3]=-1;c2[4]=0;c2[5]=-1;c2[6]=1;
     _term_ = 3; /* bit 1 for treat, bit 2 for block */
     for (c = 0; step(); c++) /* while there's another cell */
      {
	output(); /* N, MEAN, VAR */
        step();
	output();
        step();
	output();
        strcpy(_type_, "CONTR");
        y = c1[c];
        output();
        y = c2[c];
        output();
      }
   }
  ftest("amd173.mns.con", "y treat block", "treat*block", "", "");

/* The second F-test (p. 176-77) is the treat effect:
 * m11 + m13 - m21 - m23 = 0 and m21 + m22 - m31 - m32 = 0
 */
  title("Test Ho:\nu11 + u13 - (u21 + u23) = 0\nu21 + u22 - (u31 + u32) = 0");
  inset("amd173.mns") /* file from model statement */
   {
     char treat[3], block[3]; /* we're in C here! */
     double y;
     char _type_[9]; /* set this to CONTR */
     int _term_;     /* bits specify the effect */
     double c1[7], c2[7]; /* coeffs of the contrasts */
     int c; /* cell number */
     outset("amd173.mns.con", "treat block y _term_");
     /* cells, in sort order, are:
     /*   11      13       21      22       23       31      32 */
     c1[0]=1;c1[1]=1;c1[2]=-1;c1[3]=0;c1[4]=-1;c1[5]= 0;c1[6]= 0;
     c2[0]=0;c2[1]=0;c2[2]= 1;c2[3]=1;c2[4]= 0;c2[5]=-1;c2[6]=-1;
     _term_ = 1; /* bit 1 for treat */
     for (c = 0; step(); c++) /* while there's another cell */
      {
	output(); /* N, MEAN, VAR */
        step();
	output();
        step();
	output();
        strcpy(_type_, "CONTR");
        y = c1[c];
        output();
        y = c2[c];
        output();
      }
   }
  ftest("amd173.mns.con", "y treat block", "treat", "", "");
}
