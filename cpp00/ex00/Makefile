CC = c++
FLAGS = -Wall -Wextra -Werror
SRCS = megaphone.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = megaphone

%.o:%.c
	$(CC) $(FLAGS) $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $@ $(OBJS)

all:$(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean 

.PHONY : all clean fclean re
