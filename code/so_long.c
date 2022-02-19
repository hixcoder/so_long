/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 20:07:18 by hboumahd          #+#    #+#             */
/*   Updated: 2022/02/19 21:09:16 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int main(int ac, char **av)
{
	if (ac == 2)
	{	
		s_game	obj_game;
		s_map	obj_map;
		s_img	obj_img;
		
		obj_map.map = ft_map_init(av[1], &obj_map);
		ft_map_checker(&obj_map);
		printf("coin num: %d\n", obj_map.coin_num);
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