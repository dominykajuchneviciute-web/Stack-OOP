all: demo

stack.o: Stack.cpp Stack.h
	g++ -c Stack.cpp

demo: demo.cpp stack.o
	g++ demo.cpp stack.o -o demo

run:
	./demo

test: test.cpp stack.o
	g++ test.cpp stack.o -o test

runtest:
	./test

clean:
	rm -f *.o demo test

rebuild: clean all