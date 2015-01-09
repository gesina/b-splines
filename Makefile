cc = gcc
CFLAGS = -Wall -Werror -O2 -std=c99 -lm -g 
LCFLAGS = $(CFLAGS)
OCFLAGS = $(CFLAGS) -c
MAINBIN = spline_approximation

DEPFILE = spline.deps

#objects
OBJECTF += lrband.o
OBJECTF += spline_de_boor_points.o
OBJECTF += spline_eval_b-splines.o
OBJECTF += spline_eval.o
OBJECTF += spline_example.o
OBJECTF += spline_io.o
OBJECTF += spline_main.o
OBJECTF += subsband.o

all: deps main

deps: *.h *.c
	$(cc) -MM *.c > $(DEPFILE)

main: ${OBJECTF}
	$(cc) $(CFLAGS) -o $(MAINBIN) *.o

%.o: %.c %.h
	$(cc) $(OCFLAGS) -o $*.o $*.c
 


include $(DEPFILE)
