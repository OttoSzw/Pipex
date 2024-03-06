
NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = pipex_bonus.c utils.c utils2.c utils_bonus.c
OBJS = ${SRCS:.c=.o}
LIBFTDIR = libft
LIBFTPATH = libft/libft.a


.c.o:
		${CC} ${CFLAGS} -g3 -c $< -o ${<:.c=.o}

${NAME}: ${OBJS} ${LIBFTPATH}
			${CC} ${CFLAGS} ${OBJS} -L ${LIBFTDIR} -lft -o ${NAME}

${LIBFTPATH}:
				make -C ${LIBFTDIR}

all: ${NAME}

clean:
		make -C ${LIBFTDIR} clean
		rm -f ${OBJS}

fclean: clean
		make -C ${LIBFTDIR} fclean
		rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re