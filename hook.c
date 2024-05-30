/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:03:40 by timschmi          #+#    #+#             */
/*   Updated: 2024/05/30 15:11:22 by timschmi         ###   ########.fr       */
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

int	exit_window(t_mlx *mlx)
{
	mlx_destroy_image(mlx->ptr, mlx->img.img);
	mlx_destroy_window(mlx->ptr, mlx->win);
	free(mlx->ptr);
	exit(1);
	return (0);
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
		mlx->max_iter -= 10;
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
