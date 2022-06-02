target:	hw

main: main.cpp
	g++ -std=c++11 -c main.cpp

hw:	main
	g++ -std=c++11 main.cpp -o hw

run: 
	./hw

clean:
	rm hw *.o
