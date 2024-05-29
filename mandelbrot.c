/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 18:32:09 by timschmi          #+#    #+#             */
/*   Updated: 2024/05/29 16:57:34 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac.h"
#include "colors.h"

int	calc_point(t_frac *c, t_mlx *mlx)
{
	int	i;
	t_frac z, temp;

	i = 0;
	z.x = 0.0;
	z.y = 0.0;
	if (mlx->frac_indc == 'j')
	{
		z.x = c->x;
		z.y = c->y;
		c->x = mlx->jul_x;
		c->y = mlx->jul_y * -1; 
	}
	while (i < mlx->max_iter)
	{
		temp = z;
		z.x = (z.x * z.x) - (z.y * z.y) + c->x;
		z.y = 2 * (temp.x * temp.y) + c->y;
		if ((z.x * z.x) + (z.y * z.y) >= 4)
			break ;
		i++;
	}
	return (i);
}

int	calc_burn(t_frac *c, t_mlx *mlx)
{
	int	i;
	t_frac z, temp;

	i = 0;
	z.x = 0.0;
	z.y = 0.0; 

	while (i < mlx->max_iter)
	{
		if ((z.x * z.x) + (z.y * z.y) > 4)
			break ;
		temp.x = fabs(z.x);
		temp.y = fabs(z.y);
		
		z.x = (temp.x * temp.x) - (temp.y * temp.y) + c->x;
		z.y = 2 * (temp.x * temp.y) + c->y;
		i++;
	}
	return (i);
}

int interpolate(int color1, int color2, double factor)
{
	t_color c1, c2, re;
	c1.r = (color1 >> 16) & 0xFF;
	c1.g = (color1 >> 8) & 0xFF;
	c1.b = color1 & 0xFF;

	c2.r = (color2 >> 16) & 0xFF;
	c2.g = (color2 >> 8) & 0xFF;
	c2.b = color2 & 0xFF;

	re.r = (int)(c1.r + factor * (c2.r - c1.r));
	re.g = (int)(c1.g + factor * (c2.g - c1.g));
	re.b = (int)(c1.b + factor * (c2.b - c1.b));

	return ((re.r << 16) | (re.g << 8) | re.b);

}

int	generate_color(int iter, t_mlx *mlx)
{
	if (iter == mlx->max_iter)
		return (0);

	int index = iter % 8;	
	double factor = (double)iter / (double)mlx->max_iter;
	if (mlx->color_mode)
		return (palettes[mlx->color][index]);
	else
		return (interpolate(palettes[mlx->color][mlx->color_index1], palettes[mlx->color + mlx->color_mod][mlx->color_index2], factor));
}

void	map_and_zoom(t_mlx *mlx)
{
	double	off_x;
	double	off_y;

	off_x = (mlx->mouse_x * (4.0 / 1000.0) - 2) / mlx->zoom + mlx->mv_x;
	off_y = (mlx->mouse_y * (4.0 / 1000.0) - 2) / mlx->zoom + mlx->mv_y;
	mlx->zoom *= mlx->zoom_fac;
	mlx->mv_x = off_x - (mlx->mouse_x * (4.0 / 1000.0) - 2) / mlx->zoom;
	mlx->mv_y = off_y - (mlx->mouse_y * (4.0 / 1000.0) - 2) / mlx->zoom;
}

void	mandelbrot(t_mlx *mlx)
{
	t_data	img;
	t_frac	c;
	int		pixel_y;
	int		pixel_x;
	int		iter;
	
	pixel_y = 0;
	pixel_x = 0;
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
			c.y = ((pixel_y * (4.0 / 1000.0) - 2) / mlx->zoom + mlx->mv_y);
			if (mlx->frac_indc == 'b')
				iter = calc_burn(&c, mlx);
			else
				iter = calc_point(&c, mlx);
			img.color = generate_color(iter, mlx);
			better_pixel_put(&img, pixel_x, pixel_y, img.color);
			pixel_y++;
		}
		pixel_x++;
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win, img.img, 0, 0);
}
