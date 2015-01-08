
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
#include <stdio.h>

#include "spline_io.h"
#include "spline_de_boor_points.h"
#include "spline_eval.h"


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
  open_file();
  
  // get number of points
  int n = get_int("Please enter the number of points within [-1;1]", "Please enter an integer number");
  

  // get example function values
  //  first array: evaluation points
  //  second array: values f(x)
  double* values[2] = (double**) malloc(2*sizeof(double*));
  values[0]=(double*) malloc(n*sizeof(double));   // points x_i
  values[1]=(double*) malloc(n*sizeof(double));   // values f(x_i)

  example(n, values);

  
  // get spline, characterized with de Boor Points
  double* de_boor_points= (double*) malloc(n*sizeof(double));
  set_de_boor_points(values,de_boor_points);

  
  // write into file
  for(int j=0; j<n; j++)
    {
      // (x_j, f(x_j))
      print_line(2*j/n-1, values[1][j] );
      
      for(i=1/POINTS_PER_SEC; i<1; i+=1/POINTS_PER_SEC)
	{
	  // (x, s(x)) with x in [x_j, x_{j+1})
	  print_line(2*j/n-1+i, evaluation(x, values[0], de_boor_points, j));	  
	}
    }
  // (x_n, f(x_n))
  print_line(1, values[1][n-1]);



  // exit
  close_file();
  free(values[0]);
  free(values[1]);
  free(values);
  free(de_boor_points);

  
  return 0;
}
