/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 18:20:49 by saberton          #+#    #+#             */
/*   Updated: 2024/10/07 16:07:43 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_img(t_game *game)
{
	int	random;

	game->img_collectible = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible.xpm", &random, &random);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm",
			&random, &random);
	game->img_exit_open = mlx_xpm_file_to_image(game->mlx,
			"textures/exit_open.xpm", &random, &random);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm",
			&random, &random);
	game->img_perso_front = mlx_xpm_file_to_image(game->mlx,
			"textures/perso_front.xpm", &random, &random);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm",
			&random, &random);
	if (!game->img_collectible || !game->img_exit || !game->img_exit_open
		|| !game->img_floor || !game->img_perso_front || !game->img_wall)
		close_window(game);
}

void	put_exit_map(t_game *game, int y, int x)
{
	if (game->map[y][x] == 'E' && game->nb_collectible > 0)
		mlx_put_image_to_window(game->mlx, game->win, game->img_exit, x * 48, y
			* 48);
	else if (game->map[y][x] == 'E' && game->nb_collectible == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->img_exit_open, x
			* 48, y * 48);
}

void	put_img_map(t_game *game, int y, int x)
{
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->img_floor, x
					* 48, y * 48);
			else if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->img_wall, x
					* 48, y * 48);
			else if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win,
					game->img_collectible, x * 48, y * 48);
			else if (game->map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->win,
					game->img_perso_front, x * 48, y * 48);
			else if (game->map[y][x] == 'E')
				put_exit_map(game, y, x);
			x++;
		}
		y++;
	}
}
