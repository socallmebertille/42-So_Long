/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:11:38 by saberton          #+#    #+#             */
/*   Updated: 2024/09/28 16:41:10 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static void	my_mlx_pixel_put(t_game *data, int x, int y, int color)
// {
// 	char	*dst;
// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }

static int	key_hook(int keycode)
{
	ft_printf("You've pressed : [%d] on your keyboard !\n", keycode);
	return (0);
}

static int	mouse_hook(int mousecode)
{
	ft_printf("Your id click : [%d]\n", mousecode);
	return (0);
}

// static int	render_next_frame(t_data *img)
// {
// 	int			x;
// 	int			y;
// 	int			colors[3] = {0x00FF0000, 0x0000FF00, 0x000000FF};
// 	static int	i = 0;

// 	x = 0;
// 	while (x < 1920)
// 	{
// 		y = 0;
// 		while (y < 1080)
// 		{
// 			my_mlx_pixel_put(img, x, y, colors[i]);
// 			y++;
// 		}
// 		x++;
// 	}
// 	i++;
// 	if (i == 4)
// 		i = 0;
// 	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
// 	return (0);
// }

// static int	put_img_map(t_game *img)
// {
	
// }

static int close_window(void *param)
{
    (void)param; // Si tu n'as pas besoin de paramètre, tu peux ignorer l'avertissement avec ce cast
    exit(0);     // Appel à exit pour terminer le programme
    return (0);  // Retourne 0 comme attendu par mlx_hook
}

int	main(int ac, char **av)
{
	t_game *game;

	if (ac != 2)
		return (ft_printf("ERROR : You have to choose a map as 2nd arg!\n"), 0);
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (1);
	valid_map(av[1], game);
	put_img_map(game);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 1920, 1080, "So_Long");
	// img = (t_data *)malloc(sizeof(t_data));
	// if (!img)
	// 	return (1);
	// img->img = mlx_new_image(vars->mlx, 1920, 1080);
	// img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
	// 		&img->line_length, &img->endian);
	// img->mlx = vars->mlx;
	// img->win = vars->win;
	mlx_key_hook(game->win, key_hook, &game);
	mlx_mouse_hook(game->win, mouse_hook, &game);
	// mlx_loop_hook(vars->mlx, render_next_frame, img); rainbow screen
	// mlx_loop_hook(vars->mlx, circle_can_move, img); circle screen
	// mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	mlx_hook(game->win, 33, 0, close_window, game);
	mlx_loop(game->mlx);
}