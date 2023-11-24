#include "foo.h"

__device__ void foo_func1(int N, double *Arr) {
	X = 6.0;
	for (size_t I = 0; I < N; ++I)
		Arr[I] *= 4.0;
}
