/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 15:49:29 by timschmi          #+#    #+#             */
/*   Updated: 2024/05/31 12:13:44 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac.h"

void	init_values(t_mlx *mlx, char *indc, double x, double y)
{
	mlx->mv_x = 0;
	mlx->mv_y = 0;
	mlx->zoom = 1;
	mlx->zoom_fac = 1;
	mlx->mouse_x = 500;
	mlx->mouse_y = 500;
	mlx->max_iter = 20;
	mlx->color = 0;
	mlx->color_mode = 1;
	mlx->color_index1 = 0;
	mlx->color_index2 = 3;
	mlx->color_mod = 0;
	mlx->frac_indc = indc[0];
	if (indc[0] == 'j')
	{
		mlx->jul_x = x;
		mlx->jul_y = y;
	}
}

int	reset_values(t_mlx *mlx)
{
	mlx->zoom = 1;
	mlx->mv_x = 0;
	mlx->mv_y = 0;
	mlx->max_iter = 20;
	mlx->color = 0;
	mlx->color_mode = 1;
	mlx->color_index1 = 0;
	mlx->color_index2 = 7;
	mlx->color_mod = 0;
	return (0);
}

int	init_window(char *str, double x, double y)
{
	t_mlx	mlx;

	mlx.ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.ptr, 1000, 1000, str);
	mlx.img.img = mlx_new_image(mlx.ptr, 1000, 1000);
	mlx.img.addr = mlx_get_data_addr(mlx.img.img, &mlx.img.bits_per_pixel,
			&mlx.img.line_length, &mlx.img.endian);
	init_values(&mlx, str, x, y);
	hooks(&mlx);
	fractal(&mlx);
	mlx_loop(mlx.ptr);
	return (0);
}

void	better_pixel_put(t_data *data, int x, int y, int color)
{
	char	*pixel;

	pixel = data->addr + (y * data->line_length + x * (data->bits_per_pixel
				/ 8));
	*(unsigned int *)pixel = color;
}
