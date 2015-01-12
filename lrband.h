#ifndef _LRBAND_H_
#define _LRBAND_H_ 1
/* ************************************************ */
/*                                                  */
/*   FILE: lrband.h                                 */
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
/*   SOURCE:                                        */
/*   *************                                  */
/*     Material for exercise #55 on                 */
/*     https://elearning.uni-regensburg.de/         */
/*     course Numerik I, WS14/15                    */
/*                                                  */
/* ************************************************ */


//---------------------------------------------------
//
//  LU Decomposition of band matrices
//
//---------------------------------------------------



// LU Decomposition of band matrix A (without Pivoting)
/*  arguments:
     - dimension (number of rows) n
     - bandwidth l
     - matrix A
    return: decomposed matrix in A, still band matrix
            (underneath diagonal L, above R)
 */
int LRBand (int n, int l, double ** A);

/*
  For A = 
  / a_11  a_12 ... a_1,(1+l)  0  ...  0       \
 |  a_21  a_22 ...      .             .        |
 |  .      .                .         .        |
 |  .           .               .     .        |
 |  a_(l+1),1       .               . 0        |
 |  0      .            .         a_(n-l+1),n  |
 |  .          .             .        .        |
 |  .              .             .    .        |
  \ 0  ...        0  a_n,(n-l-1) ... a_nn     /
   
  enter A=
   / 0 ... a_11 ... a_1,(1+l) \
  |  0 ..a_21 ...   a_2,(1+l)  |
  |  .               .         |
  |  .               .         |
  |  .               .         |
   \ a_n1 ...       a_n,(1+l) /

   which has n rows and (2*l+1) columns

 */

// ERROR CODE:
//   0: exited normally
//   1: LU Decomposition failed

#endif
