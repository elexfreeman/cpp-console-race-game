
CFLAGS=-Wc++11-extensions -lncurses -std=gnu++11  -stdlib=libc++

run:
	g++ $(CFLAGS) -c main.cpp
	g++ $(CFLAGS) main.o -o ql.run
	make clean
	./ql.run


clean:
	rm -rf *.o *.gch ql


test:
	g++ $(CFLAGS) -c test.cpp
	#g++ $(CFLAGS) -c AIHeaders.h
	#g++ $(CFLAGS) -c AIEqual.h 
	#g++ $(CFLAGS) -c AICtrl.h
	g++ $(CFLAGS) test.o  -o test.run
	make clean
	./test.run