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

// evaluation of non-zero b-splines in [t_j,t_{j+1})
/*  argument:  
      - evaluation point x
      - interval [t_j, t_{j+1})
      - array where to store the values 
        of the four non-zero b-splines
        N_{j-3,4}, N_{j-2,4}, N_{j-1,4}, N_{j,4}
        in x
*/
int eval_b_splines(double, int, double*);

// ERROR CODES:
//  0: exited normally


#endif
