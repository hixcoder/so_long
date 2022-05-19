/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:49:10 by hboumahd          #+#    #+#             */
/*   Updated: 2022/05/19 12:09:48 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_move_boss(t_game *obj_game)
{
	int		x;
	int		y;
	char	**map;
	int		r;

	map = obj_game->obj_map->map;
	x = obj_game->obj_map->boss_x;
	y = obj_game->obj_map->boss_y;
	r = rand() % 5;
	if (r == 1 && (map[y - 1][x] == '0' || map[y - 1][x] == 'P'))
		ft_boss_up(obj_game, map, x, y);
	else if (r == 2 && (map[y + 1][x] == '0' || map[y + 1][x] == 'P'))
		ft_boss_down(obj_game, map, x, y);
	else if (r == 3 && (map[y][x + 1] == '0' || map[y][x + 1] == 'P'))
		ft_boss_right(obj_game, map, x, y);
	else if (r == 4 && (map[y][x - 1] == '0' || map[y][x - 1] == 'P'))
		ft_boss_left(obj_game, map, x, y);
}

int	ft_animate(void *obj_gam)
{
	t_game	*obj_game;
	int		s;
	void	*p;
	void	*img_boss;

	s = 50;
	obj_game = (t_game *) obj_gam;
	p = obj_game->mlx_ptr;
	img_boss = obj_game->obj_img->img_boss;
	mlx_clear_window(obj_game->mlx_ptr, obj_game->win_ptr);
	if (obj_game->counter % 20 == 0)
		img_boss = mlx_xpm_file_to_image(p, "./assets/boss_1.xpm", &s, &s);
	else if (obj_game->counter % 15 == 0)
	{
		img_boss = mlx_xpm_file_to_image(p, "./assets/boss_2.xpm", &s, &s);
		ft_move_boss(obj_game);
	}
	obj_game->obj_img->img_boss = img_boss;
	obj_game->counter++;
	if (obj_game->counter == 20)
		obj_game->counter = 0;
	ft_game_drawer(obj_game->obj_map, obj_game, obj_game->obj_img);
	return (1);
}
