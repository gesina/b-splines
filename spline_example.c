
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
  printf("  %f\n", values[1][0]);
  
  for(int i=0; i<n-1; i++)
    {
      values[0][i] = i/(double)n - 1;              // points x_i
      values[1][i] = function(values[0][i]);
    }
  values[0][n-1] = 1;                      // point x_{n}
  values[1][n-1] = function(values[0][n-1]); 
  for(int i=0; i<4; i++){                  // virtual points x_{n+1},...,x_{n+4}
    values[0][n+i]=1;
    values[1][n+i]=values[1][n-1];
  }
  
  return 0;
}


// function f(x)=1/(1+25x^2)
//  returns f(x)
double function(double x)
{
  return 1/((double)(1+25*pow(x, 2)));
}
