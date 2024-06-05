NAME = cub3d
CC = cc
SRCS_COMMON = srcs/utils/utils_1.c \
			  srcs/utils/utils_2.c \
			  srcs/utils/utils_3.c \
			  srcs/utils/utils_4.c \
			  srcs/parsing/parsing.c \
			  srcs/upload_content/upload_struct.c \
			  srcs/utils/utils_5.c \
			  srcs/utils/utils_6.c \
			  srcs/utils/utils_7.c
SRCS = cub3d.c $(SRCS_COMMON)
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -c $< -o $@ 
$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) 

fclean: clean
	$(RM) $(NAME) 

clean:
	rm -f $(OBJS) 

re: fclean all

.PHONY: all clean fclean re 

