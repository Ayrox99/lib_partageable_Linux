
all: test

test: install
	cd bin; \
	LD_LIBRARY_PATH=. ./main libComposant1.so libComposant2.so

install:
	cd main && ${MAKE} install

clean:
	cd main && ${MAKE} clean
