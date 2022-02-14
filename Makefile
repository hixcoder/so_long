# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hboumahd <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 12:20:29 by hboumahd          #+#    #+#              #
#    Updated: 2022/02/14 12:20:49 by hboumahd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

# BONUS= ./bonus

SRC = main.c

SRCOBJ = ${SRC:.c=.o}
FT_PRINTF = ft_printf

# INCLUDE2 = so_long.h

CC = cc 

FLAGS = -Wall -Wextra -Werror

%.o : %.c 
	$(MAKE) -C $(FT_PRINTF)
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME) : ${SRCOBJ}
	$(CC) $(SRCOBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all : $(NAME)  

clean :
	@rm -f *.o

fclean : clean
	@rm -f ${NAME} 

re : fclean all
