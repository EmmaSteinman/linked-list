all:  main1 main2 main3

main1: testMain1.o Complex.o
	g++ -std=c++11 -Wall -o main1 testMain1.o Complex.o

main2: testMain2.o Complex.o
	g++ -std=c++11 -Wall -o main2 testMain2.o Complex.o

main3: testMain3.o Complex.o
	g++ -std=c++11 -Wall -o main3 testMain3.o Complex.o

testMain1.o: testMain1.cpp Complex.h
	g++ -std=c++11 -Wall -c testMain1.cpp

testMain2.o: testMain2.cpp Complex.h
	g++ -std=c++11 -Wall -c testMain2.cpp

testMain3.o: testMain3.cpp Complex.h
	g++ -std=c++11 -Wall -c testMain3.cpp

Complex.o: Complex.cpp Complex.h
	g++ -std=c++11 -Wall -c Complex.cpp
