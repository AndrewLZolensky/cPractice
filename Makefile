all: app

app: app.o customer.o
	cc app.o customer.o -o app

app.o: app.c customer.h
	cc -c app.c -o app.o

customer.o: customer.c customer.h
	cc -c customer.c -o customer.o

clean:
	rm -f app.o customer.o app