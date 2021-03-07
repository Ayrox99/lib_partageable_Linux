
all: test

test: install
	cd bin; \
	LD_LIBRARY_PATH=. ./main test1 test2

install:
	cd main && ${MAKE} install

clean:
	cd main && ${MAKE} clean
