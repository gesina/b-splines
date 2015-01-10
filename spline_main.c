
/* ************************************************ */
/*                                                  */
/*   FILE: splines_main.c                           */
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


// LIBRARIES
#include <stdlib.h>
#include <stdio.h>

#include "spline_main.h"
#include "spline_io.h"
#include "spline_de_boor_points.h"
#include "spline_eval.h"
#include "spline_example.h"

//---------------------------------------------------
//
//  Main executive file for implementation of
//     evaluation of B-splines
//
//---------------------------------------------------

// main function
int main(void)
{
  // open output file
  int err= init_file();
  if(err){return err;}

  
  // get number of points
  int n = get_int("Please enter the lattice constant for [-1;1]", \
		  "Please enter an integer number");

  // get example function values
  //  first array: evaluation points
  //  second array: values f(x)
  double* values[2];
  values[0]=(double*) malloc((n+7)*sizeof(double));   // points x_i + 3 virtual
  values[1]=(double*) malloc((n+7)*sizeof(double));   // values f(x_i)

  example(n, values);  // lattice points + values + 4 virtual points

  //DEBBUGGING
  for(int i=0; i<n+7; i++){printf(" %f\t%f\n", values[0][i], values[1][i]);}


  // get spline, characterized with the (n+3) de Boor Points
  double* de_boor_points= (double*) malloc((n+3)*sizeof(double));
  set_de_boor_points(values, n, de_boor_points);
  //DEBBUGGING
  for(int i=0; i<n+4; i++){printf(" %f\n", de_boor_points[i]);}

  return 0;
  
  // write into file
  double x=0;   // temporal evaluation point
  for(int j=0; j<n; j++)
    {
      // (x_j, f(x_j))
      print_line(2*j/n-1, values[1][j+3] );
      
      for(double i=1; i<POINTS_PER_SEC; i++)
	{
	  // (x, s(x)) with x in [x_j, x_{j+1})
	  x = values[0][j+3] + i/POINTS_PER_SEC;
	  print_line(x, evaluation(x, values[0], de_boor_points, j+3));	  
	}
    }
  // (x_n, f(x_n))
  print_line(1, values[1][n-1]);


  // exit
  free(values[0]);
  free(values[1]);
  free(de_boor_points);

  
  return 0;
}
