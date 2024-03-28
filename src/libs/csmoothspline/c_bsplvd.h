#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MIN0(a,b) (((a)<(b))?(a):(b))
#define MAX0(a,b) (((a)>(b))?(a):(b))

void  c_bsplvb(double *t, int jhigh, int index, 
		double x, int left, double *biatx, int *j, 
		double *deltal, double *deltar);

void c_bsplvd( double *t, 
	      int k, double x, int left, double *a, double *dbiatx, int nderiv ){


   double factor,fkp1mm,sum; 
   int i,ideriv,il,j,jlow,jp1mid, kp1,kp1mm,ldummy,m,mhigh;
   int jj; 
   double deltal[20], deltar[20];

   jj = 1;

      mhigh = MAX0( MIN0(nderiv,k), 1);

//     mhigh is usually equal to nderiv.
      kp1 = k + 1;

      c_bsplvb(t, kp1 - mhigh, 1, x, left, dbiatx, &jj, deltal, deltar);

      if (mhigh == 1) return;

/*
c     the first column of  dbiatx  always contains the b-spline values
c     for the current order. these are stored in column k+1-current
c     order  before  bsplvb  is called to put values for the next
c     higher order on top of it.
*/
      ideriv = mhigh;

      for ( m = 2; m <= mhigh; m++){

         jp1mid = 1;
         for ( j = ideriv; j <= k; j++){
            dbiatx[ j -1 + (ideriv-1) * k ] = dbiatx[ jp1mid - 1 ];
            jp1mid = jp1mid + 1;
         }

         ideriv = ideriv - 1;
         c_bsplvb( t, kp1-ideriv, 2, x, left, dbiatx, &jj, deltal, deltar);

      }
/*
c
c     at this point,  b(left-k+i, k+1-j)(x) is in  dbiatx(i,j) for
c     i=j,...,k and j=1,...,mhigh ('=' nderiv). in particular, the
c     first column of  dbiatx  is already in final form. to obtain cor-
c     responding derivatives of b-splines in subsequent columns, gene-
c     rate their b-repr. by differencing, then evaluate at  x.
c
*/
      jlow = 1;
      for ( i = 0; i < k * k; i++) a[i] = 0.0;
      for ( i = 0; i < k; i++) a[ i * (k + 1) ] = 1.0;

/*
c     at this point, a(.,j) contains the b-coeffs for the j-th of the
c     k  b-splines of interest here.
c
*/
      for ( m = 2; m <= mhigh; m++){

         kp1mm = kp1 - m;
         fkp1mm = 1.0 * kp1mm; 
         il = left;
         i = k;
/*
c
c        for j=1,...,k, construct b-coeffs of  (m-1)st  derivative of
c        b-splines from those for preceding derivative by differencing
c        and store again in  a(.,j) . the fact that  a(i,j) = 0  for
c        i < j  is used.sed.
*/

         for ( ldummy = 1; ldummy <= kp1mm; ldummy++){

            factor = fkp1mm / ( t[ il + kp1mm -1 ] - t[ il -1 ] );
/*
c           the assumption that t(left) < t(left+1) makes denominator
c           in  factor  nonzero.
*/
            for ( j = 1; j <= i; j++) a[ i + ( j-1 ) * k - 1] = 
                    ( a[i + ( j-1 ) * k - 1] - a[i + ( j-1 ) * k - 2] ) * factor;

            il = il - 1;
            i = i - 1;
         }

/*
c
c        for i=1,...,k, combine b-coeffs a(.,i) with b-spline values
c        stored in dbiatx(.,m) to get value of  (m-1)st  derivative of
c        i-th b-spline (of interest here) at  x , and store in
c        dbiatx(i,m). storage of this value over the value of a b-spline
c        of order m there is safe since the remaining b-spline derivat-
c        ive of the same order do not use this value due to the fact
c        that  a(j,i) = 0  for j < i .
*/
         for ( i = 1; i <= k; i++){

            sum = 0.0;
            jlow = MAX0(i, m);

            for (j = jlow; j <= k; j++) sum = a[ j + (i - 1) * k -1 ] * dbiatx[ j + (m - 1) * k -1] + sum; 

            dbiatx[ i + (m - 1) * k -1] = sum;

         } // end of i-loop
      } // end of m-llo

      return;
}

/*
c     --------   ------
c      implicit none

C calculates value and deriv.s of all b-splines which do not vanish at x
C calls bsplvb
c
c******  i n p u t  ******
c  t     the knot array, of length left+k (at least)
c  k     the order of the b-splines to be evaluated
c  x     the point at which these values are sought
c  left  an integer indicating the left endpoint of the interval of
c        interest. the  k  b-splines whose support contains the interval
c               (t(left), t(left+1))
c        are to be considered.
c  a s s u m p t i o n  - - -  it is assumed that
c               t(left) < t(left+1)
c        division by zero will result otherwise (in  b s p l v b ).
c        also, the output is as advertised only if
c               t(left) <= x <= t(left+1) .
c  nderiv   an integer indicating that values of b-splines and their
c        derivatives up to but not including the  nderiv-th  are asked
c        for. ( nderiv  is replaced internally by the integer in (1,k)
c        closest to it.)
c
c******  w o r k   a r e a  ******
c  a     an array of order (k,k), to contain b-coeff.s of the derivat-
c        ives of a certain order of the  k  b-splines of interest.
c
c******  o u t p u t  ******
c  dbiatx   an array of order (k,nderiv). its entry  (i,m)  contains
c        value of  (m-1)st  derivative of  (left-k+i)-th  b-spline of
c        order  k  for knot sequence  t , i=m,...,k; m=1,...,nderiv.
c
c******  m e t h o d  ******
c  values at  x  of all the relevant b-splines of order k,k-1,...,
c  k+1-nderiv  are generated via  bsplvb  and stored temporarily
c  in  dbiatx .  then, the b-coeffs of the required derivatives of the
c  b-splines of interest are generated by differencing, each from the
c  preceding one of lower order, and combined with the values of b-
c  splines of corresponding order in  dbiatx  to produce the desired
c  values.

C Args
      integer lent,k,left,nderiv
      double precision t(lent),x, dbiatx(k,nderiv), a(k,k)
C Locals
      double precision factor,fkp1mm,sum
      integer i,ideriv,il,j,jlow,jp1mid, kp1,kp1mm,ldummy,m,mhigh

      integer jmax
      parameter(jmax = 20)
      integer jj
      double precision deltal(jmax), deltar(jmax)

      external c_bsplvb
*/

