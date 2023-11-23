
app:
	hipcc main.cc foo.cc bar.cc -fgpu-rdc -o app --save-temps

clean:
	rm -rf app a.out* *.hipi *.o *.bc *.ll *.resolution.txt *.s *.hipfb *.mcin
