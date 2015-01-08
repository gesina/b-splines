#ifndef _SUBSBAND_H_
#define _SUBSBAND_H_ 1

#include <math.h>
#include <stdio.h>

int vwsubsband(int n, int l, double ** L, double * b);
  /* Vorwaertssubstitution, loest Lx=b */
  /* mit linker unterer Dreiecksmatrix L; */
  /* die oberen Elemente (einschl. Hauptdiagonale) */
  /* werden nicht verwendet */
  /* das Ergebnis wird direkt in b gespeichert; */
  /* l=Bandbreite, n=Dimension*/
  
  /* !! Die Bandmatrix L hat n Zeilen und (2*l+1) Spalten !!*/
  /* Speicherstruktur analog zu Aufgabe 5 */

int rwsubsband(int n, int l, double ** R, double * b);
  /* Rueckwaertssubstitution, loest Rx=b */
  /* mit rechter oberer Dreiecksmatrix R; */
  /* die unteren werden nicht verwendet */
  /* das Ergebnis wird direkt in b gespeichert */
  /* l=Bandbreite, n=Dimension*/
  
  /* !! Die Bandmatrix L hat n Zeilen und (2*l+1) Spalten !!*/
  /* Speicherstruktur analog zu Aufgabe 5 */

#endif
