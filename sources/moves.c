/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:37:49 by saberton          #+#    #+#             */
/*   Updated: 2024/10/04 20:23:06 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	can_exit(t_game *game, int y, int x)
{
	if (game->map[y][x] == 'E' && game->nb_collectible > 0)
		return (-1);
	else if (game->map[y][x] == 'E' && game->nb_collectible == 0)
		return (1);
	else if (game->map[y][x] == 'C')
		game->nb_collectible -= 1;
	return (0);
}

void	move_north(t_game *game, int y, int x)
{
	int	finish;

	finish = can_exit(game, y - 1, x);
	if (game->map[y - 1][x] == '1' || finish < 0)
		return ;
	if (finish == 1)
	{
		game->map[y - 1][x] = 'P';
		game->map[y][x] = '0';
		game->player.y -= 1;
		put_img_map(game, 0, 0, 'N');
		game->nb_move += 1;
		ft_printf(GREEN "You win in %d moves, congratulations !!!\n" RESET,
			game->nb_move);
		close_window(game);
	}
	game->map[y - 1][x] = 'P';
	game->map[y][x] = '0';
	game->player.y -= 1;
	put_img_map(game, 0, 0, 'N');
	game->nb_move += 1;
	ft_printf(PURPLE "It's your %d move.\n" RESET, game->nb_move);
	return ;
}

void	move_south(t_game *game, int y, int x)
{
	int	finish;

	finish = can_exit(game, y + 1, x);
	if (game->map[y + 1][x] == '1' || finish < 0)
		return ;
	if (finish == 1)
	{
		game->map[y + 1][x] = 'P';
		game->map[game->player.y][game->player.x] = '0';
		game->player.y += 1;
		put_img_map(game, 0, 0, 'S');
		game->nb_move += 1;
		ft_printf(GREEN "You win in %d moves, congratulations !!!\n" RESET,
			game->nb_move);
		close_window(game);
	}
	game->map[y + 1][x] = 'P';
	game->map[game->player.y][game->player.x] = '0';
	game->player.y += 1;
	put_img_map(game, 0, 0, 'S');
	game->nb_move += 1;
	ft_printf(PURPLE "It's your %d move.\n" RESET, game->nb_move);
	return ;
}

void	move_west(t_game *game, int y, int x)
{
	int	finish;

	finish = can_exit(game, y, x - 1);
	if (game->map[y][x - 1] == '1' || finish < 0)
		return ;
	if (finish == 1)
	{
		game->map[y][x - 1] = 'P';
		game->map[y][x] = '0';
		game->player.x -= 1;
		put_img_map(game, 0, 0, 'W');
		game->nb_move += 1;
		ft_printf(GREEN "You win in %d moves, congratulations !!!\n" RESET,
			game->nb_move);
		close_window(game);
	}
	game->map[y][x - 1] = 'P';
	game->map[y][x] = '0';
	game->player.x -= 1;
	put_img_map(game, 0, 0, 'W');
	game->nb_move += 1;
	ft_printf(PURPLE "It's your %d move.\n" RESET, game->nb_move);
	return ;
}

void	move_est(t_game *game, int y, int x)
{
	int	finish;

	finish = can_exit(game, y, x + 1);
	if (game->map[y][x + 1] == '1' || finish < 0)
		return ;
	if (finish == 1)
	{
		game->map[y][x + 1] = 'P';
		game->map[y][x] = '0';
		game->player.x += 1;
		put_img_map(game, 0, 0, 'E');
		game->nb_move += 1;
		ft_printf(GREEN "You win in %d moves, congratulations !!!\n" RESET,
			game->nb_move);
		close_window(game);
	}
	game->map[y][x + 1] = 'P';
	game->map[y][x] = '0';
	game->player.x += 1;
	put_img_map(game, 0, 0, 'E');
	game->nb_move += 1;
	ft_printf(PURPLE "It's your %d move.\n" RESET, game->nb_move);
	return ;
}
