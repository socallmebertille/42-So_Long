/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_file_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 09:54:21 by saberton          #+#    #+#             */
/*   Updated: 2024/10/07 12:54:33 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static char	*get_map(int fd)
{
	char	*map_line;
	char	*buffer;
	char	*tmp;
	int		read_bits;

	buffer = ft_calloc((10000 + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	read_bits = 1;
	map_line = ft_strdup("");
	while (read_bits)
	{
		read_bits = (read(fd, buffer, 10000));
		if (read_bits == -1)
			return (free(map_line), free(buffer), NULL);
		buffer[read_bits] = '\0';
		tmp = map_line;
		map_line = ft_strjoin(map_line, buffer);
		free(tmp);
	}
	if (!map_line || !map_line[0])
		return (free(map_line), free(buffer), NULL);
	return (free(buffer), close(fd), map_line);
}

static int	type_file(char *map, t_game *game)
{
	int	fd;

	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		ft_printf(RED NO_MAP RESET);
		close_window_bonus(game);
	}
	if (ft_strncmp(map + (ft_strlen(map) - 4), ".ber", 4) != 0)
	{
		ft_printf(RED WRONG_TYPE RESET);
		close_window_bonus(game);
		return (1);
	}
	return (fd);
}

int	valid_file_bonus(char *map, t_game *game)
{
	int		fd;
	char	*map_line;

	fd = type_file(map, game);
	map_line = get_map(fd);
	if (!map_line)
		return (close(fd), ft_printf(RED WRONG_READING RESET),
			close_window_bonus(game), 0);
	if (ft_strnstr(map_line, "\n\n", ft_strlen(map_line)) || map_line[0] == '\n'
		|| map_line[ft_strlen(map_line) - 1] == '\n')
		return (free(map_line), ft_printf(RED FEW_NEW_LINE RESET),
			close_window_bonus(game), 0);
	game->check_map = ft_split(map_line, '\n');
	game->map = ft_split(map_line, '\n');
	if (!game->check_map || !game->map)
		return (free(map_line), close_window_bonus(game), 0);
	if (!valid_map_bonus(game))
		return (free(map_line), close_window_bonus(game), 0);
	return (free(map_line), 0);
}
