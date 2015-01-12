
/* ************************************************ */
/*                                                  */
/*   FILE: subsband.c                               */
/*                                                  */
/*   PROJECT:                                       */
/*   *************                                  */
/*    B-SPLINES                                     */
/*                                                  */
/*   Excercise #55 for the lecture                  */
/*   NUMERICAL MATHEMATICS in 2014/15               */
/*   by Prof. Dr. Blank                             */
/*   University of Regensburg                       */
/*                                                  */
/*   SOURCE:                                        */
/*   *************                                  */
/*     Material for exercise #55 on                 */
/*     https://elearning.uni-regensburg.de/         */
/*     course Numerik I, WS14/15                    */
/*                                                  */
/* ************************************************ */


//---------------------------------------------------
//
//  Forward and backward substitution
//   for band matrices
//
//---------------------------------------------------

#include <math.h>
#include <stdio.h>

#include"subsband.h"


// forward substitution, solves Lx=b
/*  arguments:
     - dimension (number of rows) n
     - bandwidth l
     - matrix L (only elements underneath diagonal used)
    return: substituted vector in b
 */
int vwsubsband(int n, int l, double** L, double* b) {
	double subs;
	for(int i=0; i<n; i++) {
		subs=0.0;
		for(int j=fmax(i-l,0); j<i; j++) {
			subs=subs+L[i][j-i+l] *b[j];
		}
		b[i]=(b[i]-subs);
	}
	return 0;
}

// backward substitution, solves Rx=b
/*  arguments:
     - dimension (number of rows) n
     - bandwidth l
     - matrix R (elements underneath diagonal not used)
    return: resulting vector x in b
 */
int rwsubsband(int n, int l, double** R, double* b) {
	double subs;
	for(int i=n-1; i>=0; i--) {
		subs=0.0;
		for(int j=i+1; j<fmin(n,i+l+1); j++) {
			subs=subs+R[i][j-i+l] *b[j];
		}
		b[i]=(b[i]-subs)/R[i][l];
	}
	return 0;
}
