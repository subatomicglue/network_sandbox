all:
	conan profile detect --force
	BORINGSSL_DIR=`conan cache path boringssl/0.0.1` && conan create . --profile=default
	conan list lsquic
