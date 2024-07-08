CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address

SRCS = main.cpp \
		Fixed.cpp \
		Point.cpp \
		bsp.cpp

NAME = Point

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re