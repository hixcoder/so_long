/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 00:42:59 by hboumahd          #+#    #+#             */
/*   Updated: 2022/02/19 20:50:51 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_move_up(s_game *obj_game)
{
	char	**map;
	int		x;
	int		y;

	map = obj_game->obj_map->map;
	x = obj_game->obj_map->plyr_x;
	y = obj_game->obj_map->plyr_y;
	if (map[y - 1][x] != '1' && map[y - 1][x] != 'E')
	{
		map[y][x] = '0';
		map[y - 1][x] = 'P';
		obj_game->obj_map->plyr_y--;
		obj_game->move_num++;
		ft_printf("==> Number of movements : %d\n", obj_game->move_num);
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
	if (map[y + 1][x] != '1' && map[y + 1][x] != 'E')
	{
		map[y][x] = '0';
		map[y + 1][x] = 'P';
		obj_game->obj_map->plyr_y++;
		obj_game->move_num++;
		ft_printf("==> Number of movements : %d\n", obj_game->move_num);
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
	if (map[y][x + 1] != '1' && map[y][x + 1] != 'E')
	{
		map[y][x] = '0';
		map[y][x + 1] = 'P';
		obj_game->obj_map->plyr_x++;
		obj_game->move_num++;
		ft_printf("==> Number of movements : %d\n", obj_game->move_num);
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
	if (map[y][x - 1] != '1' && map[y][x - 1] != 'E')
	{
		map[y][x] = '0';
		map[y][x - 1] = 'P';
		obj_game->obj_map->plyr_x--;
		obj_game->move_num++;
		ft_printf("==> Number of movements : %d\n", obj_game->move_num);
	}
	else if (map[y][x - 1] != 'E' && obj_game->obj_map->coin_num == 0)
	{
		map[y][x] = '0';
		map[y][x - 1] = 'P';
		obj_game->obj_map->plyr_x--;
		obj_game->move_num++;
		ft_printf("==> Number of movements : %d\n", obj_game->move_num);
	}
}

