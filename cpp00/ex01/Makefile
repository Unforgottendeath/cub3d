CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = phonebook.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = phonebook

%.o:%.c
	c++ -Wall -Wextra -Werror -std=c++98 -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $@ $(OBJS)

all:$(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all 

.PHONY : all clean fclean re
