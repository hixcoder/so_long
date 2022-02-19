/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 20:07:18 by hboumahd          #+#    #+#             */
/*   Updated: 2022/02/19 16:03:59 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// stoped here
// I have two errors:
// parse big maps 
// hoe to move the player


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
	int		x;
	int		y;

	obj_game = (s_game *) obj_gam;
	map = obj_game->obj_map->map;
	x = obj_game->obj_map->plyr_x;
	y = obj_game->obj_map->plyr_y;	
	if(key == KEY_ESC)
		exit(0);
	else if(key == KEY_W){
		ft_printf("map[y][x]\n\n");
		ft_printf("map[%d][%d] = %c\n",x,y,map[x][y]);
		map[y][x] = '0';
		ft_printf("map[%d][%d] = %c\n\n",x,y,map[x][y]);
		ft_printf("map[%d - 1][%d] = %c\n",x,y,map[x - 1][y]);
		map[y - 1][x] = 'P';
		ft_printf("map[%d - 1][%d] = %c\n",x,y,map[x - 1][y]);
		ft_game_drawer(obj_game->obj_map, obj_game, obj_game->obj_img);
	}
		
	// ft_printf("the key is : %d\n", key);
	
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

		obj_game.obj_map = &obj_map;
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


		// test
		// ft_printf("width = %d, height = %d\n", obj_map.map_width, obj_map.map_height);
		// for (int i1 = 0; i1 < obj_map.map_height; i1++)
		// {
		// 	for (int i2 = 0; i2 < obj_map.map_width; i2++)
		// 		ft_printf("%c", obj_map.map[i1][i2]);
		// 	ft_printf("\n");
		// }