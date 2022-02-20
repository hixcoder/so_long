/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 00:42:59 by hboumahd          #+#    #+#             */
/*   Updated: 2022/02/20 10:21:09 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_exit(s_game *obj_game)
{
	if (obj_game->obj_map->coin_num == 0)
	{
		ft_game_drawer(obj_game->obj_map, obj_game, obj_game->obj_img);
		ft_printf("\n      ==> *_* { Game End } *_* <==\n");
		exit(0);
	}
	else
		return;
}

void    ft_move_up(s_game *obj_game)
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
			ft_printf("==> Number of movements : %d\n   R==>Number of coin : %d\n", obj_game->move_num, obj_game->obj_map->coin_num);
		}
	}
}

void    ft_move_down(s_game *obj_game)
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
			ft_printf("==> Number of movements : %d\n   R==>Number of coin : %d\n", obj_game->move_num, obj_game->obj_map->coin_num);
		}
	}
}

void    ft_move_right(s_game *obj_game)
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
			ft_printf("==> Number of movements : %d\n   R==>Number of coin : %d\n", obj_game->move_num, obj_game->obj_map->coin_num);
		}
	}
}

void    ft_move_left(s_game *obj_game)
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
			ft_printf("==> Number of movements : %d\n   R==>Number of coin : %d\n", obj_game->move_num, obj_game->obj_map->coin_num);
		}
	}
}

