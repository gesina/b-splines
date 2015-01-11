
/* ************************************************ */
/*                                                  */
/*   FILE: spline_example.c                         */
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
//    Example function f(x)=1/(1+25x^2)
//
//---------------------------------------------------

#include <math.h>
#include <stdio.h>

#include "spline_example.h"

// example function f(x)=1/(1+25x^2)
/*  argument:
    - number of points in [-1,1]
    - array for values in given points to return
*/
int example(int n, double** values)
{
  //n=n+1; // number of Intervalls --> number of points
  
  values[0][3]= -1;                      // point x_0=t_1=t_2=t_3=t_4
  values[1][3]= function(values[0][3]);
  for(int i=0; i<3; i++)                 // virtual points t_1,...,t_3
    {
      values[0][i]=values[0][3];
      values[1][i]=values[1][3];
    }
  
  for(int i=4; i<=n+3; i++)
    {
      values[0][i] = 2*(i-3)/(double)(n) - 1;  // points x_i
      values[1][i] = function(values[0][i]);
    }
  
  for(int i=n+4; i<=n+6; i++)                // virtual points t_{n+5},...,t_{n+7}
    {
      values[0][i]=values[0][n+3];
      values[1][i]=values[1][n+3];
    }
  
  return 0;
}


// function f(x)=1/(1+25x^2)
//  returns f(x)
double function(double x)
{
  return 1/((double)(1+25*pow(x, 2)));
}
