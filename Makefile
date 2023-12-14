CFLAGS = -g -Wall

all: static_hash_map dynamic_hash_map

# apps

dynamic_hash_map: dynamic_hash_map.o customer.o
	cc $(CFLAGS) dynamic_hash_map.o customer.o -o dynamic_hash_map

static_hash_map: static_hash_map.o customer.o
	cc $(CFLAGS) static_hash_map.o customer.o -o static_hash_map

# app binaries

dynamic_hash_map.o: dynamic_hash_map.c customer.h
	cc $(CFLAGS) -c dynamic_hash_map.c -o dynamic_hash_map.o

static_hash_map.o: static_hash_map.c customer.h
	cc $(CFLAGS) -c static_hash_map.c -o static_hash_map.o

# library binaries

customer.o: customer.c customer.h
	cc $(CFLAGS) -c customer.c -o customer.o

#special
clean:
	rm -f *.o

clobber:
	rm -f *.o
	rm -f static_hash_map dynamic_hash_map