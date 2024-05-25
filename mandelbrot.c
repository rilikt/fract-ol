/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 18:32:09 by timschmi          #+#    #+#             */
/*   Updated: 2024/05/25 19:14:55 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac.h"

int calc_point(t_plane *c)
{
	int iterations = 50;
	int i = 0;
	t_plane z, temp;

	z.x = 0;
	z.y = 0;

	while (i < iterations)
	{
		temp = z;
		z.x = (z.x * z.x) - (z.y * z.y) + c->x;
		z.y = 2 * (temp.x * z.y) + c->y;
		if ((z.x * z.x) + (z.y * z.y) >= 4)
			break;
		i++;
	}
	return (i);
}

void mandelbrot()
{
	// x^2 - y^2 + 2xyi

	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1000, 1000, "Mandelbrot");
	img.img = mlx_new_image(mlx, 1000, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);

	t_plane c;

	int pixel_x = 0;
	int pixel_y = 0;

	while (pixel_x < 1000)
	{
		pixel_y = 0;
		while (pixel_y < 1000)
		{
			c.x = -2 + (double)pixel_x * (2 - (-2)) / 1000;
			c.y = 2 + (double)pixel_y * ((-2) - 2) / 1000;
			int iter = calc_point(&c);
			if (iter == 50)
				better_pixel_put(&img, pixel_x, pixel_y, 000000);
			else 
				better_pixel_put(&img, pixel_x, pixel_y, 0x00FF0000);

			pixel_y++;
		}
		pixel_x++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}