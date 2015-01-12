#ifndef SPLINEEXAMPLE
#define SPLINEEXAMPLE
/* ************************************************ */
/*                                                  */
/*   FILE: spline_example.h                         */
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
//    Points and values within [-1;1]
//      of Example function f(x)=1/(1+25x^2)
//
//---------------------------------------------------



// example function f(x)=1/(1+25x^2)
/*  argument:
    - number of intervals in [-1,1]
    - array to return the points t_i and corresbonding values f_i
*/
int example(int, double**);


// function f(x)=1/(1+25x^2)
//  returns f(x)
double function(double);



#endif
