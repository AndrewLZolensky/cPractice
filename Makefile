CFLAGS = -g -Wall

all: static_hash_map dynamic_hash_map enc_hash_map function_pointers

# apps

function_pointers: function_pointers.o
	cc $(CFLAGS) function_pointers.o -o function_pointers

enc_hash_map: enc_hash_map.o customer.o customer_hash.o
	cc $(CFLAGS) enc_hash_map.o customer.o customer_hash.o -o enc_hash_map

dynamic_hash_map: dynamic_hash_map.o customer.o
	cc $(CFLAGS) dynamic_hash_map.o customer.o -o dynamic_hash_map

static_hash_map: static_hash_map.o customer.o
	cc $(CFLAGS) static_hash_map.o customer.o -o static_hash_map

# app binaries

function_pointers.o: function_pointers.c
	cc $(CFLAGS) -c function_pointers.c -o function_pointers.o

enc_hash_map.o: enc_hash_map.c customer.h customer_hash.h
	cc $(CFLAGS) -c enc_hash_map.c -o enc_hash_map.o

dynamic_hash_map.o: dynamic_hash_map.c customer.h
	cc $(CFLAGS) -c dynamic_hash_map.c -o dynamic_hash_map.o

static_hash_map.o: static_hash_map.c customer.h
	cc $(CFLAGS) -c static_hash_map.c -o static_hash_map.o

# library binaries

customer_hash.o: customer_hash.c customer.h customer_hash.h
	cc $(CFLAGS) -c customer_hash.c -o customer_hash.o

customer.o: customer.c customer.h
	cc $(CFLAGS) -c customer.c -o customer.o

#special
clean:
	rm -f *.o

clobber: clean
	rm -f static_hash_map dynamic_hash_map enc_hash_map function_pointers