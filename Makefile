bank: main.o treeops.o account.o bankops.o
	gcc main.o treeops.o account.o bankops.o -o bank

main.o: main.c
	gcc -c main.c

treeops.o: treeops.c treeops.h
	gcc -c treeops.c

account.o: account.c account.h
	gcc -c account.c

bankops.o: bankops.c bankops.h
	gcc -c bankops.c

clean:
	rm -f *.o
	rm bank
