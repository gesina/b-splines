
/* ************************************************ */
/*                                                  */
/*   FILE: spline_de_boor_points.c                  */
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
/*   AUTHORS:                                       */
/*   *************                                  */
/*     Kerstin Blomenhofer and Gesina Schwalbe      */
/*     Group 30                                     */
/*                                                  */
/* ************************************************ */



//---------------------------------------------------
//
//  Computing of the de Boor Points c_i for a spline
//     s(x) = \sum_{i=1}^{N} c_i*N_{i,4}(x)
//  with given values in [x_0, x_n]
//
//---------------------------------------------------


#include <stdlib.h>   // malloc()

#include "spline_de_boor_points.h"
#include "lrband.h"
#include "subsband.h"

#include "spline_eval_b-splines.h"



// de Boor Points
/*  arguments:
    - array with lattice points x_i and values f_i
    - array for c_i values to return 
*/

int set_de_boor_points(double** values, int n, double* de_boor)
{
  // b-spline (nx3)-matrix
  double** A = (double**) malloc(n*sizeof(double*));
  for(int i=0; i<n; i++){
    A[i]= (double*) malloc(3*sizeof(double));
    if( !A[i] ){return 1;}
  }
  
  // copy of function values
  //  double* f = (double*) malloc(n*sizeof(double));
  for(int i=0; i<n; i++){ de_boor[i]=values[1][i]; }

  // evaluated in x_j, N_{j,4}=0, so only the last
  // three entries of the return values of eval_b_splines()
  // are needed
  double temp_N[] = {0,0,0,0};
  // evaluate at x_i and write A
  for(int j=0; j<n; j++)
    {
      eval_b_splines(values[0][j], j, values[0], temp_N);  // evaluation at x_j
      A[j][0]=temp_N[1]; A[j][1]=temp_N[2]; A[j][2]=temp_N[3];
    }


  // solve Ac = f and write c into de_boor
  if(LRBand(n, BANDWIDTH, A)){return 2;}
  vwsubsband(n, BANDWIDTH, A, de_boor);
  rwsubsband(n, BANDWIDTH, A, de_boor);
  //  for(int i=0; i<n; i++){ de_boor[i]=f[i]; }


  for(int i=0; i<n; i++){free(A[i]);}
  free(A);
  //  free(f);
    
  
  return 0;
}

// ERROR CODES:
//  0: exited normally
//  1: allociation error
//  2: lr failed
