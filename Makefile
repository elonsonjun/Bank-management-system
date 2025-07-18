all: bank

bank: main.o account.o bank.o auth.o transaction.o utils.o
	g++ -o bank main.o account.o bank.o auth.o transaction.o utils.o

%.o: %.cpp
	g++ -c $<

clean:
	rm -f *.o bank