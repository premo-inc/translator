all:
	mkdir -p build \
			&& cd build \
			&& cmake .. \
			&& make
	make run

clean:
	rm -rf build

run:
	#./build/loader ../vendor/onikiri2/benchmark/HelloWorld/a.out
	./build/loader ../../test-files/hello.riscv
	#./build/loader ../../test-files/hello.static.strip.riscv
	#./build/loader ../../test-files/nop.x64
	#./build/loader ../../test-files/hello.x86
