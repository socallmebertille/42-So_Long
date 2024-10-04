/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:14:05 by saberton          #+#    #+#             */
/*   Updated: 2024/10/04 20:27:53 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	flood_fill(char **map, t_player cur)
{
	if (map[cur.y][cur.x] == 'E')
	{
		map[cur.y][cur.x] = 'S';
		return ;
	}
	if (map[cur.y][cur.x] == '1' || map[cur.y][cur.x] == 'S')
		return ;
	map[cur.y][cur.x] = 'S';
	flood_fill(map, (t_player){cur.x - 1, cur.y});
	flood_fill(map, (t_player){cur.x + 1, cur.y});
	flood_fill(map, (t_player){cur.x, cur.y - 1});
	flood_fill(map, (t_player){cur.x, cur.y + 1});
}

static int	player_blocked(t_game *game, int y, int x)
{
	if ((game->map[y - 1][x] == 'E' || game->map[y - 1][x] == '1')
		&& (game->map[y + 1][x] == 'E' || game->map[y + 1][x] == '1')
		&& (game->map[y][x - 1] == 'E' || game->map[y][x - 1] == '1')
		&& (game->map[y][x + 1] == 'E' || game->map[y][x + 1] == '1')
		&& game->nb_collectible > 0)
		return (0);
	return (1);
}

int	flood_fill_check(t_game *game)
{
	int	i;
	int	j;

	if (!player_blocked(game, game->player.y, game->player.x))
		return (ft_printf(RED ACCESS_COLL RESET), 0);
	flood_fill(game->check_map, game->player);
	i = 0;
	while (game->check_map[i])
	{
		j = 0;
		while (game->check_map[i][j])
		{
			if (game->check_map[i][j] == 'E')
				return (ft_printf(RED ACCESS_EXIT RESET), 0);
			if (game->check_map[i][j] == 'C' && game->check_map[i - 1][j] != 'S'
				&& game->check_map[i + 1][j] != 'S' && game->check_map[i][j
				- 1] != 'S' && game->check_map[i][j + 1] != 'S')
				return (ft_printf(RED ACCESS_COLL RESET), 0);
			j++;
		}
		i++;
	}
	return (1);
}
