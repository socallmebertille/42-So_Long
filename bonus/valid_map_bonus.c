/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:55:21 by saberton          #+#    #+#             */
/*   Updated: 2024/10/07 12:54:38 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	is_rectangular(char **map)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	len = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (len == 0)
			len = j;
		else if (len != j)
			return (0);
		i++;
	}
	return (1);
}

static int	wall_and_char_check(char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] == 'P' || map[i][j] == 'E' || map[i][j] == 'C'
			|| map[i][j] == '0' || map[i][j] == '1' || map[i][j] == 'N')
		{
			if (i == 0 && map[i][j] != '1')
				return (0);
			if (!map[i + 1] && map[i][j] != '1')
				return (0);
			if ((j == 0 || j == ft_strlen(map[i]) - 1) && map[i][j] != '1')
				return (0);
			j++;
		}
		if (j != ft_strlen(map[i]))
			return (-1);
		i++;
	}
	return (1);
}

static int	nb_play_exit_coll(t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				game->nb_player += 1;
				game->player = (t_player){.x = j, .y = i};
			}
			if (game->map[i][j] == 'E')
				game->nb_exit += 1;
			if (game->map[i][j] == 'C')
				game->nb_collectible += 1;
			j++;
		}
		i++;
	}
	if (game->nb_player != 1 || game->nb_exit != 1 || game->nb_collectible < 1)
		return (0);
	return (game->width = j, game->height = i, 1);
}

static int	nb_enemy(t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'N')
				game->nb_enemy += 1;
			j++;
		}
		i++;
	}
	if (game->nb_enemy < 1)
		return (0);
	return (1);
}

int	valid_map_bonus(t_game *game)
{
	if (!is_rectangular(game->map))
		return (ft_printf(RED WRONG_SHAPE RESET), 0);
	if (!wall_and_char_check(game->map))
		return (ft_printf(RED WRONG_WALLS RESET), 0);
	if (wall_and_char_check(game->map) == -1)
		return (ft_printf(RED WRONG_CHAR RESET), 0);
	if (!nb_play_exit_coll(game) || !flood_fill_check(game) || !nb_enemy(game))
	{
		if (game->nb_player == 0)
			ft_printf(RED NO_PLAY RESET);
		if (game->nb_player > 1)
			ft_printf(RED FEW_PLAY RESET);
		if (game->nb_exit == 0)
			ft_printf(RED NO_EXIT RESET);
		if (game->nb_exit > 1)
			ft_printf(RED FEW_EXIT RESET);
		if (game->nb_collectible < 1)
			ft_printf(RED NO_COLL RESET);
		if (game->nb_enemy < 1)
			ft_printf(RED NO_ENEMY RESET);
		return (0);
	}
	return (1);
}
