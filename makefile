

C = g++
CCFLAGS = -Wall -Werror   -g

main: main.cpp
	 $(CC) $(CCFLAGS) -c -o main main.cpp