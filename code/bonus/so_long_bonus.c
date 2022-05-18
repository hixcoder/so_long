/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 20:07:18 by hboumahd          #+#    #+#             */
/*   Updated: 2022/05/18 21:28:20 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_exit_handler(void *obj_gam)
{
	t_game	*obj_game;

	obj_game = obj_gam;
	free(obj_game->obj_map->map);
	obj_game->obj_map->map = NULL;
	mlx_destroy_window(obj_game->mlx_ptr, obj_game->win_ptr);
	exit(0);
}

int	ft_key_handler(int key, void *obj_gam)
{
	t_game	*obj_game;
	char	**map;
	
	obj_game = (t_game *) obj_gam;
	map = obj_game->obj_map->map;
	mlx_clear_window(obj_game->mlx_ptr, obj_game->win_ptr);
	if (key == KEY_ESC)
		ft_exit_handler(obj_game);
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

void	ft_init_obj_game(t_game *obj_game, t_map *obj_map, t_img *obj_img)
{
	obj_game->move_num = 0;
	obj_game->obj_map = obj_map;
	obj_game->obj_img = obj_img;
	obj_game->mlx_ptr = mlx_init();
	obj_game->counter = 0;
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
		if (!obj_map.map)
			return (0);
		ft_map_checker(&obj_map);
		ft_init_obj_game(&obj_game, &obj_map, &obj_img);
		h = obj_map.map_height * 50 + 50;
		w = obj_map.map_width * 50;
		obj_game.win_ptr = mlx_new_window(obj_game.mlx_ptr, w, h, "Solo man");
		ft_drawer_init(&obj_game, &obj_img);
		ft_game_drawer(&obj_map, &obj_game, &obj_img);
		mlx_hook(obj_game.win_ptr, 02, 0, ft_key_handler, &obj_game);
		mlx_hook(obj_game.win_ptr, 17, 0, ft_exit_handler, &obj_game);
		mlx_loop_hook(obj_game.mlx_ptr, ft_animate, &obj_game);
	    mlx_loop(obj_game.mlx_ptr);
	}
	else
		ft_printf("==> Enter : ./so_long_bonus [assets/maps/map_name.ber]\n");
}
