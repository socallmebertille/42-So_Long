/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:03:43 by saberton          #+#    #+#             */
/*   Updated: 2024/09/28 18:52:34 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include <X11/Xlib.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_circle
{
	int			x;
	int			y;
}				t_player;

typedef struct s_data
{
	void		*img_floor;
	void		*img_wall;
	void		*img_collectible;
	void		*img_exit;
	void		*img_perso_front;
	void		*img_perso_left;
	void		*img_perso_right;
	void		*mlx;
	void		*win;
	int			nb_exit;
	int			nb_player;
	size_t		width;
	size_t		height;
	char		**map;
	char		**check_map;
}				t_game;

void	put_img_map(t_game *game);
int	valid_map(char *map, t_game *game);

#endif