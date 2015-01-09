
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


#include "spline_eval.h"
#include "spline_eval_b-splines.h"
#include "spline_de_boor_points.h"


// evaluation of spline in x
/*  argument:
      - evaluation point x
      - lattice (only {x_{j-3},..., x_j} needed)
      - array with de Boor Points (only {c_{j-3},..., c_j} needed)
      - index of section j
*/
double evaluation(double x, double* x_i, double* de_boor, int j)
{
  double res=0;
  
  return res;
}
