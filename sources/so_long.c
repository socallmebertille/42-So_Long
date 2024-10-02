/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:11:38 by saberton          #+#    #+#             */
/*   Updated: 2024/10/02 19:47:10 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	render_next_frame(int keycode, t_game *game)
{
	(void)game;
	if (keycode == ESC)
		exit(0);
	else if (keycode == NORTH || keycode == NORTH_)
		ft_printf("NORTH\n");
	else if (keycode == SOUTH || keycode == SOUTH_)
		ft_printf("SOUTH\n");
	else if (keycode == WEST || keycode == WEST_)
		ft_printf("WEST\n");
	else if (keycode == EST || keycode == EST_)
		ft_printf("EST\n");
	return (0);
}

static int close_window(void *param)
{
	(void)param; // Si tu n'as pas besoin de paramètre, tu peux ignorer l'avertissement avec ce cast
	exit(0);     // Appel à exit pour terminer le programme
	return (0);  // Retourne 0 comme attendu par mlx_hook
}

int	main(int ac, char **av)
{
	t_game *game;

	if (ac != 2)
		return (ft_printf("ERROR : You have to choose a map as 2nd arg!\n"), 0);
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (1);
	ft_bzero(game, sizeof(t_game));
	valid_file(av[1], game);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->width * 48, game->height * 48, "So_Long");
	if (!game->win)
		return (1);
	put_img(game);
	put_img_map(game);
	mlx_key_hook(game->win, render_next_frame, &game);
	mlx_hook(game->win, 33, 0, close_window, game);
	mlx_loop(game->mlx);
	return (0);
}
