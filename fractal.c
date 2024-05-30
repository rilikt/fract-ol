/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 18:32:09 by timschmi          #+#    #+#             */
/*   Updated: 2024/05/30 15:10:50 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac.h"

int	calc_point(t_frac *c, t_mlx *mlx)
{
	t_frac	z;
	t_frac	temp;
	int		i;

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
	t_frac	z;
	t_frac	temp;
	int		i;

	i = 0;
	z.x = 0.0;
	z.y = 0.0;
	while (i < mlx->max_iter)
	{
		if ((z.x * z.x) + (z.y * z.y) >= 4)
			break ;
		temp.x = fabs(z.x);
		temp.y = fabs(z.y);
		z.x = (temp.x * temp.x) - (temp.y * temp.y) + c->x;
		z.y = 2 * (temp.x * temp.y) + c->y;
		i++;
	}
	return (i);
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

void	fractal(t_mlx *mlx)
{
	t_frac	c;
	t_pixel	pixel;
	int		iter;

	pixel.x = 0;
	pixel.y = 0;
	while (pixel.x < 1000)
	{
		pixel.y = 0;
		while (pixel.y < 1000)
		{
			c.x = ((pixel.x * (4.0 / 1000.0) - 2) / mlx->zoom + mlx->mv_x);
			c.y = ((pixel.y * (4.0 / 1000.0) - 2) / mlx->zoom + mlx->mv_y);
			if (mlx->frac_indc == 'b')
				iter = calc_burn(&c, mlx);
			else
				iter = calc_point(&c, mlx);
			mlx->img.color = generate_color(iter, mlx);
			better_pixel_put(&mlx->img, pixel.x, pixel.y, mlx->img.color);
			pixel.y++;
		}
		pixel.x++;
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.img, 0, 0);
}
