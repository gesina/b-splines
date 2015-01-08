#ifndef SPLINESEVALUATION
#define SPLINESEVALUATION

/* ************************************************ */
/*                                                  */
/*   FILE: splines_evaluation.h                     */
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
      - lattice (only {x_{j-3},..., x_j} needed)
      - array with de Boor Points (only {c_{j-3},..., c_j} needed)
      - index of section j
*/
double evaluation(double, double*, double*, int)


#endif
