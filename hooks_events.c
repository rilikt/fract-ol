/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:03:40 by timschmi          #+#    #+#             */
/*   Updated: 2024/05/31 12:14:31 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac.h"

int	mouse_event(int keycode, int x, int y, t_mlx *mlx)
{
	if (keycode == 4)
	{
		mlx->mouse_x = x;
		mlx->mouse_y = y;
		mlx->zoom_fac = 1.2;
		map_and_zoom(mlx);
	}
	else if (keycode == 5)
	{
		mlx->mouse_x = x;
		mlx->mouse_y = y;
		mlx->zoom *= 0.8;
	}
	fractal(mlx);
	return (0);
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

int	exit_window(t_mlx *mlx)
{
	mlx_destroy_image(mlx->ptr, mlx->img.img);
	mlx_destroy_window(mlx->ptr, mlx->win);
	free(mlx->ptr);
	exit(1);
	return (0);
}

int	key_event(int keycode, t_mlx *mlx)
{
	if (keycode == 125)
		mlx->mv_y += 0.25 / mlx->zoom;
	else if (keycode == 126)
		mlx->mv_y -= 0.25 / mlx->zoom;
	else if (keycode == 124)
		mlx->mv_x += 0.25 / mlx->zoom;
	else if (keycode == 123)
		mlx->mv_x -= 0.25 / mlx->zoom;
	else if (keycode == 117)
		reset_values(mlx);
	else if (keycode == 53)
		exit_window(mlx);
	else if (keycode == 69)
		mlx->max_iter += 10;
	else if (keycode == 78)
	{
		if (mlx->max_iter > 10)
			mlx->max_iter -= 10;
	}
	else
		color_event(keycode, mlx);
	fractal(mlx);
	return (0);
}

void	hooks(t_mlx *mlx)
{
	mlx_hook(mlx->win, 4, 0, &mouse_event, mlx);
	mlx_hook(mlx->win, 17, 0, &exit_window, mlx);
	mlx_hook(mlx->win, 2, 0, &key_event, mlx);
}
