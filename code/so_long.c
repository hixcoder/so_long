/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 20:07:18 by hboumahd          #+#    #+#             */
/*   Updated: 2022/02/15 16:56:40 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define KEY_ESC	53;
#define KEY_W	13;
#define KEY_S	1;
#define KEY_A	0;
#define KEY_D	2;

#define KEY_Q	12;
#define KEY_E	14;
#define KEY_R	15;


int deal_key(int key, void *param){
	ft_printf("the key is : %d\n", key);
	param = 0;
	return (0);
}

int main(){


	int	fd;
	char *line;

	
	fd = open("code/maps/map1.ber", O_RDONLY);
	while ((line =  get_next_line(fd)))
		ft_printf("%s", line);
	close(fd);


	

	s_game	obj_game;
	s_map	obj_map; // here I stopt
	
	char	*relative_path = "./assets/coin.xpm";
	int		img_width = 50;
	int		img_height = 50;
	void	*img;
	int	width = 13;
	int	height = 5;
	int i = 0;
	int j;

	obj_game.mlx_ptr = mlx_init();
	obj_game.win_ptr = mlx_new_window(obj_game.mlx_ptr, width * 50, height * 50,"hello world");
	img = mlx_xpm_file_to_image(obj_game.mlx_ptr, relative_path, &img_width, &img_height);
	while(i < width)
	{
		j = 0;
		while(j < height)
		{
			mlx_put_image_to_window(obj_game.mlx_ptr, obj_game.win_ptr, img, i * 50, j * 50);
			j++;
		}
		i++;
	}
	mlx_key_hook(obj_game.win_ptr, deal_key, &obj_game);
	mlx_loop(obj_game.mlx_ptr);
}

