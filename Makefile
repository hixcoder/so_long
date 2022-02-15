# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 12:20:29 by hboumahd          #+#    #+#              #
#    Updated: 2022/02/15 13:29:32 by hboumahd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

# BONUS= ./bonus
SRC_FOLDER = ./code/
FT_PRINTF_FOLDER = ./code/ft_printf

SRC = so_long.c 

SRCS = $(addprefix $(SRC_FOLDER), $(SRC))

SRCOBJ = ${SRCS:.c=.o}
LIBFT_PRINTF  = ./code/libftprintf.a


INCLUDE1 = ./code/so_long.h
INCLUDE2 = ./code/ft_printf/ft_printf.h  

CC = cc 

FLAGS = -Wall -Wextra -Werror

%.o : %.c ${INCLUDE1} ${INCLUDE2}
	@$(MAKE) -C $(FT_PRINTF_FOLDER)
	$(CC) ${FLAGS} -Imlx -c $< -o $@
	@echo "make the libftprintf.a" 
	

$(NAME) : ${SRCOBJ}
	@$(CC) $(SRCOBJ) $(LIBFT_PRINTF) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "make the so_long program"

all : $(NAME)  

clean :
	@rm -f $(LIBFT_PRINTF) ./code/*.o ./code/ft_printf/*.o 

fclean : clean
	@rm -f ${NAME} so_long

re : fclean all
