
app:
	hipcc main.cc foo.cc bar.cc -fgpu-rdc -fuse-ld=lld -flto=thin -o app --save-temps -v

clean:
	rm -rf app a.out* *.hipi *.o *.bc *.ll *.resolution.txt *.s *.hipfb *.mcin
