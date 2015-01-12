#ifndef SPLINEDEBOORPOINTS
#define SPLINEDEBOORPOINTS
/* ************************************************ */
/*                                                  */
/*   FILE: spline_de_boor_points.h                  */
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

#define BANDWIDTH 1

// Computing de Boor Points
/*  arguments:
    - array with points t_i and values f_{i-3}
    - number of lattice points x_i in [-1;1] N=n+1
    - array for de Boor Points c_i values to return
*/
int set_de_boor_points(double**,int, double*);

// ERROR CODES:
//  0: exited normally
//  1: allociation error
//  2: LU Decomposition failed


#endif
