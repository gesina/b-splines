#ifndef SPLINEIO
#define SPLINEIO

/* ************************************************ */
/*                                                  */
/*   FILE: spline_io.h                              */
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
//  Input and output for b-spline evaluation
//
//---------------------------------------------------

#define OUTPUT_FILE "spline_example.dat"
#define LINE_ENTRY "   %16.12f    %16.12f"

// get number of points
/*  argument:
      - instruction string
      - output string for faulty input
    return:   input integer
*/
int get_int(char*, char*);


// print line into file
/*  argument:
      - x value
      - f(x) value
*/
int print_line(double, double);


// open file
int open_file();

// close file
int close_file();


#endif
