# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oszwalbe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/03 15:19:16 by oszwalbe          #+#    #+#              #
#    Updated: 2023/11/23 14:44:20 by oszwalbe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
HEAD = libft.h
SOURCES = ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
ft_memcpy.c ft_memset.c ft_strlen.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c \
ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_substr.c ft_strdup.c \
ft_strjoin.c ft_strtrim.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
ft_putendl_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_split.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
SOURCESALL = ${SOURCES} ${BONUS}
OBJETS = ${SOURCES:.c=.o}
OBJETSALL = ${SOURCESALL:.c=.o}

.c.o:
	${CC} ${CFLAGS} -I ${HEAD} -c $< -o ${<:.c=.o}

${NAME}: ${OBJETS}
	ar -rsc ${NAME} ${OBJETS}

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SOURCES)
	gcc -nostartfiles -shared -o libft.so $(OBJETS)

bonus: ${OBJETSALL}
	ar -rsc ${NAME} ${OBJETSALL}

all: ${NAME}

clean:
	rm -f ${OBJETSALL}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus
