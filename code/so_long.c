/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 20:07:18 by hboumahd          #+#    #+#             */
/*   Updated: 2022/02/17 18:17:00 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int deal_key(int key, void *param){
	if(key == KEY_ESC)
		exit(0);
	ft_printf("the key is : %d\n", key);
	param = 0;
	return (0);
}

void ft_draw_obj(char *relative_path, s_game *obj_game, int i, int j)
{
	int		img_width = 50;
	int		img_height = 50;
	void	*img;

	img = mlx_xpm_file_to_image(obj_game->mlx_ptr, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(obj_game->mlx_ptr, obj_game->win_ptr, img, j * 50, i * 50);
}

void	ft_drawer_game(s_map *obj_map, s_game *obj_game)
{
	int i;
	int j;
	char **map;

	i = -1;
	map = obj_map->map;
	while(i++ < obj_map->map_width)
	{
		j = -1;
		while(++j < obj_map->map_height)
		{
			if(map[i][j] == '1')
				ft_draw_obj("assets/wall.xpm", obj_game, i, j);
			else if(map[i][j] == '0')
				ft_draw_obj("assets/grass.xpm", obj_game, i, j);
			else if(map[i][j] == 'C')
				ft_draw_obj("assets/coin.xpm", obj_game, i, j);
			else if(map[i][j] == 'P')
				ft_draw_obj("assets/player.xpm", obj_game, i, j);
			else if(map[i][j] == 'E')
				ft_draw_obj("assets/dors_close.xpm", obj_game, i, j);
		}
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		
		s_game	obj_game;
		s_map	obj_map;

		int i;
		int j;


		void	*img1;
		void	*img2;
		void	*img3;
		void	*img4;
		void	*img5;
		int		img_size;
		
		ft_map_dimensions(av[1], &obj_map);
		obj_map.map = ft_map_init(av[1], &obj_map);
		// ft_map_checker(&obj_map);

		// test
		ft_printf("width = %d, height = %d\n", obj_map.map_width, obj_map.map_height);
		for (int i1 = 0; i1 < obj_map.map_height; i1++)
		{
			for (int i2 = 0; i2 < obj_map.map_width; i2++)
				ft_printf("%c", obj_map.map[i1][i2]);
			ft_printf("\n");
		}
		
		obj_game.mlx_ptr = mlx_init();
		obj_game.win_ptr = mlx_new_window(obj_game.mlx_ptr, obj_map.map_width * 50, obj_map.map_height * 50,"hello world");
		
		img_size = 50;

		i = -1;
		while(++i < obj_map.map_height)
		{
			j = -1;
			while(++j < obj_map.map_width)
			{	
				if (obj_map.map[i][j] == '1')
				{
					img1 = mlx_xpm_file_to_image(obj_game.mlx_ptr, "./assets/wall.xpm", &img_size, &img_size);
					mlx_put_image_to_window(obj_game.mlx_ptr, obj_game.win_ptr, img1, j * 50, i * 50);
				}
				else if (obj_map.map[i][j] == '0')
				{
					img2 = mlx_xpm_file_to_image(obj_game.mlx_ptr, "./assets/grass.xpm", &img_size, &img_size);
					mlx_put_image_to_window(obj_game.mlx_ptr, obj_game.win_ptr, img2, j * 50, i * 50);
				}
				else if (obj_map.map[i][j] == 'C')
				{
					img3 = mlx_xpm_file_to_image(obj_game.mlx_ptr, "./assets/coin.xpm", &img_size, &img_size);
					mlx_put_image_to_window(obj_game.mlx_ptr, obj_game.win_ptr, img3, j * 50, i * 50);
				}
				else if (obj_map.map[i][j] == 'P')
				{
					img4 = mlx_xpm_file_to_image(obj_game.mlx_ptr, "./assets/player.xpm", &img_size, &img_size);
					mlx_put_image_to_window(obj_game.mlx_ptr, obj_game.win_ptr, img4, j * 50, i * 50);
				}
				else if (obj_map.map[i][j] == 'E')
				{
					img5 = mlx_xpm_file_to_image(obj_game.mlx_ptr, "./assets/dors_close.xpm", &img_size, &img_size);
					mlx_put_image_to_window(obj_game.mlx_ptr, obj_game.win_ptr, img5, j * 50, i * 50);
				}
			}
		}
		mlx_key_hook(obj_game.win_ptr, deal_key, &obj_game);

		mlx_loop(obj_game.mlx_ptr);
	}
	else
		ft_printf("Please enter : ./so_long [code/maps/mapx.ber]\n");
	
}
