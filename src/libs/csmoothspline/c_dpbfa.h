#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MIN0(a,b) (((a)<(b))?(a):(b))
#define MAX0(a,b) (((a)>(b))?(a):(b))


double c_ddot( int n, double *dx, double *dy);

int c_dpbfa( double *abd, int lda, int n, int m){


//     internal variables

   double t, s;
   int ik, j, jk, k, mu;

   for ( j = 1; j <= n; j++ ){

      s = 0.0;

       ik = m + 1;
       jk = MAX0( j - m, 1 );
       mu = MAX0( m + 2 - j, 1 );

       if ( m >= mu ) {
            for ( k = mu; k <= m; k++){

               t = abd[ k -1 + (j -1) * lda ] - 
                   c_ddot( k - mu, abd + ( ik - 1 + ( jk - 1 ) * lda) ,
                                   abd + ( mu - 1 + ( j - 1 ) * lda) );
               t = t / abd[ m + ( jk - 1 ) * lda ];
               abd[ k - 1 + ( j - 1 ) * lda] = t;
               s = s + t * t;
               ik = ik - 1;
               jk = jk + 1;
         }
      }

      s = abd[ m + ( j - 1 ) * lda] - s;

      if ( s <= 0.0 ) return ( j );

      abd[ m + ( j - 1 ) * lda ] = pow(s ,0.5 );

   }

   return (0);
}


/*
      integer lda,n,m,info
      double precision abd(lda,n)
c
c     dpbfa factors a double precision symmetric positive definite
c     matrix stored in band form.
c
c     dpbfa is usually called by dpbco, but it can be called
c     directly with a saving in time if  rcond  is not needed.
c
c     on entry
c
c        abd     double precision(lda, n)
c                the matrix to be factored.  the columns of the upper
c                triangle are stored in the columns of abd and the
c                diagonals of the upper triangle are stored in the
c                rows of abd .  see the comments below for details.
c
c        lda     integer
c                the leading dimension of the array  abd .
c                lda must be .ge. m + 1 .
c
c        n       integer
c                the order of the matrix  a .
c
c        m       integer
c                the number of diagonals above the main diagonal.
c                0 .le. m .lt. n .
c
c     on return
c
c        abd     an upper triangular matrix  r , stored in band
c                form, so that  a = trans(r)*r .
c
c        info    integer
c                = 0  for normal return.
c                = k  if the leading minor of order  k  is not
c                     positive definite.
c
c     band storage
c
c           if  a  is a symmetric positive definite band matrix,
c           the following program segment will set up the input.
c
c                   m = (band width above diagonal)
c                   do 20 j = 1, n
c                      i1 = max0(1, j-m)
c                      do 10 i = i1, j
c                         k = i-j+m+1
c                         abd(k,j) = a(i,j)
c                10    continue
c                20 continue
c
c     linpack.  this version dated 08/14/78 .
c     cleve moler, university of new mexico, argonne national lab.
c
c     subroutines and functions
c
c     blas ddot
c     fortran max0,sqrt
c
c     internal variables
c
      double precision ddot,t
      double precision s
      integer ik,j,jk,k,mu
c     begin block with ...exits to 40
*/
