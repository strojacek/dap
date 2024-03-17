#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MIN0(a,b) (((a)<(b))?(a):(b))
#define MAX0(a,b) (((a)>(b))?(a):(b))

double c_ddot( int n, double *dx, double *dy);
void c_daxpy( int n, double da, double *dx,double *dy);

void c_dpbsl( double *abd, int lda, int n, int m, double *b){

//     internal variables
      double t;
      int k, kb, la, lb, lm;
/*
c     solve trans(r)*y = b
*/
   for (k = 0; k < n; k++){

         lm = MIN0( k, m);
         t = c_ddot(lm, abd + m - lm + k * lda, b + k - lm   );
         b[k] = ( b[k] - t) / abd[ m + k * lda];

   }

/*
c     solve r*x = y
*/
   for ( kb = 0; kb < n; kb++){

         k = n - kb -1;

         lm = MIN0(k, m);
         la = m + 1 - lm;
         lb = k - lm;

        b[k] = b[k] / abd[ m + k * lda];
         t = -b[k];


         c_daxpy( lm, t, abd + (la - 1 + k * lda) , b + lb );



   }

   return;
}

/*
      integer lda,n,m
      double precision abd(lda,n),b(n)
c
c     dpbsl solves the double precision symmetric positive definite
c     band system  a*x = b
c     using the factors computed by dpbco or dpbfa.
c
c     on entry
c
c        abd     double precision(lda, n)
c                the output from dpbco or dpbfa.
c
c        lda     integer
c                the leading dimension of the array  abd .
c
c        n       integer
c                the order of the matrix  a .
c
c        m       integer
c                the number of diagonals above the main diagonal.
c
c        b       double precision(n)
c                the right hand side vector.
c
c     on return
c
c        b       the solution vector  x .
c
c     error condition
c
c        a division by zero will occur if the input factor contains
c        a zero on the diagonal.  technically this indicates
c        singularity but it is usually caused by improper subroutine
c        arguments.  it will not occur if the subroutines are called
c        correctly and  info .eq. 0 .
c
c     to compute  inverse(a) * c  where  c  is a matrix
c     with  p  columns
c           call dpbco(abd,lda,n,rcond,z,info)
c           if (rcond is too small .or. info .ne. 0) go to ...
c           do 10 j = 1, p
c              call dpbsl(abd,lda,n,c(1,j))
c        10 continue
c
c     linpack.  this version dated 08/14/78 .
c     cleve moler, university of new mexico, argonne national lab.
c
c     subroutines and functions
c
c     blas daxpy,ddot
c     fortran min0
c
c     internal variables
c
      double precision ddot,t
      integer k,kb,la,lb,lm
*/
