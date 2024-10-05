/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 18:20:49 by saberton          #+#    #+#             */
/*   Updated: 2024/10/05 17:48:48 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_img_bonus(t_game *game)
{
	int	random;

	game->img_collectible = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible.xpm", &random, &random);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm",
			&random, &random);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm",
			&random, &random);
	game->img_perso_front = mlx_xpm_file_to_image(game->mlx,
			"textures/perso_front.xpm", &random, &random);
	game->img_perso_back = mlx_xpm_file_to_image(game->mlx,
			"textures/perso_back.xpm", &random, &random);
	game->img_perso_left = mlx_xpm_file_to_image(game->mlx,
			"textures/perso_left.xpm", &random, &random);
	game->img_perso_right = mlx_xpm_file_to_image(game->mlx,
			"textures/perso_right.xpm", &random, &random);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm",
			&random, &random);
	game->img_enemy = mlx_xpm_file_to_image(game->mlx, "textures/enemy.xpm",
			&random, &random);
	if (!game->img_collectible || !game->img_exit || !game->img_floor
		|| !game->img_perso_front || !game->img_perso_back
		|| !game->img_perso_left || !game->img_perso_right || !game->img_wall
		|| !game->img_enemy)
		close_window_bonus(game);
}

void	put_perso_enemy_bonus(t_game *game, int y, int x, char dir)
{
	if (game->map[y][x] == 'P' && dir == 'N')
		mlx_put_image_to_window(game->mlx, game->win, game->img_perso_back, x
			* 48, y * 48);
	else if (game->map[y][x] == 'P' && dir == 'S')
		mlx_put_image_to_window(game->mlx, game->win, game->img_perso_front, x
			* 48, y * 48);
	else if (game->map[y][x] == 'P' && dir == 'W')
		mlx_put_image_to_window(game->mlx, game->win, game->img_perso_left, x
			* 48, y * 48);
	else if (game->map[y][x] == 'P' && dir == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img_perso_right, x
			* 48, y * 48);
	else if (game->map[y][x] == 'N')
		mlx_put_image_to_window(game->mlx, game->win, game->img_enemy, x
			* 48, y * 48);
}

void	put_img_map_bonus(t_game *game, int y, int x, char dir)
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
			else if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->img_exit, x
					* 48, y * 48);
			else if (game->map[y][x] == 'P' || game->map[y][x] == 'N')
				put_perso_enemy_bonus(game, y, x, dir);
			x++;
		}
		y++;
	}
}
