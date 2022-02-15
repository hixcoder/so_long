/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:58:45 by hboumahd          #+#    #+#             */
/*   Updated: 2022/02/15 16:53:47 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H
# include "mlx.h"
# include "./ft_printf/ft_printf.h"
# include "./get_next_line/get_next_line.h"

typedef struct s_game
{
    void	*mlx_ptr;
    void	*win_ptr;
} s_game;

typedef struct s_map
{
    void	*mlx_ptr;
    void	*win_ptr;
} s_map;


#endif 