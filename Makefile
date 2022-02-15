# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 12:20:29 by hboumahd          #+#    #+#              #
#    Updated: 2022/02/15 16:11:20 by hboumahd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC_FOLDER = ./code/
FT_PRINTF_FOLDER = ./code/ft_printf
GET_NEXT_LINE_FOLDER = ./code/get_next_line

SRC = so_long.c 

SRCS = $(addprefix $(SRC_FOLDER), $(SRC))

SRCOBJ = ${SRCS:.c=.o}

PRINTF  = ./code/printf.a
GET_NEXT_LINE = ./code/get_next_line.a


INCLUDE1 = ./code/so_long.h
INCLUDE2 = ./code/ft_printf/ft_printf.h  
INCLUDE3 = ./code/get_next_line/get_next_line.h 

CC = cc 

FLAGS = -Wall -Wextra -Werror

%.o : %.c ${INCLUDE1} ${INCLUDE2} ${INCLUDE3}
	@$(MAKE) -C $(FT_PRINTF_FOLDER)
	@$(MAKE) -C $(GET_NEXT_LINE_FOLDER)
	$(CC) ${FLAGS} -Imlx -c $< -o $@
	@echo "make the printf.a" 
	@echo "make the get_next_line.a" 
	

$(NAME) : ${SRCOBJ}
	@$(CC) $(SRCOBJ) $(PRINTF) $(GET_NEXT_LINE) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "make the so_long program"

all : $(NAME)  

clean :
	@rm -f ./code/*.a ./code/*.o ./code/ft_printf/*.o ./code/get_next_line/*.o

fclean : clean
	@rm -f ${NAME} so_long

re : fclean all
