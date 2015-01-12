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
#define LINE_ENTRY "\n   %16.12f    %16.12f"

// get character from user
/*  argument:
      - instruction string
      - string with allowed characters
      - output string for faulty input
    return:   input integer
*/
char get_char(char*, char*, char*);

  
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
int init_file();
// ERROR CODES:
//  0: exited normally
//  3: file handling error
//  4: refused to overwrite


#endif
