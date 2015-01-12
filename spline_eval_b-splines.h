#ifndef SPLINEEVALBSPLINE
#define SPLINEEVALBSPLINE

/* ************************************************ */
/*                                                  */
/*   FILE: spline_eval_b-splines.h                 */
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


// evaluation of spline in x
/*  argument:
      - evaluation point x
      - lattice points t_i (beginning with 0);
        only {x_{j-3}=t_{j},..., x_j=t_{j+3}} needed)
      - array with de Boor Points;
        only {c_{j-3},..., c_j} needed
      - index of section j with x in [t_j, t_{j+1}] (beginning with 0)
*/
int eval_b_splines(double, int, double*, double*);

#endif
