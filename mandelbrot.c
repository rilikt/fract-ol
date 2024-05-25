/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 18:32:09 by timschmi          #+#    #+#             */
/*   Updated: 2024/05/25 20:20:22 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac.h"

int calc_point(t_plane *c, int max_iter)
{
	int i = 0;
	t_plane z, temp;

	z.x = 0;
	z.y = 0;

	while (i < max_iter)
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

int generate_color(int iter, int max_iter)
{
	if (iter == max_iter)
		return (0);
	
	int color_palette[16] = {	0xFF0000, 0xFF7F00, 0xFFFF00, 0x7FFF00,
								0x00FF00, 0x00FF7F, 0x00FFFF, 0x007FFF,
								0x0000FF, 0x7F00FF, 0xFF00FF, 0xFF007F,
								0xFFFFFF, 0xC0C0C0, 0x808080, 0x404040
							};

	int index_palette = (iter * 16) / max_iter;

	return (color_palette[index_palette]);
}

void mandelbrot()
{
	// x^2 - y^2 + 2xyi

	void	*mlx;
	void	*mlx_win;
	int color;
	int max_iter = 100;
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
			c.x = -2 + pixel_x * (2.5 / 1000.0);
			c.y = 2 - pixel_y * (4.0 / 1000.0);
			int iter = calc_point(&c , max_iter);
			color = generate_color(iter , max_iter);
			better_pixel_put(&img, pixel_x, pixel_y, color);
			pixel_y++;
		}
		pixel_x++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}