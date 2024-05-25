/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 15:49:29 by timschmi          #+#    #+#             */
/*   Updated: 2024/05/25 20:21:36 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac.h"

void	init_window(void)
{
	void	*mlx;
	void	*mlx_win;
	int		x;
	int		y;
	t_data	img;
	int		red;
	int		blue;
	int		color;

	x = 0;
	y = 0;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1000, 1000, "Mandelbrot");
	img.img = mlx_new_image(mlx, 1000, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	while (x < 1000)
	{
		y = 0;
		while (y < 1000)
		{
			red = 255 - (x * 255 / 1000);
			blue = x * 255 / 1000;
			color = (red << 16) | blue;
			better_pixel_put(&img, x, y, color);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

void	better_pixel_put(t_data *data, int x, int y, int color)
{
	char *pixel;

	pixel = data->addr + (y * data->line_length + x * (data->bits_per_pixel
				/ 8));
	*(unsigned int *)pixel = color;
}