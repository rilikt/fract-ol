/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 15:49:29 by timschmi          #+#    #+#             */
/*   Updated: 2024/05/27 16:35:47 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac.h"

int init_window()
{
	t_mlx mlx;
	t_frac c;

	mlx.mv_x = 0;
	mlx.mv_y = 0;
	mlx.zoom = 1;
	mlx.zoom_fac = 1;
	mlx.mouse_x = 500;
	mlx.mouse_y = 500;
	mlx.max_iter = 20;
	mlx.ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.ptr, 1000, 1000, "Mandelbrot");
	hooks (&mlx);
	mandelbrot(&c, &mlx);
	mlx_loop(mlx.ptr);
	return (0);
}

void	better_pixel_put(t_data *data, int x, int y, int color)
{
	char *pixel;

	pixel = data->addr + (y * data->line_length + x * (data->bits_per_pixel
				/ 8));
	*(unsigned int *)pixel = color;
}