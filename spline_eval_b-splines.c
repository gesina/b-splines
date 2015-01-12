
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



// evaluation of non-zero b-splines in [t_J,t_{J+1})
/*  argument:  
      - evaluation point x
      - interval [t_J, t_{J+1}] (beginning with 0)
      - lattice points t_i (beginning with 0)
      - array in which to store the values 
        of the (only) four (possibly) non-zero b-splines
        N_{j-3,4}, N_{j-2,4}, N_{j-1,4}, N_{j,4} in x
*/
int eval_b_splines(double x, int J, double* points, double* N)
{
  // PSEUDOCODE
  /*
    Übergebe Folge von Knoten x_i:
         t_0 =...= t_4 = x_0 <= t_5 <=...<= t_{N-1} = x_{n} = t_{n+3} =...= t_{n+6}
    Übergebe J mit x in [t_J; t_{J+1} )
    Setze N_{j, 1} = Xi_{ [t_j; t_{j+1}] } für j=J-3, ..., J
    und N_{p, 1}=X_{[t_p, t_m]} falls p={min{i|t_{i+1}=t_m}

    for j=J-3,..., J
     | for k=2,.. , 4
     |  |  // bestimme N_jk mit Rekursionsformel (siehe 6.2.5):
     |  |  N_{j,k}(x) =  (x-t_j)    / (t_{j+k-1}-t_j)     * N_{j,  k-1}(x)
     |  |              + (t_{j+1}-x)/ (t_{j+k}  -t_{j+1}) * N_{j+1,k-1}(x)   
     |  end
    end
  */

  // summands
  double C_1=0; // 1st part: (x-t_j)    / (t_{j+k-1}-t_j)     * N_{j,  k-1}(x)
  double C_2=0; // 2nd part: (t_{j+k}-x)/ (t_{j+k}  -t_{j+1}) * N_{j+1,k-1}(x)

  // N_{j,1}:
  N[3]=1;                           // N_{J,1} = 1
  for( int i=0; i<3; i++){N[i]=0;}  // N_{J,2},...,N_{J,4} = 0
  
  // N_{j,k}:
  for( int k=2; k<=4; k++)        // k= 1, ... , 4
    {
      for( int j=J-3; j<=J; j++)  // j= J-3, ... , J
	{
	  // summands C_1, C_2
	  // C_1 == 0?
	  if(fabs(points[j]-points[j+k-1])<=DBL_EPSILON) { C_1 = 0; }
	  else { C_1 = (x-points[j])/(points[j+k-1] - points[j])*N[j-(J-3)];   }
	  // C_2 == 0?
	  if(fabs(points[j+1]-points[j+k])<= DBL_EPSILON) { C_2 = 0; }
	  else { C_2 = (points[j+k]-x)/(points[j+k]-points[j+1])* N[j+1-(J-3)]; }

	  // N_{j,k} = ... (v. sup.)
	  N[j-(J-3)] = C_1 + C_2;
	}
    }
  return 0;
}
