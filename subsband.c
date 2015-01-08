/*
   'subsband.c' Obfuscated by COBF (Version 1.06 2006-01-07 by BB) at Thu Dec  8 14:38:39 2011
*/
#include"subsband.h"
#define lh double
#define le int
#define lw LRBand
#define lj for
#define lv if
#define lx fabs
#define lq printf
#define lm return
#define lp fmin
#define lu vwsubsband
#define ls fmax
#define lt rwsubsband
le lu(le lk,le lc,lh* *lr,lh*li){le la,lb;lh lf;lj(la=0;la<lk;la++){
lf=0.0;lj(lb=ls(la-lc,0);lb<la;lb++){lf=lf+lr[la][lb-la+lc] *li[lb];}
li[la]=(li[la]-lf);}lm 0;}le lt(le lk,le lc,lh* *ln,lh*li){le la,lb;
lh lf;lj(la=lk-1;la>=0;la--){lf=0.0;lj(lb=la+1;lb<lp(lk,la+lc+1);lb++
){lf=lf+ln[la][lb-la+lc] *li[lb];}li[la]=(li[la]-lf)/ln[la][lc];}lm 0
;}
