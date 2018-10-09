run: main.o student.o ta.o
	gcc -pthread main.o student.o ta.o -o run
main.o: main.c
	gcc -c main.c
student.o: student.c student.h
	gcc -c student.c
ta.o: ta.c ta.h
	gcc -c ta.c
clean:
	rm *.o run
