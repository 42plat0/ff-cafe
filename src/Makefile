CC = gcc
CFLAGS = -I. 
NAME=main

DEPS_DIR = include/
DEPS= stack queue config sandwich dispenser cafe

DEPS_H = $(addsufix .h, $(DEPS))
DEPS_IN_DIR = $(addprefix $(DEPS_DIR), $(DEPS))
OBJ = $(addsuffix .o, $(NAME) $(DEPS_IN_DIR))

run: $(NAME)
	./$(NAME)

%.o: %.c $(DEPS_H)
	$(CC) -c -o $@ $< $(CFLAGS)

$(NAME): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean: 
	rm -rf $(OBJ) $(NAME)
