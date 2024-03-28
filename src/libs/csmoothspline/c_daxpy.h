#include <stdio.h>
#include <math.h>
#include <stdlib.h>


void c_daxpy( int n, double da, double *dx,double *dy){

//     .. Local Scalars ..
   int i, m, mp1;


   if ( n <= 0) return;
   if ( da == 0.0 ) return;

   m = n % 4;

   if ( m != 0 ){
      for (i = 0; i < m; i++) dy[i] = dy[i] + da * dx[i];
   }

   if (n < 4) return;

   mp1 = m;

   for ( i = mp1; i < n; i +=4 ){
      dy[i] = dy[i] + da * dx[i];
      dy[i+1] = dy[i+1] + da * dx[i+1];
      dy[i+2] = dy[i+2] + da * dx[i+2];
      dy[i+3] = dy[i+3] + da * dx[i+3];
   }

   return;
}
