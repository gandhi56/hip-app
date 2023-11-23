#include "bar.h"

__device__ void bar_func1(int N, double *Arr){
	for (int I = 0; I < N; ++I) {
		*(Arr + I) = 2.0;
	}
}
