#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define kmax 20

int newFindInterval(double *xt, int n, double x,
		  int rightmost_closed,  int all_inside, int ilo,
		  int *mflag);

double  c_bvalue( double *t, double *bcoef, int n, int k, double x, int jderiv) {

/*
c      integer n,k, jderiv
c      DOUBLE precision t(*),bcoef(n),x
c     dimension t(n+k)
*/

   double aj[kmax], dm[kmax], dp[kmax];
   int i, ilo, imk, j, jc, jcmin, jcmax;
   int jj, km1, kmj, mflag, nmi, jdrvp1;
   int rightmost_closed, all_inside;

   i = 1;
   rightmost_closed = 0;
   all_inside = 0;

   if (jderiv >= k) return (0.0);

   if( ( x != t[n] ) || (t[n] != t[n+k-1] ) ){

         i = newFindInterval ( t, n + k, x, rightmost_closed, all_inside, i, &mflag);

         if (mflag != 0) return (0.0);

    } else {
	
         i = n;
   }

//  *** if k = 1 (and jderiv = 0), bvalue = bcoef(i).

   km1 = k - 1;
   if (km1 <= 0) return( bcoef[i-1] );

/*
c  *** store the k b-spline coefficients relevant for the knot interval
c     (t(i),t(i+1)) in aj(1),...,aj(k) and compute dm(j) = x - t(i+1-j),
c     dp(j) = t(i+j) - x, j=1,...,k-1 . set any of the aj not obtainable
c     from input to zero. set any t.s not obtainable equal to t(1) or
c     to t(n+k) appropriately.
*/

   jcmin = 1;
   imk = i - k;

   if (imk >= 0){
      for ( j = 0; j < km1; j++) dm[j] = x - t[ i - j - 1 ];

   } else {

         jcmin = 1 - imk;
         for ( j = 0; j < i; j++) dm[j] = x - t[ i - j -1 ];

         for ( j = i; j <= km1; j++) {
            aj[k-j-1] = 0.0;
            dm[j-1] = dm[i-1];
         }
   }

   jcmax = k;
   nmi = n - i;

   if (nmi >= 0) {
      for ( j = 0; j < km1; j++) dp[j] = t[i + j] - x;

   } else {

      jcmax = k + nmi;

      for ( j = 0; j < jcmax; j++) dp[j] = t[ i + j ] - x;

      for ( j = jcmax; j <= km1; j++) {
            aj[j] = 0.0;
            dp[j - 1] = dp[jcmax-1];
      }

   }

   for ( jc = jcmin; jc <= jcmax; jc++)  aj[jc-1] = bcoef[imk + jc - 1];

//   *** difference the coefficients  jderiv  times.
/* Katia: looks like jderiv = 0 in our case
   if (jderiv >= 1) {
         do 23 j=1,jderiv
            kmj = k-j
            fkmj = dble(kmj)
            ilo = kmj
            do 24 jj=1,kmj
               aj(jj) = ((aj(jj+1) - aj(jj))/(dm(ilo) + dp(jj)))*fkmj
               ilo = ilo - 1
 24         continue
 23      continue
   }
*/

/*
c  *** compute value at  x  in (t(i),t(i+1)) of jderiv-th derivative,
c     given its relevant b-spline coeffs in aj(1),...,aj(k-jderiv).
*/
   if (jderiv != km1) {
         jdrvp1 = jderiv + 1;

      for (j = jdrvp1; j <= km1; j++ ){

         kmj = k - j;
         ilo = kmj;

         for ( jj = 0; jj < kmj; jj++ ){
               aj[jj] = ( aj[jj+1] * dm[ilo-1] + aj[jj] * dp[jj] ) / ( dm[ilo-1] + dp[jj] );
               ilo = ilo - 1;
         }
      }

   }

   return (aj[0]);
}

/*
c Calculates value at  x  of  jderiv-th derivative of spline from B-repr.
c The spline is taken to be continuous from the right.
c
C calls  interv
c
c******  i n p u t ******
c  t, bcoef, n, k......forms the b-representation of the spline  f  to
c        be evaluated. specifically,
c  t.....knot sequence, of length  n+k, assumed nondecreasing.
c  bcoef.....b-coefficient sequence, of length  n .
c  n.....length of  bcoef  and dimension of s(k,t),
c        a s s u m e d  positive .
c  k.....order of the spline .
c
c  w a r n i n g . . .   the restriction  k <= kmax (=20)  is imposed
c        arbitrarily by the dimension statement for  aj, dm, dm  below,
c        but is  n o w h e r e  c h e c k e d  for.
c  however in R, this is only called from bvalus() with k=4 anyway!
c
c  x.....the point at which to evaluate .
c  jderiv.....integer giving the order of the derivative to be evaluated
c        a s s u m e d  to be zero or positive.
c
c******  o u t p u t  ******
c  bvalue.....the value of the (jderiv)-th derivative of  f  at  x .
c
c******  m e t h o d  ******
c     the nontrivial knot interval  (t(i),t(i+1))  containing  x  is lo-
c  cated with the aid of  interv(). the  k  b-coeffs of  f  relevant for
c  this interval are then obtained from  bcoef (or taken to be zero if
c  not explicitly available) and are then differenced  jderiv  times to
c  obtain the b-coeffs of  (d^jderiv)f  relevant for that interval.
c  precisely, with  j = jderiv, we have from x.(12) of the text that
c
c     (d^j)f  =  sum ( bcoef(.,j)*b(.,k-j,t) )
c
c  where
c                   / bcoef(.),                     ,  j .eq. 0
c                   /
c    bcoef(.,j)  =  / bcoef(.,j-1) - bcoef(.-1,j-1)
c                   / ----------------------------- ,  j > 0
c                   /    (t(.+k-j) - t(.))/(k-j)
c
c     then, we use repeatedly the fact that
c
c    sum ( a(.)*b(.,m,t)(x) )  =  sum ( a(.,x)*b(.,m-1,t)(x) )
c  with
c                 (x - t(.))*a(.) + (t(.+m-1) - x)*a(.-1)
c    a(.,x)  =    ---------------------------------------
c                 (x - t(.))      + (t(.+m-1) - x)
c
c  to write  (d^j)f(x)  eventually as a linear combination of b-splines
c  of order  1 , and the coefficient for  b(i,1,t)(x)  must then
c  be the desired number  (d^j)f(x). (see x.(17)-(19) of text).
c
C Arguments
      integer n,k, jderiv
      DOUBLE precision t(*),bcoef(n),x
c     dimension t(n+k)
c  current fortran standard makes it impossible to specify the length of
c  t  precisely without the introduction of otherwise superfluous
c  additional arguments.

*/
