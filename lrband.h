#ifndef _LRBAND_H_
#define _LRBAND_H_ 1

#include <math.h>
#include <stdio.h>

int LRBand (int n, int l, double ** A);
  /* LR-Zerlegung der Bandmatrix A ohne Pivotsuche */
  /* n: Dimension */
  /* l: Bandbreite */
  /* Das Ergebnis wird in A gespeichert und ist wieder eine Bandmatrix in
     speicherschonend abgespeichert */
  /* unterhalb der Diagonale ist L gespeichert */
  /* in der Diagonale und oberhalb R */
  
  /* !! Die Bandmatrix A hat n Zeilen und (2*l+1) Spalten !!*/
  /* Speicherstruktur analog zu Aufgabe 5 */
  
  /* Gibt den Wert 0 zurück wenn die LR-Zerlegung berechnet wurde. */
  /* Falls die LR-Zerlegung nicht möglich ist, wird 1 zurückgegeben. */


#endif
