/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 20:53:04 by hboumahd          #+#    #+#             */
/*   Updated: 2022/02/20 10:20:46 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_drawer_init(s_game *obj_game, s_img *obj_img)
{
	obj_img->img_size = 50;
	obj_img->img_wall = mlx_xpm_file_to_image(obj_game->mlx_ptr, "./assets/wall.xpm", &obj_img->img_size, &obj_img->img_size);
	obj_img->img_grass = mlx_xpm_file_to_image(obj_game->mlx_ptr, "./assets/grass.xpm", &obj_img->img_size, &obj_img->img_size);
	obj_img->img_coin = mlx_xpm_file_to_image(obj_game->mlx_ptr, "./assets/coin.xpm", &obj_img->img_size, &obj_img->img_size);
	obj_img->img_player = mlx_xpm_file_to_image(obj_game->mlx_ptr, "./assets/player.xpm", &obj_img->img_size, &obj_img->img_size);
	obj_img->img_dors_close = mlx_xpm_file_to_image(obj_game->mlx_ptr, "./assets/dors_close.xpm", &obj_img->img_size, &obj_img->img_size);
    obj_img->img_dors_open = mlx_xpm_file_to_image(obj_game->mlx_ptr, "./assets/dors_open.xpm", &obj_img->img_size, &obj_img->img_size);
		
}

void	ft_game_drawer(s_map *obj_map, s_game *obj_game, s_img *obj_img)
{
	int i;
	int j;
	char **map;

	map = obj_map->map;
	i = -1;
	while(++i < obj_map->map_height)
	{
		j = -1;
		while(++j < obj_map->map_width)
		{	
			mlx_put_image_to_window(obj_game->mlx_ptr, obj_game->win_ptr, obj_img->img_grass, j * 50, i * 50);
			if (obj_map->map[i][j] == '1')
				mlx_put_image_to_window(obj_game->mlx_ptr, obj_game->win_ptr, obj_img->img_wall, j * 50, i * 50);
			else if (obj_map->map[i][j] == '0')
				mlx_put_image_to_window(obj_game->mlx_ptr, obj_game->win_ptr, obj_img->img_grass, j * 50, i * 50);
			else if (obj_map->map[i][j] == 'C')
				mlx_put_image_to_window(obj_game->mlx_ptr, obj_game->win_ptr, obj_img->img_coin, j * 50, i * 50);
			else if (obj_map->map[i][j] == 'P')
				mlx_put_image_to_window(obj_game->mlx_ptr, obj_game->win_ptr, obj_img->img_player, j * 50, i * 50);
			else if (obj_map->map[i][j] == 'E')
                mlx_put_image_to_window(obj_game->mlx_ptr, obj_game->win_ptr, obj_img->img_dors_open, j * 50, i * 50);
		}
	}
}