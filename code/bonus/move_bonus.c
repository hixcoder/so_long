/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 00:42:59 by hboumahd          #+#    #+#             */
/*   Updated: 2022/05/16 13:14:16 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_check_exit(t_game *obj_game)
{
	if (obj_game->obj_map->coin_num == 0)
	{
		ft_game_drawer(obj_game->obj_map, obj_game, obj_game->obj_img);
		free(obj_game->obj_map->map);
		obj_game->obj_map->map = NULL;
		mlx_destroy_window(obj_game->mlx_ptr, obj_game->win_ptr);
		ft_printf("\n      ==> *_* { Game End } *_* <==\n");
		exit(0);
	}
	else
		return ;
}

void	ft_move_up(t_game *obj_game)
{
	char	**map;
	int		x;
	int		y;

	map = obj_game->obj_map->map;
	x = obj_game->obj_map->plyr_x;
	y = obj_game->obj_map->plyr_y;
	if (map[y - 1][x] != '1')
	{
		if (map[y - 1][x] == 'C')
			obj_game->obj_map->coin_num--;
		if (map[y - 1][x] == 'E')
			ft_check_exit(obj_game);
		else
		{
			map[y][x] = '0';
			map[y - 1][x] = 'P';
			obj_game->obj_map->plyr_y--;
			obj_game->move_num++;
			ft_printf("==> Number of movements : %d\n", obj_game->move_num);
		}
	}
}

void	ft_move_down(t_game *obj_game)
{
	char	**map;
	int		x;
	int		y;

	map = obj_game->obj_map->map;
	x = obj_game->obj_map->plyr_x;
	y = obj_game->obj_map->plyr_y;
	if (map[y + 1][x] != '1')
	{
		if (map[y + 1][x] == 'C')
			obj_game->obj_map->coin_num--;
		if (map[y + 1][x] == 'E')
			ft_check_exit(obj_game);
		else
		{
			map[y][x] = '0';
			map[y + 1][x] = 'P';
			obj_game->obj_map->plyr_y++;
			obj_game->move_num++;
			ft_printf("==> Number of movements : %d\n", obj_game->move_num);
		}
	}
}

void	ft_move_right(t_game *obj_game)
{
	char	**map;
	int		x;
	int		y;

	map = obj_game->obj_map->map;
	x = obj_game->obj_map->plyr_x;
	y = obj_game->obj_map->plyr_y;
	if (map[y][x + 1] != '1')
	{
		if (map[y][x + 1] == 'C')
			obj_game->obj_map->coin_num--;
		if (map[y][x + 1] == 'E')
			ft_check_exit(obj_game);
		else
		{
			map[y][x] = '0';
			map[y][x + 1] = 'P';
			obj_game->obj_map->plyr_x++;
			obj_game->move_num++;
			ft_printf("==> Number of movements : %d\n", obj_game->move_num);
		}
	}
}

void	ft_move_left(t_game *obj_game)
{
	char	**map;
	int		x;
	int		y;

	map = obj_game->obj_map->map;
	x = obj_game->obj_map->plyr_x;
	y = obj_game->obj_map->plyr_y;
	if (map[y][x - 1] != '1')
	{
		if (map[y][x - 1] == 'C')
			obj_game->obj_map->coin_num--;
		if (map[y][x - 1] == 'E')
			ft_check_exit(obj_game);
		else
		{
			map[y][x] = '0';
			map[y][x - 1] = 'P';
			obj_game->obj_map->plyr_x--;
			obj_game->move_num++;
			ft_printf("==> Number of movements : %d\n", obj_game->move_num);
		}
	}
}
