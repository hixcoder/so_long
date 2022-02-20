/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:58:45 by hboumahd          #+#    #+#             */
/*   Updated: 2022/02/20 10:21:34 by hboumahd         ###   ########.fr       */
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

typedef struct s_map
{
	char	**map;
	int		map_width;
	int		map_height;
	int		exit_num;
	int		coin_num;
	int		plyr_num;
	int		plyr_x;
	int		plyr_y;
}	s_map;

typedef struct s_img
{
	int     img_size;
	void	*img_player;
	void	*img_coin;
	void	*img_grass;
	void	*img_dors_close;
	void	*img_dors_open;
	void	*img_wall;
} s_img;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	s_map	*obj_map;
	s_img 	*obj_img;
	int		move_num;
} s_game;

void    ft_map_dimensions(char *map_path, s_map *obj_map);
char	**ft_map_init(char *map_path, s_map *obj_map);
void    ft_map_checker(s_map *obj_map);
void    ft_move_up(s_game *obj_game);
void    ft_move_down(s_game *obj_game);
void    ft_move_right(s_game *obj_game);
void    ft_move_left(s_game *obj_game);
void	ft_drawer_init(s_game *obj_game, s_img *obj_img);
void	ft_game_drawer(s_map *obj_map, s_game *obj_game, s_img *obj_img);

#endif 