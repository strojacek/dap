#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*
C Purpose :
C       Compute smoothing spline for smoothing parameter lambda
C       and compute one of three `criteria' (OCV , GCV , "df match").
C See comments in ./sbart.c from which this is called
*/

void c_sinerp( double *abd,int ld4, int nk, double *p1ip, double *p2ip, int ldnk, int flag);
double  c_bvalue( double *t, double *bcoef, int n, int k, double x, int jderiv);
int newFindInterval(double *xt, int n, double x, int rightmost_closed,  int all_inside, int ilo, int *mflag);
int c_dpbfa( double *abd, int lda, int n, int m);
void c_dpbsl( double *abd, int lda, int n, int m, double *b);


int c_sslvrg( double *x, 
              int n, double *knot, int nk, double *coef,
              double *sz, double lambda, 
              double *xwy, 
			  double *hs0, double *hs1, double *hs2, double *hs3,  
              double *sg0, double *sg1, double *sg2, double *sg3,  double *abd,
              int ld4 ){


   int info;

// local variables
   int i, ileft, lenkno;
   double eps, xv;

   lenkno = nk + 4;
   ileft = 1;
   eps = 1e-11;

// compute the coefficients coef() of estimated smooth
   for ( i = 0; i < nk; i++){
         coef[i] = xwy[i];
         abd[ 3 + i * ld4 ] = hs0[i] + lambda * sg0[i];
   }

   for ( i = 0; i < nk - 1; i++) abd[ 2 + (i+1) * ld4 ] = hs1[i] + lambda * sg1[i];
   for ( i = 0; i < nk - 2; i++) abd[ 1 + (i+2) * ld4 ] = hs2[i] + lambda * sg2[i];
   for ( i = 0; i < nk - 3; i++) abd[ 0 + (i+3) * ld4 ] = hs3[i] + lambda * sg3[i];

// factorize banded matrix abd:
   info = c_dpbfa( abd, ld4, nk, 3);
   if(info != 0) return(info);

// solve linear system (from factorize abd):
   c_dpbsl(abd, ld4, nk, 3, coef);

// Value of smooth at the data points
   for ( i = 0; i < n; i++){
      xv = x[i];
      sz[i] = c_bvalue(knot, coef, nk, 4, xv, 0);
   }
 
   return(info);
}
