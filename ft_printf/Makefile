# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hboumahd <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/27 14:29:53 by hboumahd          #+#    #+#              #
#    Updated: 2021/11/27 14:29:57 by hboumahd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c ft_putchar.c ft_putnbr_base.c ft_putstr.c ft_putnbr_base2.c ft_putnbr.c

SRCOBJ = ${SRC:.c=.o}

INCLUDE = ft_printf.h  

CC = cc 

FLAGS = -Wall -Wextra -Werror



%.o : %.c ${INCLUDE}
	${CC} ${FLAGS} -c $< -o $@

$(NAME) : ${SRCOBJ} 
	ar rcs ${NAME} ${SRCOBJ} 

all : $(NAME)

clean :
	rm -f ${SRCOBJ}

fclean : clean
	rm -f ${NAME}

re : fclean all
