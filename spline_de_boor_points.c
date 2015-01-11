
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
    - array with points t_i and values f_{i-3}
    - number of lattice points x_i in [-1;1]
    - array for c_i values to return 
*/
int set_de_boor_points(double** values, int N, double* de_boor)
{
  printf(" N : %i\n", N);
  // b-spline (nx3)-matrix
  double** A = (double**) malloc(N*sizeof(double*));
  for(int i=0; i<N; i++){
    A[i]= (double*) malloc(3*sizeof(double));
    if( !A[i] ){return 1;}
  }
  
  // copy function values f_i into de_boor (shifted one point)
  for(int i=3; i<N+4; i++){ de_boor[i-2]=values[1][i]; }
  de_boor[0]=values[1][3];

  // evaluated in x_j, N_{j,4}=0, so only the last
  // three entries of the return values of eval_b_splines()
  // are needed
  double temp_N[] = {0,0,0,0};
  // evaluate at x_i and write A
  for(int j=1; j<N-1; j++)
    {
      // evaluation at x_j=t_{j+3} (t_i starting with 0)
      eval_b_splines(values[0][j+3], j+3, values[0], temp_N);
      A[j][0]=temp_N[0]; A[j][1]=temp_N[1]; A[j][2]=temp_N[2];
    }
  // A[0][1]= (x_1+x_2-2x_0)/(x_2-x_0)
  A[0][1]= (values[0][4]+values[0][5]-2*values[0][3])    \
    /(values[0][5]-values[0][3]);
  // A[0][2]= -(x_1-x_0)/(x_2-x_0)
  A[0][2]= -(values[0][4]-values[0][3])    \
    /(values[0][5]-values[0][2]);
  // A[n-1][0]= -(x_n-x_{n-1})/(x_n-x_{n-2})
  A[N-1][0]= -(values[0][N+2]-values[0][N+1])    \
    /(values[0][N+2]-values[0][N]);
  // A[n-1][1]= (2x_n-x_{n-2}-x_{n-1})/(x_n-x_{n-2})
  A[N-1][1]=(2*values[0][N+2]-values[0][N]-values[0][N+1])    \
    /(values[0][N+2]-values[0][N]);

  // solve Ac = f and write c into de_boor
  if(LRBand(N, BANDWIDTH, A)){return 2;}
  vwsubsband(N, BANDWIDTH, A, de_boor+1);
  rwsubsband(N, BANDWIDTH, A, de_boor+1);
  //  for(int i=0; i<n; i++){ de_boor[i]=f[i]; }
  
  for(int i=0; i<N; i++){free(A[i]);}
  free(A);

  
  return 0;
}

// ERROR CODES:
//  0: exited normally
//  1: allociation error
//  2: lr failed
