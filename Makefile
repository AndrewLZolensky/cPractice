CFLAGS = -g -Wall

all: app

app: app.o customer.o
	cc $(CFLAGS) app.o customer.o -o app

app.o: app.c customer.h
	cc $(CFLAGS) -c app.c -o app.o

customer.o: customer.c customer.h
	cc $(CFLAGS) -c customer.c -o customer.o

clean:
	rm -f app.o customer.o app