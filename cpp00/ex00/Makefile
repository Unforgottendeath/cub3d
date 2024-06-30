CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = megaphone.cpp

NAME = megaphone

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re