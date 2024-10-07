/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:11:38 by saberton          #+#    #+#             */
/*   Updated: 2024/10/07 16:00:36 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	if (tab)
		free(tab);
	tab = NULL;
}

static void	clean_img_bonus(t_game *game)
{
	if (game->img_floor)
		mlx_destroy_image(game->mlx, game->img_floor);
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_collectible)
		mlx_destroy_image(game->mlx, game->img_collectible);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
	if (game->img_exit_open)
		mlx_destroy_image(game->mlx, game->img_exit_open);
	if (game->img_perso_front)
		mlx_destroy_image(game->mlx, game->img_perso_front);
	if (game->img_perso_back)
		mlx_destroy_image(game->mlx, game->img_perso_back);
	if (game->img_perso_left)
		mlx_destroy_image(game->mlx, game->img_perso_left);
	if (game->img_perso_right)
		mlx_destroy_image(game->mlx, game->img_perso_right);
	if (game->img_enemy)
		mlx_destroy_image(game->mlx, game->img_enemy);
	if (game->img_score)
		mlx_destroy_image(game->mlx, game->img_score);
}

int	close_window_bonus(t_game *game)
{
	if (game->map)
		free_tab(game->map);
	if (game->check_map)
		free_tab(game->check_map);
	clean_img_bonus(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
	if (game)
		free(game);
	game = NULL;
	exit(0);
}

static int	render_next_frame(int keycode, t_game *game)
{
	if (keycode == ESC)
		close_window_bonus(game);
	else if (keycode == NORTH || keycode == NORTH_)
		move_north_bonus(game, game->player.y, game->player.x);
	else if (keycode == SOUTH || keycode == SOUTH_)
		move_south_bonus(game, game->player.y, game->player.x);
	else if (keycode == WEST || keycode == WEST_)
		move_west_bonus(game, game->player.y, game->player.x);
	else if (keycode == EST || keycode == EST_)
		move_est_bonus(game, game->player.y, game->player.x);
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
	valid_file_bonus(av[1], game);
	game->total_coll = game->nb_collectible;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->width * 48, game->height * 48,
			"So_Long_Bonus");
	if (!game->win)
		return (1);
	put_img_bonus(game);
	put_img_map_bonus(game, 0, 0, 'S');
	mlx_key_hook(game->win, render_next_frame, game);
	mlx_loop_hook(game->mlx, put_move, game);
	mlx_hook(game->win, 33, 0, close_window_bonus, game);
	mlx_loop(game->mlx);
	return (0);
}
