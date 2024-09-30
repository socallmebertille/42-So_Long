/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:55:21 by saberton          #+#    #+#             */
/*   Updated: 2024/09/30 16:45:32 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int  is_rectangular(char **map)
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

static int  wall_check(char **map)
{
	size_t	i;
	size_t	j;
	size_t	wall;

	i = 0;
	wall = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (i == 0 && map[i][j] != '1')
				return (0);
			if (!map[i + 1] && map[i][j] != '1')
				return (0);
			if ((j == 0 || j == ft_strlen(map[i]) - 1) && map[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int  nb_play_exit_coll(t_game *game)
{
	size_t	i;
	size_t	j;

	game->nb_player = 0;
	game->nb_exit = 0;
	game->nb_collectible = 0;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
				game->nb_player +=1;
			if (game->map[i][j] == 'E')
				game->nb_exit +=1;
			if (game->map[i][j] == 'C')
				game->nb_collectible +=1;
			j++;
		}
		i++;
	}
	if (game->nb_player != 1 || game->nb_exit != 1 || game->nb_collectible < 1)
		return (0);
	return (1);
}

int valid_map(t_game *game)
{
	if (!is_rectangular(game->map))
		return (ft_printf("The map isn't rectangular or line empty.\n"), 0);
	if (!wall_check(game->map))
		return (ft_printf("The map isn't surounded by walls or column empty.\n"), 0);
	if (!nb_play_exit_coll(game))
	{
		if (game->nb_player == 0)
			ft_printf("No player detected.\n");
		if (game->nb_player > 1)
			ft_printf("Too much player detected.\n");
		if (game->nb_exit == 0)
			ft_printf("No exit detected.\n");
		if (game->nb_exit > 1)
			ft_printf("Too much exit detected.\n");
		if (game->nb_collectible < 1)
			ft_printf("No collectible detected.\n");
		return (0);
	}
	// if (!fool_fill_check(game))
	// 	return (0);
	return (1);
}
