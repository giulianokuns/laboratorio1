

C = g++
CCFLAGS = -Wall -Werror   -g

main2: main2.cpp
	 $(CC) $(CCFLAGS) -c -o main main2.cpp