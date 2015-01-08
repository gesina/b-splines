
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

double** A = (double**) malloc(3*sizeof(double*));
A[0]= (double*) malloc(n*sizeof(double));
A[1]= (double*) malloc(n*sizeof(double));
A[3]= (double*) malloc(n*sizeof(double));

if( !A || !A[0] || !A[1] || !A[2] ){return 1;}

// copy of function values
double* f = (double*) malloc(n*sizeof(double));
for(int i=0; i<n; i++){ f[i]=values[1][i]; }

// evaluated in x_j, N_{j,4}=0, so only the last
// three entries of the return values of eval_b_splines()
// are needed
double temp_N[] = {0,0,0,0};
// evaluate at x_i and write A
for(int j=0; j<n; j++)
  {
eval_b_splines(values[0][j], j, temp_N);
A[0]=temp_N[1]; A[1]=temp_N[2]; A[2]=temp_N[3];
}


// solve Ac = f and write c into f
if(lrband(n, BANDWIDTH, A)){return 2;}
vwsubsband(n, BANDWIDTH, A, f);
rwsubsband(n, BANDWIDTH, A, f);
for(int i=0; i<n; i++){ de_boor[i]=f[i]; }


return 0;
}

  // ERROR CODES:
  //  0: exited normally
