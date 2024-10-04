/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:11:38 by saberton          #+#    #+#             */
/*   Updated: 2024/10/04 20:17:06 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	if (tab)
		free(tab);
}

static void	clean_img(t_game *game)
{
	if (game->img_collectible)
		mlx_destroy_image(game->mlx, game->img_collectible);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_floor)
		mlx_destroy_image(game->mlx, game->img_floor);
	if (game->img_perso_front)
		mlx_destroy_image(game->mlx, game->img_perso_front);
	if (game->img_perso_left)
		mlx_destroy_image(game->mlx, game->img_perso_left);
	if (game->img_perso_right)
		mlx_destroy_image(game->mlx, game->img_perso_right);
}

int	close_window(t_game *game)
{
	if (game->map)
		free_tab(game->map);
	if (game->check_map)
		free_tab(game->check_map);
	clean_img(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (game)
		free(game);
	exit(0);
}

static int	render_next_frame(int keycode, t_game *game)
{
	if (keycode == ESC)
		close_window(game);
	else if (keycode == NORTH || keycode == NORTH_)
		move_north(game, game->player.y, game->player.x);
	else if (keycode == SOUTH || keycode == SOUTH_)
		move_south(game, game->player.y, game->player.x);
	else if (keycode == WEST || keycode == WEST_)
		move_west(game, game->player.y, game->player.x);
	else if (keycode == EST || keycode == EST_)
		move_est(game, game->player.y, game->player.x);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
		return (ft_printf(RED WRONG_NB_ARGS RESET), 0);
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (1);
	ft_bzero(game, sizeof(t_game));
	valid_file(av[1], game);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->width * 48, game->height * 48,
			"So_Long");
	if (!game->win)
		return (1);
	put_img(game);
	put_img_map(game, 0, 0, 'N');
	mlx_key_hook(game->win, render_next_frame, game);
	mlx_hook(game->win, 33, 0, close_window, game);
	mlx_loop(game->mlx);
	return (0);
}
