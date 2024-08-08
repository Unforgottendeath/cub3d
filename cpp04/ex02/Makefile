CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address

SRCS = main.cpp \
		Dog.cpp \
		Cat.cpp \
		AAnimal.cpp \
		Brain.cpp

NAME = Animal

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re