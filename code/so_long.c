/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 20:07:18 by hboumahd          #+#    #+#             */
/*   Updated: 2022/02/21 15:33:37 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_key_handler(int key, void *obj_gam)
{
	t_game	*obj_game;
	char	**map;

	obj_game = (t_game *) obj_gam;
	map = obj_game->obj_map->map;
	mlx_clear_window(obj_game->mlx_ptr, obj_game->win_ptr);
	if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_W)
		ft_move_up(obj_game);
	else if (key == KEY_S)
		ft_move_down(obj_game);
	else if (key == KEY_A)
		ft_move_left(obj_game);
	else if (key == KEY_D)
		ft_move_right(obj_game);
	ft_game_drawer(obj_game->obj_map, obj_game, obj_game->obj_img);
	return (0);
}

int	ft_exit_handler(void *obj_gam)
{
	t_game	*obj_game;

	obj_game = obj_gam;
	free(obj_game->obj_map->map);
	obj_game->obj_map->map = NULL;
	mlx_destroy_window(obj_game->mlx_ptr, obj_game->win_ptr);
	exit(0);
}

int	main(int ac, char **av)
{
	t_game	obj_game;
	t_map	obj_map;
	t_img	obj_img;
	int		h;
	int		w;

	if (ac == 2)
	{
		obj_map.map = ft_map_init(av[1], &obj_map);
		ft_map_checker(&obj_map);
		obj_game.move_num = 0;
		obj_game.obj_map = &obj_map;
		obj_game.obj_img = &obj_img;
		obj_game.mlx_ptr = mlx_init();
		h = obj_map.map_height * 50;
		w = obj_map.map_width * 50;
		obj_game.win_ptr = mlx_new_window(obj_game.mlx_ptr, w, h, "Solo man");
		ft_drawer_init(&obj_game, &obj_img);
		ft_game_drawer(&obj_map, &obj_game, &obj_img);
		mlx_hook(obj_game.win_ptr, 02, 0, ft_key_handler, &obj_game);
		mlx_hook(obj_game.win_ptr, 17, 0, ft_exit_handler, &obj_game);
		mlx_loop(obj_game.mlx_ptr);
	}
	else
		ft_printf("Please enter : ./so_long [code/maps/mapx.ber]\n");
}
