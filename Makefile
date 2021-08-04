
CFLAGS=-Wc++11-extensions -lncurses -std=gnu++11  -stdlib=libc++

run:
	g++ $(CFLAGS) -c main.cpp
	g++ $(CFLAGS) main.o -o ql.run
	make clean
	./ql.run


clean:
	rm -rf *.o *.gch ql


test:
	g++ $(CFLAGS) -c keyinput.cpp
	g++ $(CFLAGS) keyinput.o -o k.run
	make clean
	./k.run