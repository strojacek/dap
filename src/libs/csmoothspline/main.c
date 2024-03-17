#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#include <string.h>

int sbart
    (double *xs, double *ys, double *ws, 
     int n, double *knot, int nk, double *coef,
     double *sz, 
     double spar, int ispar, double *lspar,
     int *isetup,
     double *xwy, double *hs0, double *hs1, double *hs2,
     double *hs3, double *sg0, double *sg1, double *sg2,
     double *sg3, double *abd, int ld4); 



double  c_bvalue( double *t, double *bcoef, int n, int k, double x, int jderiv);

int nknots( int n);

int main (int argc, char **argv){

	double penalty, dotoff;
	double *xs, *ys, *ws;
	double spar;
	int n, nk;
	double *knot,*coef;
	double *sz;
	double *lev, crit;
	int icrit, ispar, iter, isetup;
	double lspar, uspar;
	double tol, eps;
	double *xwy;
	double *hs0, *hs1, *hs2, *hs3;
	double *sg0, *sg1, *sg2, *sg3;
	double *abd, *p1ip, *p2ip;
	int ld4, ldnk, ier;

	// local variables:
	int i, j;
	double weight_sum;
	int pos_weights = 0;
	double rux, xorigin;
	double y_predict ;
	char *token;
	char line[256];
	FILE *fin;
	int iw;

	// Initialize input arguments
	isetup = 0;
	penalty = 1.0;
	n = 1825; //365*14; //21;
	tol = 1e-04;
	eps = 2e-08;
	lspar = -1.5;
	uspar = 1.5;
	//nk = n + 2;
	spar = 0.35;
	ispar = 1;
	icrit = 0;
	dotoff = 0.0;
	crit = 1.0;
	iter = 500;
	ld4 = 4;
	ldnk = 1;
	ier = 1;


	xs = (double *) malloc ( n * sizeof(double) );
	ys = (double *) malloc ( n * sizeof(double) );
	ws = (double *) malloc ( n * sizeof(double) );
	sz = (double *) malloc ( n * sizeof(double) );
	lev = (double *) malloc ( n * sizeof(double) );


	/*
	for ( i = 0; i < n; i++ ){
		xs[i] = i * 1.0;
		ys[i] = cos(xs[i]/100.);
		ws[i] = 0.75;
		//sz[i] = 1.0;
	}
	*/

	fin = fopen("pixel.out","r");
	for ( i = 0; i < n; i++ ){
		fgets(line, sizeof line , fin);
		token = strtok( line, ",");
		for ( j = 1; j < 8; j++ ){
			token = strtok(NULL,",");
			if ( j == 4 ) xs[i] = atoi(token);
			if ( j == 5 ) ys[i] = atoi(token);
			if ( j == 7 ){
				iw = atoi(token);
				switch(iw){
				case 0:
					ws[i] = 1.0;
					break;
				
				case 1:
					ws[i] = 0.9;
					break;
				
				case 2:
					ws[i] = 0.6;
					break;
				case 3:
					ws[i] = 0.5;
					break;
				
				default:
					ws[i] = 0.0;
					break;
				
				
				}
				if (ys[i] == 32767) ws[i] = 0;
			}
		}
		//printf(" %f %f %d %f\n", xs[i], ys[i], iw, ws[i]);	
	}
	fclose(fin);

	// Normilize weights
	weight_sum = 0;
	pos_weights = 0;
	//pos_weights++;
	for ( i = 0; i < n; i++ ) {
		weight_sum += ws[i];
		if ( ws[i] > 0.1 ) { printf("%d\n",i+1); pos_weights++;}
	}
	printf("weighted_sum = %f pos_weight=%d\n", weight_sum, pos_weights);

	// Prepare input values
	rux = xs[n-1] - xs[0];
	xorigin = xs[0];
	for ( i = 0; i < n; i++ ) {
		ws[i] = ws[i] * pos_weights / weight_sum;
		//printf("weights %d %f\n", i, ws[i]);
		xs[i] = (xs[i] - xorigin) / rux;

		if (ws[i] <= 0) ys[i] = ws[i] * ys[i]; 
	}

        nk = nknots ( n );
	knot = (double *) malloc ( (nk+6) * sizeof(double) );
	for ( i = 0; i < 3; i++ ) knot[i] = xs[0];
	for ( i = 0; i < nk -1; i++ ) knot[i+3] = xs[ (int)( i * (n - 1) / ( nk - 1 ) ) ];
        knot[nk+2] = xs[n-1];
	for ( i = 0; i < 3; i++ ) knot[i+nk+3] = xs[n-1];
        nk = nk + 2;
	  	
	//allocate space for scratch arrays
	coef = (double *) malloc ( (nk) * sizeof(double) );

	xwy = (double *) malloc ( nk * sizeof(double) );
	hs0 = (double *) malloc ( nk * sizeof(double) );
	hs1 = (double *) malloc ( nk * sizeof(double) );
	hs2 = (double *) malloc ( nk * sizeof(double) );
	hs3 = (double *) malloc ( nk * sizeof(double) );
	sg0 = (double *) malloc ( nk * sizeof(double) );
	sg1 = (double *) malloc ( nk * sizeof(double) );
	sg2 = (double *) malloc ( nk * sizeof(double) );
	sg3 = (double *) malloc ( nk * sizeof(double) );
	abd = (double *) malloc ( ld4*nk * sizeof(double) );
	p1ip = (double *) malloc ( ld4*nk * sizeof(double) );
	p2ip = (double *) malloc ( ldnk*nk * sizeof(double) );
	printf(" Before calling sbart penalty=%f, n = %d, spar=%f\n", penalty, n, spar);

	// main function
	ier = sbart ( xs, ys, ws, 
		n, knot, nk, coef, sz,
		spar, ispar, &lspar, &isetup,
		xwy, hs0, hs1, hs2, hs3, sg0, sg1, sg2, sg3, abd, 
		ld4);

	printf(" Done with sbart ier=%d\n", ier);


	printf(" Running predict\n");

	for (i = 0; i < n; i++){
	   y_predict = c_bvalue(knot, coef, nk,4 , xs[i], 0);
	   printf (" %d, %f %f %f %f %f \n", i+1, xs[i], ys[i], ws[i], y_predict, sz[i]);
	}
	printf("\n");


	// cleanup
	free(xs);
	free(ys);
	free(ws);
	free(knot);
	free(coef);
	free(sz);
	free(lev);
	free(xwy);
	free(hs0);
	free(hs1);
	free(hs2);
	free(hs3);
	free(sg0);
	free(sg1);
	free(sg2);
	free(sg3);
	free(abd);
	free(p1ip);
	free(p2ip);


	return(0);
}
	
