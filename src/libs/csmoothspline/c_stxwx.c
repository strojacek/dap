#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int newFindInterval(double *xt, int n, double x,
		  int rightmost_closed,  int all_inside, int ilo,
		  int *mflag);

void c_bsplvd( double *t, 
	      int k, double x, int left, double *a, double *dbiatx, int nderiv );


void c_stxwx( double *x, double *z, double *w, int k, double *xknot, int n, double *y,
            double *hs0, double *hs1, double *hs2,double *hs3){


//      integer k,n
//      DOUBLE precision x(k),z(k),w(k), xknot(n+4),y(n),
//     &     hs0(n),hs1(n),hs2(n),hs3(n)

// local
   double eps, vnikx[4], work[16], wsqr;
   int lenxk, i, j, ileft, mflag, ipar1, ipar2;

   lenxk = n + 4;
// Initialise the output vectors

   for ( i = 0; i < n; i++){

         y[i] = 0.0;
         hs0[i] = 0.0;
         hs1[i] = 0.0;
         hs2[i] = 0.0;
         hs3[i] = 0.0;
   }

// Compute X' W^2 X -> hs0,hs1,hs2,hs3  and X' W^2 Z -> y
// Note that here the weights w(i) == sqrt(wt[i])  where wt[] where original weights

   ileft = 1;
   eps = 1.0e-9; // is it 0.1d-9 ?
   ipar1 = 0;
   ipar2 = 0;

   for ( i = 0; i < k; i++){

      //ileft= interv(xknot(1), n+1, x(i), ipar1,ipar2, ileft, mflag)
      ileft = newFindInterval(xknot, n + 1, x[i], ipar1, ipar2, ileft, &mflag);

      if(mflag == 1){ 
         if(x[i] <= ( xknot[ileft-1] + eps) ){
            ileft = ileft - 1;
         } else {
            return;
         }
      }
//         call bsplvd (xknot,lenxk,4,x(i),ileft,work,vnikx,1)
      c_bsplvd ( xknot, 4, x[i], ileft, work, vnikx, 1);

      wsqr = w[i] * w[i];
      j = ileft - 4;
      y[j] = y[j] + wsqr * z[i] * vnikx[0];
      hs0[j] = hs0[j] + wsqr * vnikx[0] * vnikx[0];
      hs1[j] = hs1[j] + wsqr * vnikx[0] * vnikx[1];
      hs2[j] = hs2[j] + wsqr * vnikx[0] * vnikx[2];
      hs3[j] = hs3[j] + wsqr * vnikx[0] * vnikx[3];

      j = ileft - 4 + 1;
      y[j] = y[j] + wsqr * z[i] * vnikx[1];
      hs0[j] = hs0[j] + wsqr * vnikx[1] * vnikx[1];
      hs1[j] = hs1[j] + wsqr * vnikx[1] * vnikx[2];
      hs2[j] = hs2[j] + wsqr * vnikx[1] * vnikx[3];

      j = ileft - 4 + 2;
      y[j] = y[j] + wsqr * z[i] * vnikx[2];
      hs0[j] = hs0[j] + wsqr * vnikx[2] * vnikx[2];
      hs1[j] = hs1[j] + wsqr * vnikx[2] * vnikx[3];

      j = ileft - 4 + 3;
      y[j] = y[j] + wsqr * z[i] * vnikx[3];
      hs0[j] = hs0[j] + wsqr * vnikx[3] * vnikx[3];

   }

   return;
}
