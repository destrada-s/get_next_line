SRCS =	get_next_line.c \
		get_next_line_utils.c \
		main.c

OBJS = $(SRCS:.c=.o)

AR = ar -rcs

CC = gcc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

NAME = nextline.a

NAME_PROG = main

all: $(NAME)

$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS)
			$(CC) $(CFLAGS) main.c $(NAME) -o $(NAME_PROG)

clean:
	$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME) $(NAME_PROG)

re: fclean all

.PHONY: all clean fclean re