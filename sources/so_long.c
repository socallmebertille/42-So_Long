/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:11:38 by saberton          #+#    #+#             */
/*   Updated: 2024/09/24 15:43:40 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

static int	key_hook(int keycode, t_vars *vars)
{
	ft_printf("You've pressed : [%d] on your keyboard !\n", keycode);
	return (0);
}

static int	mouse_hook(int mousecode, t_vars *vars)
{
	ft_printf("Your id click : [%d]\n", mousecode);
	return (0);
}

static int render_next_frame(t_data *img)
{
	int x;
	int y;
	
	x = 0;
	y = 5;
	while (x < 1920)
	{
		my_mlx_pixel_put(img, x, y, 0x00FF0000);
		x++;
	}
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_vars	*vars;
	t_data *img;

	// if (ac != 2)
	// 	return (ft_printf("ERROR : You have to choose a map as 2nd arg!\n"), 0);
	vars = (t_vars *)malloc(sizeof(t_vars));
	if (!vars)
		return (1);
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 1920, 1080, "First window");
	img = (t_data *)malloc(sizeof(t_data));
	if (!img)
		return (1);
	img->img = mlx_new_image(vars->mlx, 1920, 1080);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length,
			&img->endian);
	img->mlx = vars->mlx;
	img->win = vars->win;
	mlx_key_hook(vars->win, key_hook, &vars);
	mlx_mouse_hook(vars->win, mouse_hook, &vars);
	mlx_loop_hook(vars->mlx, render_next_frame, img);
	mlx_put_image_to_window(vars->mlx, vars->win, img->img, 0, 0);
	mlx_loop(vars->mlx);
	free(img);
}