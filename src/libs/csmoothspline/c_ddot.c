#include <stdio.h>
#include <math.h>
#include <stdlib.h>


double c_ddot( int n, double *dx, double *dy){


      double dtemp;
      int i, m, mp1;

      dtemp = 0.0;

      if ( n <= 0 ) return(dtemp);
 
      m = n % 5;

      if ( m != 0 ) {
            for ( i = 0; i < m; i++) dtemp = dtemp + dx[i] * dy[i];
            
            if ( n < 5 ) return(dtemp);
      }

      mp1 = m + 1;

      for (i = mp1-1; i < n; i=i+5){
          dtemp += dx[i]*dy[i] + dx[i+1]*dy[i+1] + 
     +     dx[i+2]*dy[i+2] + dx[i+3]*dy[i+3] + dx[i+4]*dy[i+4];
      }
      
      return(dtemp);
}
