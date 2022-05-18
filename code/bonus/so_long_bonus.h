/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:26:38 by hboumahd          #+#    #+#             */
/*   Updated: 2022/05/18 11:51:46 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H

# define SO_LONG_BONUS_H
# include "mlx.h"
# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"

# define KEY_ESC	53
# define KEY_W	13
# define KEY_S	1
# define KEY_A	0
# define KEY_D	2

# define KEY_Q	12
# define KEY_E	14
# define KEY_R	15

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
}	t_map;

typedef struct s_img
{
	void	*img_player;
	void	*img_coin;
	void	*img_grass;
	void	*img_dor;
	void	*img_wall;
	void	*img_boss;
}	t_img;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_map	*obj_map;
	t_img	*obj_img;
	int		move_num;
	int		counter;
}	t_game;

void	ft_map_dimensions(char *map_path, t_map *obj_map);
char	**ft_map_init(char *map_path, t_map *obj_map);
void	ft_map_checker(t_map *obj_map);
void	ft_move_up(t_game *obj_game);
void	ft_move_down(t_game *obj_game);
void	ft_move_right(t_game *obj_game);
void	ft_move_left(t_game *obj_game);
void	ft_drawer_init(t_game *obj_game, t_img *obj_img);
void	ft_game_drawer(t_map *obj_map, t_game *obj_game, t_img *obj_img);
int		ft_animate(void *obj_gam);

#endif