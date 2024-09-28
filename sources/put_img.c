/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 18:20:49 by saberton          #+#    #+#             */
/*   Updated: 2024/09/28 14:20:57 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_img_map(t_game *game)
{
	game->img_collectible = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible.xpm", (int *)48, (int *)48);
    game->img_exit = mlx_xpm_file_to_image(game->mlx,
			"textures/exit.xpm", (int *)48, (int *)48);
    game->img_floor = mlx_xpm_file_to_image(game->mlx,
			"textures/floor.xpm", (int *)48, (int *)48);
    game->img_perso_front = mlx_xpm_file_to_image(game->mlx,
			"textures/perso_front.xpm", (int *)48, (int *)48);
    game->img_perso_left = mlx_xpm_file_to_image(game->mlx,
			"textures/perso_left.xpm", (int *)48, (int *)48);
    game->img_perso_right = mlx_xpm_file_to_image(game->mlx,
			"textures/perso_right.xpm", (int *)48, (int *)48);
    game->img_wall = mlx_xpm_file_to_image(game->mlx,
			"textures/wall.xpm", (int *)48, (int *)48);
    if (!game->img_collectible || !game->img_exit || !game->img_floor || !game->img_perso_front || game->img_perso_left || !game->img_perso_right || !game->img_wall)
        exit(EXIT_FAILURE); // had to add destroy fct
}