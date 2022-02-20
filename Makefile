# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 12:20:29 by hboumahd          #+#    #+#              #
#    Updated: 2022/02/20 13:14:07 by hboumahd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC_FOLDER = ./code/
FT_PRINTF_FOLDER = ./code/ft_printf
GET_NEXT_LINE_FOLDER = ./code/get_next_line
LIBFT_FOLDER = ./code/libft

SRC = so_long.c map.c map_check.c move.c draw.c

SRCS = $(addprefix $(SRC_FOLDER), $(SRC))

SRCOBJ = ${SRCS:.c=.o}

OTHER_FOLDER = ./code/**/
OTHERS = *.c
OTHEROBJ = $(addprefix $(OTHER_FOLDER), $(OTHERS))

PRINTF  = ./code/printf.a
GET_NEXT_LINE = ./code/get_next_line.a
LIBFT = ./code/libft.a


INCLUDE1 = ./code/so_long.h
INCLUDE2 = ./code/ft_printf/ft_printf.h  
INCLUDE3 = ./code/get_next_line/get_next_line.h 
INCLUDE4 = ./code/libft/libft.h 

CC = cc 

# -g for the debugger
FLAGS = -Wall -Wextra -Werror 

%.o : %.c ${INCLUDE1} ${INCLUDE2} ${INCLUDE3} ${INCLUDE4}
	$(CC) ${FLAGS} -Imlx -c $< -o $@
	
$(NAME) : ${SRCOBJ} $(OTHEROBJ)
	@$(MAKE) -C $(FT_PRINTF_FOLDER)
	@$(MAKE) -C $(GET_NEXT_LINE_FOLDER)
	@$(MAKE) -C $(LIBFT_FOLDER)
	@echo "make the so_long program"
	@echo "make the printf.a" 
	@echo "make the get_next_line.a"
	@echo "make the libft.a"
	@$(CC) $(SRCOBJ) $(PRINTF) $(GET_NEXT_LINE) $(LIBFT) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all : $(NAME)  

clean :
	@rm -f ./code/*.a ./code/*.o ./code/ft_printf/*.o ./code/get_next_line/*.o ./code/libft/*.o

fclean : clean
	@rm -f ${NAME} so_long

re : fclean all
