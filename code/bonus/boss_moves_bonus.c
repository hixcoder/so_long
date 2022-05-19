/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boss_moves_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 11:45:35 by hboumahd          #+#    #+#             */
/*   Updated: 2022/05/19 15:30:16 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_check_exit2(t_game *obj_game, char c)
{
	int	i;

	if (c == 'P')
	{
		ft_game_drawer(obj_game->obj_map, obj_game, obj_game->obj_img);
		i = -1;
		while (obj_game->obj_map->map[++i] != NULL)
		{
			free(obj_game->obj_map->map[i]);
			obj_game->obj_map->map[i] = NULL;
		}
		free(obj_game->obj_map->map);
		obj_game->obj_map->map = NULL;
		mlx_destroy_window(obj_game->mlx_ptr, obj_game->win_ptr);
		ft_printf("\n      ==> *_* { You Lost } *_* <==\n");
		exit(0);
	}
}

void	ft_boss_up(t_game *obj_game, char **map, int x, int y)
{
	ft_check_exit2(obj_game, map[y - 1][x]);
	map[y][x] = '0';
	map[y - 1][x] = 'B';
	obj_game->obj_map->boss_y--;
}

void	ft_boss_down(t_game *obj_game, char **map, int x, int y)
{
	ft_check_exit2(obj_game, map[y + 1][x]);
	map[y][x] = '0';
	map[y + 1][x] = 'B';
	obj_game->obj_map->boss_y++;
}

void	ft_boss_right(t_game *obj_game, char **map, int x, int y)
{
	ft_check_exit2(obj_game, map[y][x + 1]);
	map[y][x] = '0';
	map[y][x + 1] = 'B';
	obj_game->obj_map->boss_x++;
}

void	ft_boss_left(t_game *obj_game, char **map, int x, int y)
{
	ft_check_exit2(obj_game, map[y][x - 1]);
	map[y][x] = '0';
	map[y][x - 1] = 'B';
	obj_game->obj_map->boss_x--;
}
