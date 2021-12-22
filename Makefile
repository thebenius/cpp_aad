
.PHONY: all, doxygen, clean

all:
	mkdir -p build
	cd build; cmake ..
	cd build; make

doxygen:
	doxygen Doxfile

clean:
	rm -rf build
	rm -rf html