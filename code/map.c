/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 19:58:25 by hboumahd          #+#    #+#             */
/*   Updated: 2022/02/21 15:42:26 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_map_type(char *map_path)
{
	int		map_path_ending;
	char	*ending;

	map_path_ending = ft_strlen(map_path) - 4;
	ending = ".ber";
	if (ft_strncmp(ending, &map_path[map_path_ending], 4) != 0)
	{
		printf("==> Error: The map must end with the [.ber] extension.\n");
		exit(0);
	}
}

/*
* this function calculate the map width and height
*/
void	ft_map_dimensions(char *map_path, t_map *obj_map)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(map_path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		if (i == 0)
			obj_map->map_width = ft_strlen(line) - 1;
		line = get_next_line(fd);
		i++;
	}
	obj_map->map_height = i;
	close(fd);
}

/*
* this function return the map in 2d char array
*/
char	**ft_map_init(char *map_path, t_map *obj_map)
{
	int		fd;
	int		i;
	char	*line;
	char	**map;

	ft_check_map_type(map_path);
	ft_map_dimensions(map_path, obj_map);
	map = (char **) malloc(sizeof(char *) * (obj_map->map_height + 1));
	if (!map)
		return (NULL);
	fd = open(map_path, O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		map[i] = ft_strdup(line);
		line = get_next_line(fd);
		i++;
	}
	map[obj_map->map_height] = NULL;
	close(fd);
	return (map);
}
