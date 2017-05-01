# Implementation of the De Boor's algorithm for evaluation of basis splines

This project was an excercise for the lecture 
*Numerical Mathematics* for Bachelor students by
[Prof. Dr. Blank](http://www.mathematik.uni-regensburg.de/Mat8/Blank/)
at the University of Regensburg in 2014. It implements
[De Boor's algorithm](https://en.wikipedia.org/wiki/De_Boor%27s_algorithm) 
for evaluation of cubic
[basis spline approximations](https://en.wikipedia.org/wiki/B-spline)
(sort of peacewise interpolation of function values with cubic polynomials).


## Requirements
- Compilation: **gcc**, **make**
- Graphical output: [**gnuplot**](http://gnuplot.info/)


## Functionality
### `spline_approximation`
The output program `spline_approximation` will, after calling it with

```bash
./spline_approximation
```

- ask for the number of intervals to consider for approximation;
  *n* intervalls correspond to *n+1* data points for interpolation 
  (the more, the better)
- generate an array of points and values:
  + points: *n+1* equally distributed points in the interval [-1;1]
  + values: calculated as specified in `function(double)` in `spline_example.c`
- calculate de Boor's points of the cubic interpolating spline and
  print them to the console
- evaluate the interpolating spline at `POINTS_PER_SEC` (see
  `spline_main.h`) points in each of the *n* spline-peace-intervals
  and write the data to `OUTPUT_FILE` (see `spline_io.h`; it is
  `spline_example.dat` at the moment)
- print the approximated value at the evaluation point 1/3 to the console. 

See also comments in `spline_main.c`.

### `gnuplot_script.gnu`
The gnuplot-script `gnuplot_script.gnu` will produce an png
(`spline_example.png`) out of the evaluation data `spline_example.dat`
if one calls

```bash
gnuplot gnuplot_script.gnu
```

The size, title etc. can be modified in `gnuplot_script.gnu`.


## Compilation
Simply call

```bash
make
```


## Structure of the Files
Mind the (quite elaborate) comments in the source files that try to
describe the functionality.
The pseudocode-peaces required for the tutors are in German, sorry for that. 

- Main function: `splines_main.*`
- Calculation of de Boor points (=coefficients for the spline-peaces)
  from given array of points and values to approximate: `spline_de_boor_points.*`
- Evaluation of a spline from given point-values and corresponding de
  Boor points: 
  + `spline_eval_b-spline.*` (eval. of single b-spline peace), 
  + `spline_eval.*` (put values of peaces together to eval. of complete spline) 
- Solution of linear equation systems (externally provided): `lrband.*`, `subsband.*` 
- Calculation of values of example function to interpolate: `spline_example.*`
- Example outputs with different numbers of intervals: `spline_example_{6,7,17}.png`
- File- and Terminal-IO: `splines_io.*`
- Build helper: `Makefile`, `splines.deps`
- Gnuplot script for exporting to png: `gnuplog_script.gnu`
