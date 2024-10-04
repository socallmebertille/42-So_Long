/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 09:54:21 by saberton          #+#    #+#             */
/*   Updated: 2024/10/04 15:47:39 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

static void	type_file(char *map, t_game *game)
{
	if (ft_strncmp(map + (ft_strlen(map) - 4), ".ber", 4) != 0)
	{
		ft_printf("The type's map need to be in \".ber\"\n");
		close_window(game);
		return ;
	}
}

int	valid_file(char *map, t_game *game)
{
	int		fd;
	char	*map_line;

	type_file(map, game);
	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("The map doesn't exist.\n");
		close_window(game);
	}
	map_line = get_map(fd);
	if (!map_line)
		return (close(fd), ft_printf("There is an issue in the map.\n"),
			close_window(game), 0);
	if (ft_strnstr(map_line, "\n\n", ft_strlen(map_line)) || map_line[0] == '\n'
		|| map_line[ft_strlen(map_line) - 1] == '\n')
		return (free(map_line), ft_printf("The map contain too much '\\n'.\n"),
			close_window(game), 0);
	game->check_map = ft_split(map_line, '\n');
	game->map = ft_split(map_line, '\n');
	if (!game->check_map || !game->map)
		return (free(map_line), close_window(game), 0);
	if (!valid_map(game))
		return (free(map_line), close_window(game), 0);
	return (free(map_line), 0);
}
