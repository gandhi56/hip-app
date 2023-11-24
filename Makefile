
app:
	#hipcc main.cc foo.cc bar.cc -fgpu-rdc -fuse-ld=lld -o app --save-temps
	/home/angandhi/llvm-project/build/bin//clang++  -isystem "/opt/rocm/include" --offload-arch=gfx908 -O3 -mllvm -amdgpu-early-inline-all=false -mllvm -amdgpu-function-calls=true  -O3 --hip-link --offload-arch=gfx908 --rtlib=compiler-rt -unwindlib=libgcc  -x hip main.cc -x hip foo.cc -x hip bar.cc -fgpu-rdc -fuse-ld=lld -o "app" --save-temps

clean:
	rm -rf app a.out* *.hipi *.o *.bc *.ll *.resolution.txt *.s *.hipfb *.mcin
