#include"subsband.h"

int vwsubsband(int n, int l, double** L, double* b) {
	double subs;
	for(int i=0; i<n; i++) {
		subs=0.0;
		for(int j=fmax(i-l,0); j<i; j++) {
			subs=subs+L[i][j-i+l] *b[j];
		}
		b[i]=(b[i]-subs);
	}
	return 0;
}

int rwsubsband(int n, int l, double** R, double* b) {
	double subs;
	for(int i=n-1; i>=0; i--) {
		subs=0.0;
		for(int j=i+1; j<fmin(n,i+l+1); j++) {
			subs=subs+R[i][j-i+l] *b[j];
		}
		b[i]=(b[i]-subs)/R[i][l];
	}
	return 0;
}
