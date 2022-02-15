/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 20:07:18 by hboumahd          #+#    #+#             */
/*   Updated: 2022/02/15 13:57:25 by hboumahd         ###   ########.fr       */
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

	s_game obj_game;

	obj_game.mlx_ptr = mlx_init();
	obj_game.win_ptr = mlx_new_window(obj_game.mlx_ptr, 1000, 500,"hello world");
	mlx_key_hook(obj_game.win_ptr, deal_key, &obj_game);
	mlx_loop(obj_game.mlx_ptr);
}