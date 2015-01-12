
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
//    Points and values within [-1;1]
//      of Example function f(x)=1/(1+25x^2)
//
//---------------------------------------------------

#include <math.h>

#include "spline_example.h"

// example function f(x)=1/(1+25x^2)
/*  argument:
    - number of intervals in [-1,1]
    - array to return the points t_i and corresbonding values f_i
*/
int example(int n, double** values)
{ 
  values[0][3]= -1;                      // point x_0=t_0=t_1=t_2=t_3
  values[1][3]= function(values[0][3]);  //  + values
  for(int i=0; i<3; i++)                 // virtual points t_0,...,t_2
    {
      values[0][i]=values[0][3];
      values[1][i]=values[1][3];         //  + values
    }
  
  for(int i=4; i<=n+3; i++)
    {
      values[0][i] = 2*(i-3)/(double)(n) - 1;// points x_i = t_3,...,t_{n+3}
      values[1][i] = function(values[0][i]);
    }
  
  for(int i=n+4; i<=n+6; i++)                // virtual points t_{n+4},...,t_{n+6}
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
  return 1/((double)(1+25*x*x));
}
