/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 04:12:54 by hboumahd          #+#    #+#             */
/*   Updated: 2022/02/21 15:13:13 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_errors(int error_num)
{
	printf("==> Error: ");
	if (error_num == 0)
		printf("your map is not rectanglar.\n");
	else if (error_num == 1)
		printf("The map must contain only these 5 chars: [0, 1, C, E, P].\n");
	else if (error_num == 2)
		printf("The map must contain at least one [E & C] and only one P.\n");
	else if (error_num == 3)
		printf("The map must be surrounded by walls [1].\n");
	exit(0);
}

void	ft_check_walls(t_map *obj_map)
{
	int		i;
	int		j;
	int		rows;
	int		colums;
	char	**map;

	rows = obj_map->map_height - 1;
	colums = obj_map->map_width - 1;
	map = obj_map->map;
	i = -1;
	while (++i <= rows)
	{
		j = -1;
		while (++j <= colums)
		{
			if (map[0][j] != '1' || map[rows][j] != '1'
			|| map[i][0] != '1' || map[i][colums] != '1')
				ft_map_errors(3);
		}
	}
}

void	ft_check_is_rectangle(t_map *obj_map)
{
	int		i;
	char	**map;

	map = obj_map->map;
	i = -1;
	while (map[++i])
	{
		if (((int)ft_strlen(map[i]) - 1) != obj_map->map_width)
			ft_map_errors(0);
	}
}

void	ft_map_chars_num(t_map *obj_map, char map_c, int i, int j)
{
	if (map_c == '0' || map_c == '1')
		return ;
	if (map_c == 'E')
		obj_map->exit_num++;
	else if (map_c == 'C')
		obj_map->coin_num++;
	else if (map_c == 'P')
	{
		obj_map->plyr_num++;
		obj_map->plyr_x = j;
		obj_map->plyr_y = i;
	}	
}

/*
* this function for check if the map valid or not
*/
void	ft_map_checker(t_map *obj_map)
{
	int		i;
	int		j;
	char	**map;

	ft_check_is_rectangle(obj_map);
	map = obj_map->map;
	i = -1;
	obj_map->exit_num = 0;
	obj_map->coin_num = 0;
	obj_map->plyr_num = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'C'
			&& map[i][j] != 'E' && map[i][j] != 'P' && map[i][j] != '\n')
				ft_map_errors(1);
			ft_map_chars_num(obj_map, map[i][j], i, j);
		}
	}
	if (obj_map->exit_num <= 0 || obj_map->coin_num <= 0
		|| (obj_map->plyr_num != 1))
		ft_map_errors(2);
	ft_check_walls(obj_map);
}
