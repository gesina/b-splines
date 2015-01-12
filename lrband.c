
/* ************************************************ */
/*                                                  */
/*   FILE: lrband.c                                 */
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
//  LU Decomposition of band matrices
//
//---------------------------------------------------


#include <math.h>
#include <stdio.h>

#include"lrband.h"

// LU Decomposition of band matrix A (without Pivoting)
/*  arguments:
    - dimension (number of rows) n
    - bandwidth l
    - matrix A
    return: decomposed matrix in A, still band matrix
*/
int LRBand(int n,int l,double* *A) {
  static double prec=1.0e-8;
  for(int i=0; i<n; i++) {
    if(fabs(A[i][l])<prec) {
      printf("The Diagonal-Element %20.16e is too small.\n",A[i][l]);
      printf("%2d. step of LR-Decomp. not executed.\n",i+1);
      return 1;
    }
    int max_row=fmin(i+l+1,n);
    for(int j=i+1; j<max_row; j++) {
      A[j][i+l-j]=A[j][i+l-j]/A[i][l];
    }
    for(int j=i+1; j<max_row; j++) {
      for(int k=i+1; k<max_row; k++)
	{
	  A[k][j+l-k] -= A[k][i+l-k]*A[i][j+l-i];
	}
    }
  }
	
  return 0;
}
