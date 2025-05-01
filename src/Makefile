CC = gcc
CFLAGS = -I. 
DEPS= stack.h # queue.h
OBJ = main.o include/stack.o
LIBS= stack
NAME=main

run: $(NAME)
	./$(NAME)

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(NAME): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean: 
	rm -rf include/*.o *.o $(NAME)
