# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvalenti <lvalenti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/03 18:18:59 by lvalenti          #+#    #+#              #
#    Updated: 2017/04/03 18:19:02 by lvalenti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC =	ft_abs.c\
		ft_strequ.c\
		ft_strisdigit.c\
		ft_strnequ.c\
		ft_atoi.c\
		ft_bzero.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isfolder.c\
		ft_isprint.c\
		ft_itoa.c\
		ft_memalloc.c\
		ft_memccpy.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memcpy.c\
		ft_memdel.c\
		ft_memmove.c\
		ft_memset.c\
		ft_putchar.c\
		ft_putchar_fd.c\
		ft_putendl.c\
		ft_putendl_fd.c\
		ft_putnbr.c\
		ft_putnbr_fd.c\
		ft_putstr.c\
		ft_putstr_fd.c\
		ft_strcat.c\
		ft_strchr.c\
		ft_strclr.c\
		ft_strcmp.c\
		ft_strcpy.c\
		ft_strdel.c\
		ft_strdup.c\
		ft_striter.c\
		ft_striteri.c\
		ft_strjoin.c\
		ft_strlcat.c\
		ft_strlen.c\
		ft_strmap.c\
		ft_strmapi.c\
		ft_strncat.c\
		ft_strncmp.c\
		ft_strncpy.c\
		ft_strnew.c\
		ft_strnstr.c\
		ft_strrchr.c\
		ft_strsplit.c\
		ft_strstr.c\
		ft_strsub.c\
		ft_strtrim.c\
		ft_tolower.c\
		ft_toupper.c\
		ft_strswitch.c\
		ft_strrev.c\
		ft_putmap.c\
		ft_pow.c\
		ft_lstnew.c\
		ft_lstmap.c\
		ft_lstiter.c\
		ft_lstdelone.c\
		ft_lstdel.c\
		ft_lstadd.c\
		ft_isspace.c\
		ft_swap.c\
		ft_strnchr.c\
		ft_triplestr.c\
		ft_biggest.c\
		ft_smallest.c\
		ft_strlenchr.c\
		libstrstr.c\
		ft_freejoin.c\
		ft_strstrlen.c

OBJS = $(SRC:.c=.o)
CFLAGS= -g -Wall -Werror -Wextra
CC = gcc

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -c $(SRC) -I ./
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
