CC = g++
CFLAGS = -std=c++98 -Wall -Wextra

SRCS = main.cpp hash.cpp
OBJS = $(SRCS:.cpp=.o)
EXEC = main

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC)

main.o: main.cpp hash.h
	$(CC) $(CFLAGS) -c main.cpp

hash.o: hash.cpp hash.h
	$(CC) $(CFLAGS) -c hash.cpp

clean:
	rm -f $(OBJS) $(EXEC)
