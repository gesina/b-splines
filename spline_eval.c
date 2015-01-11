
/* ************************************************ */
/*                                                  */
/*   FILE: spline_eval.c                           */
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
//     Evaluation of B-splines in point x
//
//---------------------------------------------------


#include <stdio.h>

#include "spline_eval.h"
#include "spline_eval_b-splines.h"
#include "spline_de_boor_points.h"


// evaluation of spline in x
/*  argument:
      - evaluation point x
      - lattice (only {x_{j-3},..., x_j} needed)
      - array with de Boor Points (only {c_{j-3},..., c_j} needed)
      - index of section j with x in [t_j, t_{j+1}] (beginning with 0)
*/
double evaluation(double x, double* points, double* de_boor, int j)
{
  double temp_N[4] = {0,0,0,0};     // N_{j-3},...,N_{j}

  eval_b_splines(x, j, points, temp_N);

  x=0;
  for (int i=0; i<4; i++)
    {    
      x += de_boor[j-i]*temp_N[3-i];
    }
  
  
  return x;
}
