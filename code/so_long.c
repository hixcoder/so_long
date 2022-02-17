/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 20:07:18 by hboumahd          #+#    #+#             */
/*   Updated: 2022/02/17 01:27:07 by hboumahd         ###   ########.fr       */
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

int main(int ac, char **av)
{

	if (ac == 2){
		
		s_game	obj_game;
		s_map	obj_map;
		int i;
		int j;
		
		char	*relative_path = "./assets/player.xpm";
		int		img_width = 50;
		int		img_height = 50;
		void	*img;
		
		
		
		ft_map_dimensions(av[1], &obj_map);
		ft_printf("width = %d, height = %d\n", obj_map.map_width, obj_map.map_height);
		obj_map.map = ft_map_init(av[1], &obj_map);
		for (int i1 = 0; i1 < obj_map.map_height; i1++)
		{
			ft_printf("%s", obj_map.map[i1]);
		}
		ft_map_checker(&obj_map);
		
		
		
		obj_game.mlx_ptr = mlx_init();
		obj_game.win_ptr = mlx_new_window(obj_game.mlx_ptr, obj_map.map_width * 50, obj_map.map_height * 50,"hello world");
		img = mlx_xpm_file_to_image(obj_game.mlx_ptr, relative_path, &img_width, &img_height);

		i = 0;
		while(i < obj_map.map_width)
		{
			j = 0;
			while(j < obj_map.map_height)
			{
				mlx_put_image_to_window(obj_game.mlx_ptr, obj_game.win_ptr, img, i * 50, j * 50);
				j++;
			}
			i++;
		}
		mlx_key_hook(obj_game.win_ptr, deal_key, &obj_game);
		
		mlx_loop(obj_game.mlx_ptr);
	}
	else
		ft_printf("Please enter : ./so_long [code/maps/mapx.ber]\n");
	
}

