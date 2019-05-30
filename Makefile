movieSelect: movieSelect.cpp 
	g++ -Wall -Werror -pedantic -O1  movieSelect.cpp -o movieSelect
	
functionTesting: functionTesting.cpp
	g++ -Wall -Werror -pedantic -O1  functionTesting.cpp -o functionTesting

clean: movieSelect.o functionTesting.o
	rm -f movieSelect movieSelect.o functionTesting.o functionTesting