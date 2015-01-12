
/* ************************************************ */
/*                                                  */
/*   FILE: spline_main.c                           */
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
//  Main executive file for implementation of
//     evaluation of B-splines
//
//---------------------------------------------------


// LIBRARIES
#include <stdlib.h>   // malloc()
#include <stdio.h>    // printf()

#include "spline_main.h"
#include "spline_io.h"
#include "spline_de_boor_points.h"
#include "spline_eval.h"
#include "spline_example.h"



// main function
int main(void)
{
  // open output file
  int err= init_file();
  if(err){return err;}
  
  
  // get number of points
  int n = get_int("Please enter the number of intervals in [-1;1]", \
		  "Please enter an integer number");

  // get example function values
  //  first array: evaluation points
  //  second array: values f(x)
  double* values[2];
  values[0]=(double*) malloc((n+7)*sizeof(double));   // points x_i + 6 virtual
  values[1]=(double*) malloc((n+7)*sizeof(double));   // values f(x_i)

  example(n, values);  // lattice points + values + 4 virtual points

  // get spline, characterized by the (n+3) de Boor Points
  double* de_boor_points= (double*) malloc((n+3)*sizeof(double));
  set_de_boor_points(values, n+1, de_boor_points);
  // print De Boor Points
  printf("De Boor Points:\n");
  for(int i=0; i<n+3; i++){printf(" %f\n", de_boor_points[i]);}
  
  printf("\nf(1/3) ~ %13.11f   for n=%i, 1/3 in [t_%i, t_%i]\n",	\
	 evaluation(1/(double)3 , values[0], de_boor_points, (int) (4*n)/(3*2)+3),\
	 n,								\
	 (int) ((4*n)/(double)(3*2))+3,					\
	 (int) ((4*n)/(double)(3*2)) +4);
  
  
  // write into file
  double x=-1;   // temporal evaluation point
  for(int j=0; j<n; j++)
    {
      // (x_j, f(x_j))
      print_line(x, values[1][j+3] );
      
      for(double i=1; i<POINTS_PER_SEC; i++)
	{
	  // (x, s(x)) with x in [x_j, x_{j+1})
	  x += 2/((double)POINTS_PER_SEC*n);
	  print_line(x, evaluation(x, values[0], de_boor_points, j+3));	  
	}
      x+= 2/((double)POINTS_PER_SEC*n);
    }
  // (x_n, f(x_n))
  print_line(1, values[1][n+3]);


  // exit
  free(values[0]);
  free(values[1]);
  free(de_boor_points);

  
  return 0;
}
