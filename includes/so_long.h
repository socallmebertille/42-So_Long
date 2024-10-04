/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:03:43 by saberton          #+#    #+#             */
/*   Updated: 2024/10/04 20:27:28 by saberton         ###   ########.fr       */
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

# define RESET "\e[0m"
# define RED "\e[1;91m"
# define GREEN "\e[1;92m"
# define PURPLE "\033[1;35m"

# define WRONG_NB_ARGS "Error\nYou have to choose a map as 2nd arg!\n"
# define NO_MAP "Error\nThe map doesn't exist.\n"
# define WRONG_TYPE "Error\nThe type's map need to be in \".ber\"\n"
# define WRONG_READING "Error\nThere is an issue while reading the map.\n"
# define FEW_NEW_LINE "Error\nThe map contain too much '\\n'.\n"
# define WRONG_SHAPE "Error\nThe map isn't rectangular or line empty.\n"
# define WRONG_WALLS "Error\nThe map isn't surounded by walls or column empty.\n"
# define WRONG_CHAR "Error\nThe map contain at least 1 wrong character.\n"
# define NO_PLAY "Error\nNo player detected.\n"
# define FEW_PLAY "Error\nToo much player detected.\n"
# define NO_EXIT "Error\nNo exit detected.\n"
# define FEW_EXIT "Error\nToo much exit detected.\n"
# define NO_COLL "Error\nNo collectible detected.\n"
# define ACCESS_COLL "Error\nWe can't access all collectibles.\n"
# define ACCESS_EXIT "Error\nWe can't access exit.\n"

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