bank: main.o account.o treeops.o
	gcc main.o account.o treeops.o -o bank

main.o: main.c
	gcc -c main.c

account.o: account.c account.h
	gcc -c account.c

treeops.o: treeops.c treeops.h
	gcc -c treeops.c

clean:
	rm -f *.o
	rm bank