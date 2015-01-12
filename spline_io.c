
/* ************************************************ */
/*                                                  */
/*   FILE: spline_io.c                              */
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

#include <stdio.h>     // printf(), fprint() ...
#include <string.h>    // strchr()

#include "spline_io.h"


// get character from user
/*  argument:
    - instruction string
    - string with allowed characters
    - output string for faulty input
    return:   input integer
*/
char get_char(char* instruct, char* allowed, char* failure)
{
  _Bool b=0;    // helper bool
  char c=' ';
  printf(" %s ", instruct);
  do
    {
      c=getchar();                          // get user input
      if ( strchr(allowed, c)){break;}            // ok --> quit
      else if (c=='\n') {b=1;}                    // newline --> again
      else {printf(" %s ", failure); b=1;}        // not ok --> warning+repeat
    }
  while(b);

  return c;     // return c
}



// get number of points
/*  argument:
    - instruction string
    - output string for faulty input
    return:   input integer
*/
int get_int(char* instruct, char* failure)
{
  int res = -1;   // value to return
  _Bool b=0;      // test bool for while-loop

  printf(" %s ", instruct);
  do  // as long as input doesn't make sense: repeat
    {
      while(getchar()!='\n');
      scanf("%d", &res); // user read in
      // verify input
      if ( res <= 0 )  // not ok --> try again
	{
	  printf(" %s\n", failure);
	  printf("   Your input: %i\n", res);
	  printf("Try again:  "); // ... and give some warning
	  b=1;
	}
      else             // ok and wanted --> return
	{
	  printf("You entered %d. Take it?\n", res);
	  if( get_char("Please enter (y)es or (n)o: ", \
		       "yn",                           \
		       "Please enter yes (y) or no (n): ")!='y')
	    {
	      printf("Then try again: ");
	      b=1;
	    }
	  else { b=0; }
      }
    }
  while(b); 

  
  return res;

}



// print line into file
/*  argument:
    - x value
    - f(x) value
*/
int print_line(double x, double f)
{
  // open file to "a"ppend content
  FILE* file=fopen(OUTPUT_FILE, "a");
  if(!file){return 3;}  // if not existing return err

  // actual writing
  fprintf(file, LINE_ENTRY, x, f);
  int err = fflush(file);                         // complete output and ...
  if(err) {perror(NULL); fclose(file); return 3;} // ... check on errors

  err = fclose(file);                             // close file, and again ...
  if(err) {perror(NULL); return 3;}               // ... check on errors

  return 0;
}


// open file
int init_file()
{
  // try to open file
  FILE* file=fopen(OUTPUT_FILE, "r");
  if(!file)  // if not existing ...
    {
      // create file to write in
      file=fopen(OUTPUT_FILE, "w+");
      if(!file){return 3;}
      
      printf(" Created file %s\n", OUTPUT_FILE);
    }
  else       // if already existing ...
    {
      if( get_char("\nOverwrite output file OUTPUT_FILE? ((y)es or (n)o)", \
		  "yn", "Please enter (y) or (n):")			\
	 == 'y') // user wants to overwrite?
	{
	  printf("Overwriting file ...\n");
	  // create file
	  file=fopen(OUTPUT_FILE, "w");
	  if(!file){return 3;}
	}
      else{      // quit if not
	return 4;
      }
    }

  return 0;
}
