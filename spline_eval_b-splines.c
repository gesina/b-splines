
/* ************************************************ */
/*                                                  */
/*   FILE: spline_eval_b-splines.c                  */
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


#include <float.h>
#include <math.h>
#include "spline_eval_b-splines.h"

// evaluation of non-zero b-splines in [t_j,t_{j+1})
/*  argument:  
      - evaluation point x
      - interval [t_J, t_{J+1})
      - lattice points x_i
      - array where to store the values 
        of the four non-zero b-splines
        N_{j-3,4}, N_{j-2,4}, N_{j-1,4}, N_{j,4}
        in x
*/
int eval_b_splines(double x, int J, double* points, double* N)
{
  /*
    Übergebe Folge von Knoten x_i t_0 =< ... =< t_{m-1}
    Übergebe J mit x_quer \in [t_J; t_{J+1} )
    Übergebe N_{j, 1} = X_{[t_j; t_{j+1}] } 
             und N_{p, 1}=X_{[t_p, t_m]} falls p={min{i|t_{i+1}=t_m}

    for j=j'-3, ... , j'
        for k=1, ... , 4
            bestimme N_jk mit Rekursionsformel (siehe 6.2.5):
	    N_{j,k} (x) = (x-t_j)    / (t_{j+k-1}-t_j)     * N_{j,  k-1}(x)
	                + (x-t_{j+1})/ (t_{j+k}  -t_{j+1}) * N_{j+1,k-1}(x)   
        end
    end
  */


  // summands
  double C_1=0; // 1st part: (x-t_j)    / (t_{j+k-1}-t_j)     * N_{j,  k-1}(x)
  double C_2=0; // 2nd part: (x-t_{j+1})/ (t_{j+k}  -t_{j+1}) * N_{j+1,k-1}(x)

  // N_{j,1}: N_{J,1}=1; N_{J,2},...,N_{J,4}=0
  N[0]=1;
  for( int j=1; j<4; j++){N[j]=0;}
  // N_{j,i}:
  for( int k=2; k<=4; k++)       // k= 1, ... , 4
    {
      for( int j=J; j<J+4; j++)  // j= J, ... , J+3
	{
	  // summands C_1, C_2
	  if(fabs(points[j] - points[j+3])<= DBL_EPSILON) { C_1 = 0; } // j >= n-3?
	  else { C_1 = (x-points[j])  /(points[j+3]-points[j])  * N[j-J];   }
	  if(fabs(points[j+1]-points[j+4])<= DBL_EPSILON) { C_2 = 0; } // j+1>=n-2?
	  else { C_2 = (x-points[j+1])/(points[j+4]-points[j+1])* N[j+1-J]; }
	  
	  N[j-J] = C_1 + C_2;
	}
    }


  
  return 0;
}

// ERROR CODES:
//  0: exited normally
