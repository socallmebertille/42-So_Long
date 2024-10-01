/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:14:05 by saberton          #+#    #+#             */
/*   Updated: 2024/10/01 17:24:43 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	fill(char **map, t_player size, t_player cur)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x)
		return ;
	if (map[cur.y][cur.x] == '0')
		map[cur.y][cur.x] = 'S';
    if (map[cur.y][cur.x] == 'E')
		return ;
	fill(map, size, (t_player){cur.x - 1, cur.y});
	fill(map, size, (t_player){cur.x + 1, cur.y});
	fill(map, size, (t_player){cur.x, cur.y - 1});
	fill(map, size, (t_player){cur.x, cur.y + 1});
}

static void	flood_fill(t_game *game)
{
	t_player	size;
	t_player	begin;

	size.x = game->height;
	size.y = game->width;
	begin = game->player;
	fill(game->check_map, size, begin);
}

int	flood_fill_check(t_game *game)
{
	// t_player    p;
	// char        **map;

	flood_fill(game);
	// map = game->check_map;
	// p = game->player;
	// while (map[p.y][p.x] == 'S')
	// {
	// 	if (map[p.y + 1][p.x] == 'E' || map[p.y - 1][p.x] == 'E' || map[p.y][p.x
	// 		+ 1] == 'E' || map[p.y][p.x - 1] == 'E')
	// 		return (1);
	// }
    int i = 0;
    while (game->check_map[i])
    {
        ft_printf("%s\n", game->check_map[i]);
        i++;
    }
	return (1);
}