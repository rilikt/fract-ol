/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 18:32:09 by timschmi          #+#    #+#             */
/*   Updated: 2024/05/28 13:05:22 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac.h"

int calc_point(t_frac *c, t_mlx *mlx)
{
	int i = 0;
	t_frac z, temp;

	z.x = 0.0;
	z.y = 0.0;

	if (mlx->frac_indc == 'j')
	{
		z.x = c->x;
		z.y = c->y;
		c->x = mlx->jul_x;
		c->y = mlx->jul_y;
	}
	while (i < mlx->max_iter)
	{
		temp = z;
		z.x = (z.x * z.x) - (z.y * z.y) + c->x;
		z.y = 2 * (temp.x * temp.y) + c->y;
		if ((z.x * z.x) + (z.y * z.y) >= 4)
			break;
		i++;
	}
	return (i);
}

int generate_color(int iter, t_mlx *mlx)
{
	if (iter == mlx->max_iter)
		return (0);
	
	return (mlx->color * iter/mlx->max_iter);
}

void map_and_zoom(t_mlx *mlx)
{
	double off_x = (mlx->mouse_x * (4.0 / 1000.0) -2) / mlx->zoom + mlx->mv_x;
	double off_y = (mlx->mouse_y * (4.0 / 1000.0) -2) / mlx->zoom + mlx->mv_y;

	mlx->zoom *= mlx->zoom_fac;

	mlx->mv_x = off_x - (mlx->mouse_x * (4.0 / 1000.0) -2) / mlx->zoom;
	mlx->mv_y = off_y - (mlx->mouse_y * (4.0 / 1000.0) -2) / mlx->zoom;

	// printf("x:%f y: %f\n", mlx->mv_x, mlx->mv_y);
}

void mandelbrot(t_mlx *mlx)
{
	t_data	img;
	t_frac c;
	int pixel_y = 0;
	int pixel_x = 0;
	// mlx->img = &img;
	img.img = mlx_new_image(mlx->ptr, 1000, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);

	while (pixel_x < 1000)
	{
		pixel_y = 0;
		while (pixel_y < 1000)
		{
			c.x = ((pixel_x * (4.0 / 1000.0) - 2) / mlx->zoom + mlx->mv_x);
			c.y = ((1000.0 - pixel_y) * (4.0 / 1000.0) - 2) / mlx->zoom + mlx->mv_y;
			int iter = calc_point(&c , mlx);
			img.color = generate_color(iter , mlx);
			better_pixel_put(&img, pixel_x, pixel_y, img.color);
			pixel_y++;
		}
		pixel_x++;
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win, img.img, 0, 0);
}
