all:
	g++ -O3 -c -fpic conv.cpp -o conv.o
	g++ -O3 -shared -fpic conv.o -o libconv.so