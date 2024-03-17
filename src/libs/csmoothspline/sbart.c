/* sbart.f -- translated by f2c (version 20010821).
 * ------- and f2c-clean,v 1.9 2000/01/13
 *
 * According to the GAMFIT sources, this was derived from code by
 * Finbarr O'Sullivan.
 */

/* sbart() : The cubic spline smoother
   -------
 Calls	 sgram	(sg0,sg1,sg2,sg3,knot,nk)
	 stxwx	(xs,ys,ws,n,knot,nk,xwy,hs0,hs1,hs2,hs3)
	 sslvrg (dofoff,xs,ys,ws,ssw,n,knot,nk,	coef,sz,lev,
		 lambda, xwy, hs0,hs1,hs2,hs3, sg0,sg1,sg2,sg3,
		 abd,p1ip,p2ip,ld4,ldnk,ier)

 is itself called from	 qsbart() [./qsbart.f]	 which has only one work array
*/

#include "sbart.h"


int sbart
    (double *xs, double *ys, double *ws, 
     int n, double *knot, int nk, double *coef,
     double *sz, 
     double spar, int ispar, double *lspar,
     int *isetup,
     double *xwy, double *hs0, double *hs1, double *hs2,
     double *hs3, double *sg0, double *sg1, double *sg2,
     double *sg3, double *abd, int ld4) {

/* A Cubic B-spline Smoothing routine.

   The algorithm minimises:

	(1/n) * sum ws(i)^2 * (ys(i)-sz(i))^2 + lambda* int ( s"(x) )^2 dx

   lambda is a function of the spar which is assumed to be between 0 and 1

 INPUT
 -----
   n		number of data points
   ys(n)	vector of length n containing the observations
   ws(n)	vector containing the weights given to each data point
		NB: the code alters the values here.
   xs(n)	vector containing the ordinates of the observations
   ssw          `centered weighted sum of y^2'
   nk		number of b-spline coefficients to be estimated
		nk <= n+2
   knot(nk+4)	vector of knot points defining the cubic b-spline basis.
		To obtain full cubic smoothing splines one might
		have (provided the xs-values are strictly increasing)
   spar		penalised likelihood smoothing parameter
   ispar	indicating if spar is supplied (ispar=1) or to be estimated
   isetup	setup indicator [initially 0]
   NB: this alters that, and it is a constant in the caller!
   ld4		the leading dimension of abd (ie ld4=4)

 OUTPUT
 ------
   coef(nk)	vector of spline coefficients
   sz(n)	vector of smoothed z-values
   spar         if ispar != 1
   lspar         == lambda (a function of spar and the design)
   ier		error indicator
		ier = 0 ___  everything fine
		ier = 1 ___  spar too small or too big
			problem in cholesky decomposition

 Working arrays/matrix
   xwy			X'Wy
   sg0,sg1,sg2,sg3	the diagonals of the Gram matrix SIGMA
   abd (ld4,nk)		[ X'WX + lambda*SIGMA ] in diagonal form
*/

    /* Local variables */
    double ratio;/* must be static (not needed in R) */

    double d, u;
    double fu;
    double t1, t2;

    int i, ier;


    /* unnecessary initializations to keep  -Wall happy */
    d = 0.; fu = 0.; u = 0.;
    ratio = 1.;
    ier = -1;

/*  Compute SIGMA, X' W X, X' W z, trace ratio, s0, s1.

	SIGMA	-> sg0,sg1,sg2,sg3
	X' W X	-> hs0,hs1,hs2,hs3
	X' W Z	-> xwy
*/



/* trevor fixed this 4/19/88
 * Note: sbart, i.e. stxwx() and sslvrg() {mostly, not always!}, use
 *	 the square of the weights; the following rectifies that */
    for (i = 0; i < n; ++i) if (ws[i] > 0.) ws[i] = sqrt(ws[i]);


    if ( *isetup == 0) {
	   /* SIGMA[i,j] := Int  B''(i,t) B''(j,t) dt  {B(k,.) = k-th B-spline} */

	   c_sgram(sg0, sg1, sg2, sg3, knot, nk);


	   c_stxwx(xs, ys, ws, n,
			knot, nk,
			xwy,
			hs0, hs1, hs2, hs3);



	   /* Compute ratio :=  tr(X' W X) / tr(SIGMA) */
	   t1 = t2 = 0.;
	   for (i = 3 - 1; i < (nk - 3); ++i) {
	       t1 += hs0[i];
	       t2 += sg0[i];
	   }
	   ratio = t1 / t2;
	   *isetup = 1;
    }
/*     Compute estimate */


    if ( ispar == 1) { /* Value of spar supplied */

	   *lspar = ratio * pow(16., spar * 6. - 2.);
	   ier = c_sslvrg( xs, n, knot, nk,
			 coef, sz, *lspar, xwy,
			 hs0, hs1, hs2, hs3,  
			 sg0, sg1, sg2, sg3, abd, ld4);

    }
    return (ier);
  
} /* sbart */
