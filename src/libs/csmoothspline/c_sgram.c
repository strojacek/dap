#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int newFindInterval(double *xt, int n, double x,
		  int rightmost_closed,  int all_inside, int ilo,
		  int *mflag);

void c_bsplvd( double *t, 
	      int k, double x, int left, double *a, double *dbiatx, int nderiv );


void c_sgram( double * sg0, double *sg1, double *sg2, double *sg3, double *tb, int nb){ 

/*
C PURPOSE
C       Calculation of the cubic B-spline smoothness prior
C       for "usual" interior knot setup.
C       Uses BSPVD and INTRV in the CMLIB
C       sgm[0-3](nb)    Symmetric matrix
C                       whose (i,j)'th element contains the integral of
C                       B''(i,.) B''(j,.) , i=1,2 ... nb and j=i,...nb.
C                       Only the upper four diagonals are computed.
*/

   int ileft, mflag, i, ii, jj, lentb;
   double vnikx[12], work[16], yw1[4], yw2[4], wpt;

   lentb = nb + 4;

// Initialise the sigma vectors
    for ( i = 0; i < nb; i++) {
         sg0[i] = 0.0;
         sg1[i] = 0.0;
         sg2[i] = 0.0;
         sg3[i] = 0.0;
   }

   ileft = 1;

   for ( i = 1; i <= nb; i++ ){

//     Calculate a linear approximation to the
//     second derivative of the non-zero B-splines
//     over the interval [tb(i),tb(i+1)].

//    ileft = interv(tb(1), nb+1,tb(i), 0,0, ileft, mflag);
      ileft = newFindInterval(tb, nb + 1, tb [i - 1], 0, 0, ileft, &mflag);


//    Left end second derivatives
      c_bsplvd ( tb, 4, tb[i - 1], ileft, work, vnikx, 3);

//    Put values into yw1
      for ( ii = 0; ii < 4; ii++) yw1[ii] = vnikx[ii + 2 * 4];


//    Right end second derivatives
      c_bsplvd ( tb, 4, tb[i], ileft, work, vnikx, 3);


//    Slope*(length of interval) in Linear Approximation to B''
      for ( ii = 0; ii < 4; ii++) yw2[ii] = vnikx[ii + 2 * 4] - yw1[ii];

      wpt = tb[i] - tb[i-1];
//    Calculate Contributions to the sigma vectors

      switch (ileft) {

      case 1:

         ii = 0;
         jj = ii;
         sg0[ ileft - 1 + ii ]  = sg0[ ileft - 1 + ii ] +
                                  wpt * ( yw1[ii] * yw1[ jj ] +
                                ( yw2[ii] * yw1[jj] + yw2[jj] * yw1[ii] ) * 0.5 + 
                                  yw2[ii] * yw2[jj] * 0.3330 );



         break;

      case 2:

         for ( ii = 0; ii < 2; ii++ ){
            jj = ii;
            sg0[ileft - 2 + ii] = sg0[ ileft - 2 + ii ] +
                                  wpt * (yw1[ii] * yw1[jj] +
                                ( yw2[ii] * yw1[jj] + yw2[jj] * yw1[ii] ) * 0.5 + 
                                  yw2[ii] * yw2[jj] * 0.3330 );
            jj = ii + 1;
            if( jj < 2 ) { 
                  sg1[ileft + ii - 2] = sg1[ileft + ii - 2] +
                                        wpt * (yw1[ii]*yw1[jj] +
                                      ( yw2[ii] * yw1[jj] + yw2[jj] * yw1[ii] ) * 0.5 + 
                                        yw2[ii] * yw2[jj] * 0.333 );
            }
         }


         break;

      case 3:

         for ( ii = 0; ii < 3; ii++ ){
            jj = ii;
            sg0[ileft - 3 + ii] = sg0[ ileft - 3 + ii ] +
                                  wpt * (yw1[ii] * yw1[jj] +
                                ( yw2[ii] * yw1[jj] + yw2[jj] * yw1[ii] ) * 0.5 + 
                                  yw2[ii] * yw2[jj] * 0.3330 );
            jj = ii + 1;
            if( jj < 3 ) { 
                  sg1[ileft + ii - 3] = sg1[ileft + ii - 3] +
                                        wpt * (yw1[ii]*yw1[jj] +
                                      ( yw2[ii] * yw1[jj] + yw2[jj] * yw1[ii] ) * 0.5 + 
                                        yw2[ii] * yw2[jj] * 0.333 );
            }
            jj = ii + 2;
            if( jj < 3 ) { 
                  sg2[ileft + ii - 3] = sg2[ileft + ii - 3] +
                                        wpt * (yw1[ii]*yw1[jj] +
                                      ( yw2[ii] * yw1[jj] + yw2[jj] * yw1[ii] ) * 0.5 + 
                                        yw2[ii] * yw2[jj] * 0.333 );
            }
         }


         break;


      default:

         for ( ii = 0; ii < 4; ii++ ){
            jj = ii;
            sg0[ileft - 4 + ii] = sg0[ ileft - 4 + ii ] +
                                  wpt * (yw1[ii] * yw1[jj] +
                                ( yw2[ii] * yw1[jj] + yw2[jj] * yw1[ii] ) * 0.5 + 
                                  yw2[ii] * yw2[jj] * 0.3330 );
            jj = ii + 1;
            if( jj < 4 ) { 
                  sg1[ileft + ii - 4] = sg1[ileft + ii - 4] +
                                        wpt * (yw1[ii]*yw1[jj] +
                                      ( yw2[ii] * yw1[jj] + yw2[jj] * yw1[ii] ) * 0.5 + 
                                        yw2[ii] * yw2[jj] * 0.333 );
            }
            jj = ii + 2;
            if( jj < 4 ) { 
                  sg2[ileft + ii - 4] = sg2[ileft + ii - 4] +
                                        wpt * (yw1[ii]*yw1[jj] +
                                      ( yw2[ii] * yw1[jj] + yw2[jj] * yw1[ii] ) * 0.5 + 
                                        yw2[ii] * yw2[jj] * 0.333 );
            }
            jj = ii + 3;
            if( jj < 4 ) { 
                  sg3[ileft + ii - 4] = sg3[ileft + ii - 4] +
                                        wpt * (yw1[ii]*yw1[jj] +
                                      ( yw2[ii] * yw1[jj] + yw2[jj] * yw1[ii] ) * 0.5 + 
                                        yw2[ii] * yw2[jj] * 0.333 );
            }
         }


         break;

      } // end of switch


   } // end of i - loop 
   return;
}
