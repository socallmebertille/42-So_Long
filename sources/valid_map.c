/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 09:54:21 by saberton          #+#    #+#             */
/*   Updated: 2024/09/30 12:24:02 by saberton         ###   ########.fr       */
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
	map_line = NULL;
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

static void	type_file(char *map)
{
	if (ft_strncmp(map + (ft_strlen(map) - 4), ".ber", 4) != 0)
		return (ft_printf("%s\n", map + (ft_strlen(map) - 4)), ft_printf("The type's map need to be in \".ber\"\n"), exit(EXIT_FAILURE));
}

int	valid_map(char *map, t_game *game)
{
	int		fd;
	char	*map_line;

	type_file(map);
	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("The map doesn't exist.\n");
		exit(EXIT_FAILURE);
	}
	map_line = get_map(fd);
	if (!map_line)
		return (close(fd), ft_printf("There is an issue in the map.\n"),
			exit(EXIT_FAILURE), 0); // ajt fct gestion err
	if (ft_strnstr(map_line, "\n\n", ft_strlen(map_line)))
		return (free(map_line), ft_printf("The map contain too much '\\n'.\n"),
			exit(EXIT_FAILURE), 0);
	game->check_map = ft_split(map_line, '\n');
	game->map = ft_split(map_line, '\n');
	if (!game->check_map || !game->map)
		return (free(map_line), exit(EXIT_FAILURE), 0); //ajt fct erreur pr free
	free(map_line);
	return (0);
}
