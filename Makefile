CFLAGS=-Wall -O3 -g -march=native -malign-data=cacheline

all:	try_mpz test_format_longnum

test_format_longnum:	test_format_longnum.o format_longnum.o
	${CC} -o test_format_longnum test_format_longnum.o format_longnum.o

try_mpz:	try_mpz.o format_longnum.o
	${CC} -o try_mpz try_mpz.o format_longnum.o -lgmp

clean:
	rm -f test_format_longnum try_mpz \
		try_mpz.o format_longnum.o test_format_longnum.o
