/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:03:43 by saberton          #+#    #+#             */
/*   Updated: 2024/10/04 15:50:30 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../ft_printf/includes/ft_printf.h"
# include "../libft/includes/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/Xlib.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>

# define ESC 65307
# define NORTH 65362
# define SOUTH 65364
# define WEST 65361
# define EST 65363
# define NORTH_ 119
# define SOUTH_ 115
# define WEST_ 97
# define EST_ 100

typedef struct s_player
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
	int			nb_collectible;
	int			nb_move;
	size_t		width;
	size_t		height;
	char		**map;
	char		**check_map;
	t_player	player;
}				t_game;

void			put_img(t_game *game);
void			put_perso_map(t_game *game, int y, int x, char dir);
void			put_img_map(t_game *game, int y, int x, char dir);
void			move_north(t_game *game, int y, int x);
void			move_south(t_game *game, int y, int x);
void			move_west(t_game *game, int y, int x);
void			move_est(t_game *game, int y, int x);
int				valid_file(char *map, t_game *game);
int				valid_map(t_game *game);
int				flood_fill_check(t_game *game);
int				close_window(t_game *game);

#endif