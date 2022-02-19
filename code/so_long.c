/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 20:07:18 by hboumahd          #+#    #+#             */
/*   Updated: 2022/02/19 20:06:00 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
				mlx_put_image_to_window(obj_game->mlx_ptr, obj_game->win_ptr, obj_img->img_dors_close, j * 50, i * 50);
		}
	}
}

int deal_key(int key, void *obj_gam){
	s_game	*obj_game;
	char	**map;
	
	obj_game = (s_game *) obj_gam;
	map = obj_game->obj_map->map;
	mlx_clear_window(obj_game->mlx_ptr, obj_game->win_ptr);
	
	if(key == KEY_ESC)
		exit(0);
	else if(key == KEY_W)
		ft_move_up(obj_game);
	else if(key == KEY_S)
		ft_move_down(obj_game);
	else if(key == KEY_A)
		ft_move_left(obj_game);
	else if(key == KEY_D)
		ft_move_right(obj_game);
	
	ft_game_drawer(obj_game->obj_map, obj_game, obj_game->obj_img);
	
	
	return (0);
}


void	ft_drawer_init(s_game *obj_game, s_img *obj_img)
{
	obj_img->img_size = 50;
	obj_img->img_wall = mlx_xpm_file_to_image(obj_game->mlx_ptr, "./assets/wall.xpm", &obj_img->img_size, &obj_img->img_size);
	obj_img->img_grass = mlx_xpm_file_to_image(obj_game->mlx_ptr, "./assets/grass.xpm", &obj_img->img_size, &obj_img->img_size);
	obj_img->img_coin = mlx_xpm_file_to_image(obj_game->mlx_ptr, "./assets/coin.xpm", &obj_img->img_size, &obj_img->img_size);
	obj_img->img_player = mlx_xpm_file_to_image(obj_game->mlx_ptr, "./assets/player.xpm", &obj_img->img_size, &obj_img->img_size);
	obj_img->img_dors_close = mlx_xpm_file_to_image(obj_game->mlx_ptr, "./assets/dors_close.xpm", &obj_img->img_size, &obj_img->img_size);
		
}

int main(int ac, char **av)
{
	if (ac == 2)
	{	
		s_game	obj_game;
		s_map	obj_map;
		s_img	obj_img;
		
		obj_map.map = ft_map_init(av[1], &obj_map);
		ft_map_checker(&obj_map);
		obj_game.move_num = 0;

		obj_game.obj_map = &obj_map;
		obj_game.obj_img = &obj_img;
		obj_game.mlx_ptr = mlx_init();
		obj_game.win_ptr = mlx_new_window(obj_game.mlx_ptr, obj_map.map_width * 50, obj_map.map_height * 50,"Solo leveling");
		
		ft_drawer_init(&obj_game, &obj_img);
		ft_game_drawer(&obj_map, &obj_game, &obj_img);
		
		mlx_key_hook(obj_game.win_ptr, deal_key, &obj_game);
		mlx_loop(obj_game.mlx_ptr);
	}
	else
		ft_printf("Please enter : ./so_long [code/maps/mapx.ber]\n");
}