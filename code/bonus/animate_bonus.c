/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:49:10 by hboumahd          #+#    #+#             */
/*   Updated: 2022/05/18 21:36:37 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int ft_animate(void *obj_gam)
{
    t_game	*obj_game;
    int		s;
	void	*p;

	s = 50;
	obj_game = (t_game *) obj_gam;
	p = obj_game->mlx_ptr;
    mlx_clear_window(obj_game->mlx_ptr, obj_game->win_ptr);
    if (obj_game->counter % 20 == 0)
        obj_game->obj_img->img_boss = mlx_xpm_file_to_image(p, "./assets/boss_1.xpm", &s, &s);
    else if (obj_game->counter % 15 == 0)
        obj_game->obj_img->img_boss = mlx_xpm_file_to_image(p, "./assets/boss_2.xpm", &s, &s);
    obj_game->counter++;
    if (obj_game->counter == 20)
        obj_game->counter = 0;
    ft_game_drawer(obj_game->obj_map, obj_game, obj_game->obj_img);
    return (1);
}