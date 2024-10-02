/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 18:20:49 by saberton          #+#    #+#             */
/*   Updated: 2024/10/02 19:06:18 by saberton         ###   ########.fr       */
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
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm",
			&random, &random);
	game->img_perso_front = mlx_xpm_file_to_image(game->mlx,
			"textures/perso_front.xpm", &random, &random);
	game->img_perso_left = mlx_xpm_file_to_image(game->mlx,
			"textures/perso_left.xpm", &random, &random);
	game->img_perso_right = mlx_xpm_file_to_image(game->mlx,
			"textures/perso_right.xpm", &random, &random);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm",
			&random, &random);
	if (!game->img_collectible || !game->img_exit || !game->img_floor
		|| !game->img_perso_front || !game->img_perso_left
		|| !game->img_perso_right || !game->img_wall)
		exit(EXIT_FAILURE); // had to add destroy fct
}
void	put_img_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->img_floor, j
					* 48, i * 48);
			else if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->img_wall, j
					* 48, i * 48);
			else if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win,
					game->img_collectible, j * 48, i * 48);
			else if (game->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->win,
					game->img_exit, j * 48, i * 48);
			else if (game->map[i][j] == 'P')
				mlx_put_image_to_window(game->mlx, game->win,
					game->img_perso_right, j * 48, i * 48);
			j++;
		}
		i++;
	}
}
