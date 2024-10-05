/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_move_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 17:57:29 by saberton          #+#    #+#             */
/*   Updated: 2024/10/05 18:18:58 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int put_move(t_game *game)
{
    char    *nb;

    nb = ft_itoa(game->nb_move);
    mlx_string_put(game->mlx, game->win, 10, 24, 16711935, "Number of moves : ");
    mlx_string_put(game->mlx, game->win, 120, 24, 16711935, nb);
    free(nb);
    return (1);
}