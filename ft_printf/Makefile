#Variables

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

#Sources et Objects

SRCS = ft_printf.c \
		ft_print_char.c \
		ft_putnbr_base.c

OBJS = ${SRCS:.c=.o}

#Rules

all: ${NAME}

${NAME}: ${OBJS}
	@${AR} ${NAME} ${OBJS}

.c.o:
	@${CC} ${CFLAGS} -c $< -o $@

clean: 
	@rm -rf ${OBJS} ${BONUS_OBJS}

fclean: clean
	@rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean bonus re
