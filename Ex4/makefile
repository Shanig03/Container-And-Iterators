# Email: shanig7531@gmail.com

CXX = clang++
CXXFLAGS = -std=c++17 -Wall -Wextra -g
INCLUDES = -I./src

all: Main test

main: main.o
	$(CXX) $(CXXFLAGS) -o main main.o

main.o: src/main.cpp src/MyContainer.hpp src/AscendingOrderIterator.hpp src/DescendingOrderIterator.hpp src/SideCrossOrderIterator.hpp src/ReverseOrderIterator.hpp src/OrderIterator.hpp src/MiddleOutOrderIterator.hpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c src/main.cpp -o main.o

Main: main
	./main

test: TestRunner
	./TestRunner

TestRunner: Tests/tests.cpp src/MyContainer.hpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o TestRunner Tests/tests.cpp

valgrind: main TestRunner
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./main

clean:
	rm -f *.o Main TestRunner main

.PHONY: all clean test run valgrind