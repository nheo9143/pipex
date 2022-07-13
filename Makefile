NAME = pipex
SRCS = main.c \
		util.c \
		ft_error.c \
		ft_split.c \
		ft_strjoin.c \
		parse.c \
		process.c

HDRS = headers

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror -g

all : $(NAME)

$(NAME) :$(OBJS)
	cc -o $(NAME) $(OBJS)

clean :
	rm -f $(OBJS) $(BONUS_OBJS)

fclean :
	make clean
	rm -f $(NAME) $(BONUS_OBJS)

re :
	make fclean
	make all

.PHONY : clean fclean re all