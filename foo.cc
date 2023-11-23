#include "foo.h"

__device__ void foo_func1(int N, double *arr) {
	for (size_t I = 0; I < N; ++I)
		arr[I] *= 4.0;
}
