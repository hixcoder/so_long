/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 19:58:25 by hboumahd          #+#    #+#             */
/*   Updated: 2022/02/17 05:33:12 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
* this function calculate the map width and height
*/
void ft_map_dimensions(char *map_path, s_map *obj_map)
{
    int     fd;
	int		i;
	char	*line;
	
	i = 0;
    fd = open(map_path, O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		if (i == 0)
			obj_map->map_width = ft_strlen(line) - 1;
		i++;
	}
	obj_map->map_height = i;
    close(fd);
}

/*
* this function return the map in 2d char array
*/
char	**ft_map_init(char *map_path, s_map *obj_map)
{
    int		fd;
	int		i;
	char	*line;
	char	**map;
	
	map = malloc(obj_map->map_width * obj_map->map_height);
	if (!map)
		return (NULL);
	fd = open(map_path, O_RDONLY);
    i = 0;
	while ((line = get_next_line(fd)))
	{
		map[i] = ft_strdup(line);
		i++;
	}
    close(fd);
	return map;
}