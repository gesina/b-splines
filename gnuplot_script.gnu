
# ************************************************ #
#                                                  #
#   FILE: gnuplot_script.gnu                       #
#                                                  #
#   PROJECT:                                       #
#   *************                                  #
#    B-SPLINES                                     #
#                                                  #
#   Excercise #55 for the lecture                  #
#   NUMERICAL MATHEMATICS in 2014/15               #
#   by Prof. Dr. Blank                             #
#   University of Regensburg                       #
#                                                  #
#   AUTHORS:                                       #
#   *************                                  #
#     Kerstin Blomenhofer and Gesina Schwalbe      #
#     Group 30                                     #
#                                                  #
# ************************************************ #



#---------------------------------------------------
#
#    gnuplot script
#    to print b-spline approximation of example function
#
#---------------------------------------------------

# output to show on screen

# set title
set title "Approximation of example function with B-Splines"

# position of caption
set key right top

# coordinate system
set xtics 0.1
set mxtics 5
set ytics 0.2
set mytics 5
set grid

# actual plot
plot "spline_example.dat" with linespoints pointtype 7 pointsize 0.5 linetype 1 linewidth 2 title "f(x)=1/(1+25x^2)"


# ----------------------------------------------------------------
# output into png-file

# png output
set terminal png size 1000, 800

# output file
set output "spline_example.png"

# actual plot
plot "spline_example.dat" with linespoints pointtype 7 pointsize 0.5 linetype 1 linewidth 2 title "f(x)=1/(1+25x^2)"
