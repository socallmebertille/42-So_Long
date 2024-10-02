/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:14:05 by saberton          #+#    #+#             */
/*   Updated: 2024/10/02 16:49:13 by saberton         ###   ########.fr       */
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

int	flood_fill_check(t_game *game)
{
	int	i;
	int	j;

	flood_fill(game->check_map, game->player);
	// i = 0;
	// while (game->check_map[i])
	// {
	// 	ft_printf("%s\n", game->check_map[i]);
	// 	i++;
	// }
	i = 0;
	while (game->check_map[i])
	{
		j = 0;
		while (game->check_map[i][j])
		{
			if (game->check_map[i][j] == 'E')
				return (ft_printf("We can't access exit.\n"), 0);
			if (game->check_map[i][j] == 'C' && game->check_map[i - 1][j] != 'S'
				&& game->check_map[i + 1][j] != 'S' && game->check_map[i][j
				- 1] != 'S' && game->check_map[i][j + 1] != 'S')
				return (ft_printf("We can't access all collectibles.\n"), 0);
			j++;
		}
		i++;
	}
	// tq C > 0 -> E == 1
	// tant qu'il rest des coin -> on considere E comme un mur
	return (1);
}
