
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

# set title
set title "Approximation of example function with B-Splines"

# position of caption
set key right top

# actual plot
# linespoints:  Linie mit Markierungen an den Knoten
# linetype:     1 durchgezogene Linie
#               2 gestrichelte Linie
#               3 gepunktelte Linie
# linewidth:    Breite der Linie in pt
# title:        Bezeichner für die Datenreihe in der Legende
plot "spline_example.dat" with linespoints linetype 1 linewidth 2 title "f(x)=1/(1+25x^2)"


# ----------------------------------------------------------------
# output into png-file

# png output
set terminal png size 800, 500

# output file
set output "spline_example.png"

# actual plot
plot "spline_example.dat" with linespoints linetype 1 linewidth 2 title "f(x)=1/(1+25x^2)"