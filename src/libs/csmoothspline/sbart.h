#include <stdio.h>
#include <math.h>
#include <stdlib.h>


/*
 * `sbart` and associated functions for fitting spline
 */
void c_sgram(double *sg0, double *sg1, double *sg2, double *sg3,
             double *tb, int nb);
void c_stxwx(double *x, double *z, double *w, int k, double *xknot, int n, double *y,
             double *hs0, double *hs1, double *hs2,double *hs3);

int c_sslvrg(double *x, int n, double *knot, int nk, double *coef,
             double *sz, double lambda, double *xwy,
             double *hs0, double *hs1, double *hs2, double *hs3,
             double *sg0, double *sg1, double *sg2, double *sg3,
             double *abd, int ld4);

int sbart(double *xs, double *ys, double *ws,
          int n, double *knot, int nk, double *coef,
          double *sz,
          double spar, int ispar, double *lspar,
          int *isetup,
          double *xwy, double *hs0, double *hs1, double *hs2,
          double *hs3, double *sg0, double *sg1, double *sg2,
          double *sg3, double *abd, int ld4);


/*
 * `c_bvalue` for spline prediction
 */
double c_bvalue(double *t, double *bcoef, int n, int k, double x, int jderiv);
