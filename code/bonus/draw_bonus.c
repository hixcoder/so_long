/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 20:53:04 by hboumahd          #+#    #+#             */
/*   Updated: 2022/05/18 12:53:59 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_drawer_init(t_game *obj_game, t_img *obj_img)
{
	int		s;
	void	*p;

	s = 50;
	p = obj_game->mlx_ptr;
	obj_img->img_wall = mlx_xpm_file_to_image(p, "./assets/wall.xpm", &s, &s);
	obj_img->img_grass = mlx_xpm_file_to_image(p, "./assets/grass.xpm", &s, &s);
	obj_img->img_coin = mlx_xpm_file_to_image(p, "./assets/coin.xpm", &s, &s);
	obj_img->img_player = mlx_xpm_file_to_image(p, "./assets/plyr.xpm", &s, &s);
	obj_img->img_dor = mlx_xpm_file_to_image(p, "./assets/dors.xpm", &s, &s);
	obj_img->img_boss = mlx_xpm_file_to_image(p, "./assets/boss_0.xpm", &s, &s);
}

void	ft_put_image(t_game *obj_game, void	*img, int i, int j)
{
	void	*w;
	void	*p;

	w = obj_game->win_ptr;
	p = obj_game->mlx_ptr;
	mlx_put_image_to_window(p, w, img, j * 50, i * 50 + 50);
}

void	ft_moves_nbr(t_map *obj_map, t_game *obj_game)
{
	char *text;
	int x;
	int y;
	
	x = obj_map->map_width / 2;
	y = obj_map->map_height;
	text = ft_strjoin("Number of moves : ",ft_itoa(obj_game->move_num));
	mlx_string_put(obj_game->mlx_ptr,obj_game->win_ptr,x,y,0xABCDEF,text);
}

void	ft_game_drawer(t_map *obj_map, t_game *obj_game, t_img *obj_img)
{
	int		i;
	int		j;
	char	**map;

	map = obj_map->map;
	i = -1;
	while (++i < obj_map->map_height)
	{
		j = -1;
		while (++j < obj_map->map_width)
		{
			ft_put_image(obj_game, obj_img->img_grass, i, j);
			if (obj_map->map[i][j] == '1')
				ft_put_image(obj_game, obj_img->img_wall, i, j);
			else if (obj_map->map[i][j] == '0')
				ft_put_image(obj_game, obj_img->img_grass, i, j);
			else if (obj_map->map[i][j] == 'C')
				ft_put_image(obj_game, obj_img->img_coin, i, j);
			else if (obj_map->map[i][j] == 'P')
				ft_put_image(obj_game, obj_img->img_player, i, j);
			else if (obj_map->map[i][j] == 'E')
				ft_put_image(obj_game, obj_img->img_dor, i, j);
			else if (obj_map->map[i][j] == 'B')
				ft_put_image(obj_game, obj_img->img_boss, i, j);
		}
	}
	ft_moves_nbr(obj_map, obj_game);
}
