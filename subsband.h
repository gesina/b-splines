#ifndef _SUBSBAND_H_
#define _SUBSBAND_H_ 1
/* ************************************************ */
/*                                                  */
/*   FILE: subsband.h                               */
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
//  Forward and backward substitution
//   for band matrices
//
//---------------------------------------------------

// forward substitution, solves Lx=b
/*  arguments:
     - dimension (number of rows) n
     - bandwidth l
     - matrix L (only elements underneath diagonal used)
    return: substituted vector in b
 */
int vwsubsband(int n, int l, double ** L, double * b);

// backward substitution, solves Rx=b
/*  arguments:
     - dimension (number of rows) n
     - bandwidth l
     - matrix R (elements underneath diagonal not used)
    return: resulting vector x in b
 */
int rwsubsband(int n, int l, double ** R, double * b);

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

#endif
