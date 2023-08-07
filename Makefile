
all: build
	cd build && cmake .. -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release
	cd build && cmake --build .

build:
	mkdir -p build && cd build && conan install .. --output-folder=. --build=missing

clean clobber:
	rm -r build

