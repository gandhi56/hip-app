main.cc:17:9: error: use of undeclared identifier 'foo_func1'
  do { (foo_func1)<<<(dim3((N+256-1)/256,1,1)), (dim3(256,1,1)), (0), (0)>>>(N, d_a); } while (0);
        ^
1 error generated when compiling for host.
