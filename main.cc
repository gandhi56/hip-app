#include <hip/hip_runtime.h>
#include <iostream>
#include "foo.h"
#include "bar.h"

#define HIP_CHECK(command) {        \
  hipError_t status = command;      \
  if (status != hipSuccess) {       \
    std::cerr << "Error: HIP reports " << hipGetErrorString(status) << std::endl;  \
    std::abort();}}

__global__ void driver(int N, double *arr) {
  bar_func1(N, arr);
  foo_func1(N, arr);
}

int main() {
  int N = 1000;
  size_t Nbytes = N * sizeof(double);
  double *h_a = (double*)malloc(Nbytes);
  double *d_a = nullptr;
  HIP_CHECK(hipMalloc(&d_a, Nbytes));
  HIP_CHECK(hipMemcpy(d_a, h_a, Nbytes, hipMemcpyHostToDevice));
  hipLaunchKernelGGL(driver, dim3((N+256-1)/256,1,1), dim3(256,1,1), 0, 0, N, d_a);
  HIP_CHECK(hipGetLastError());
  HIP_CHECK(hipMemcpy(h_a, d_a, Nbytes, hipMemcpyDeviceToHost));
  free(h_a);
  HIP_CHECK(hipFree(d_a));
  return 0;
}
