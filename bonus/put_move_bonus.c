/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_move_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 17:57:29 by saberton          #+#    #+#             */
/*   Updated: 2024/10/07 14:57:24 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	put_coll(t_game *game)
{
	char	*nb;
	char	*total;

	nb = ft_itoa(game->total_coll - game->nb_collectible);
	total = ft_itoa(game->total_coll);
	mlx_string_put(game->mlx, game->win, 20, 37, 0xFFFFFF, "Collectibles :  /");
	mlx_string_put(game->mlx, game->win, 22, 37, 0xFFFFFF, "Collectibles :  /");
	mlx_string_put(game->mlx, game->win, 21, 36, 0xFFFFFF, "Collectibles :  /");
	mlx_string_put(game->mlx, game->win, 21, 38, 0xFFFFFF, "Collectibles :  /");
	mlx_string_put(game->mlx, game->win, 21, 37, 16711935, "Collectibles :  /");
	mlx_string_put(game->mlx, game->win, 109, 37, 0xFFFFFF, nb);
	mlx_string_put(game->mlx, game->win, 111, 37, 0xFFFFFF, nb);
	mlx_string_put(game->mlx, game->win, 110, 36, 0xFFFFFF, nb);
	mlx_string_put(game->mlx, game->win, 110, 38, 0xFFFFFF, nb);
	mlx_string_put(game->mlx, game->win, 110, 37, 16711935, nb);
	mlx_string_put(game->mlx, game->win, 124, 37, 0xFFFFFF, total);
	mlx_string_put(game->mlx, game->win, 126, 37, 0xFFFFFF, total);
	mlx_string_put(game->mlx, game->win, 125, 36, 0xFFFFFF, total);
	mlx_string_put(game->mlx, game->win, 125, 38, 0xFFFFFF, total);
	mlx_string_put(game->mlx, game->win, 125, 37, 16711935, total);
	free(nb);
	free(total);
	return (1);
}

int	put_move(t_game *game)
{
	char	*nb;

	mlx_put_image_to_window(game->mlx, game->win, game->img_score, 0, 4);
	nb = ft_itoa(game->nb_move);
	mlx_string_put(game->mlx, game->win, 20, 22, 0xFFFFFF, "Moves :");
	mlx_string_put(game->mlx, game->win, 22, 22, 0xFFFFFF, "Moves :");
	mlx_string_put(game->mlx, game->win, 21, 21, 0xFFFFFF, "Moves :");
	mlx_string_put(game->mlx, game->win, 21, 23, 0xFFFFFF, "Moves :");
	mlx_string_put(game->mlx, game->win, 21, 22, 16711935, "Moves :");
	mlx_string_put(game->mlx, game->win, 109, 22, 0xFFFFFF, nb);
	mlx_string_put(game->mlx, game->win, 111, 22, 0xFFFFFF, nb);
	mlx_string_put(game->mlx, game->win, 110, 21, 0xFFFFFF, nb);
	mlx_string_put(game->mlx, game->win, 110, 23, 0xFFFFFF, nb);
	mlx_string_put(game->mlx, game->win, 110, 22, 16711935, nb);
	put_coll(game);
	free(nb);
	return (1);
}
