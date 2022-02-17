/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:58:45 by hboumahd          #+#    #+#             */
/*   Updated: 2022/02/17 05:07:04 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H
# include "mlx.h"
# include "./ft_printf/ft_printf.h"
# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"

#define KEY_ESC	53
#define KEY_W	13
#define KEY_S	1
#define KEY_A	0
#define KEY_D	2

#define KEY_Q	12
#define KEY_E	14
#define KEY_R	15

typedef struct s_game
{
    void	*mlx_ptr;
    void	*win_ptr;
} s_game;

typedef struct s_map
{
    char    **map;
    int     map_width;
    int     map_height;
	int	    E_num;
	int	    C_num;
	int 	P_num;
} s_map;

typedef struct s_element
{
    int     img_width;
    int     img_height;
    char    *relative_path;
    void	*img;
} s_element;

void    ft_map_dimensions(char *map_path, s_map *obj_map);
char	**ft_map_init(char *map_path, s_map *obj_map);
void    ft_map_checker(s_map *obj_map);

#endif 