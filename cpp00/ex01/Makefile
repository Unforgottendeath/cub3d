CC = c++
FLAGS = -Wall -Wextra -Werror
SRCS = phonebook.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = phonebook

%.o:%.c
	$(CC) $(FLAGS) $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $@ $(OBJS)

all:$(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all 

.PHONY : all clean fclean re
