/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:03:40 by timschmi          #+#    #+#             */
/*   Updated: 2024/05/28 13:05:44 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac.h"

int mouse_event(int keycode, int x, int y, t_mlx *mlx)
{
	if (keycode == 4)
	{
		mlx->mouse_x = x;
		mlx->mouse_y = y;
		mlx->zoom_fac = 1.2;
	}
	else if (keycode == 5)
	{
		mlx->mouse_x = x;
		mlx->mouse_y = y;
		mlx->zoom_fac = 0.8;
	}
	map_and_zoom(mlx);
	mandelbrot(mlx);
	return (0);
}

int exit_window(t_mlx *mlx)
{
	// mlx_destroy_image(mlx->ptr, mlx->img);
	mlx_destroy_window(mlx->ptr, mlx->win);
	free(mlx->ptr);
	exit(1);
	return (0);
}

int arrow_event(int keycode, t_mlx *mlx)
{
	// printf("code: %d\n", keycode);
	
	if (keycode == 125)
		mlx->mv_y += 0.25 / mlx->zoom;
	else if (keycode == 126)
		mlx->mv_y -= 0.25 / mlx->zoom;
	else if (keycode == 124)
		mlx->mv_x += 0.25 / mlx->zoom;
	else if (keycode == 123)
		mlx->mv_x -= 0.25 / mlx->zoom;
	else if (keycode == 117)
	{
		mlx->zoom = 1;
		mlx->mv_x = 0;
		mlx->mv_y = 0;
		mlx->max_iter = 20;
	}
	else if (keycode == 88)
		mlx->color -= 1;
	else if (keycode == 92)
		mlx->color += 1;
	else if (keycode == 69 || keycode == 78)
	{
		if (keycode == 69)
			mlx->max_iter += 10;
		else
			mlx->max_iter -= 10;
	}
	else if (keycode == 53)
	{
		// mlx_destroy_image(mlx->ptr, mlx->img);
		mlx_destroy_window(mlx->ptr, mlx->win);
		free(mlx->ptr);
		exit(1);
	}
	mandelbrot(mlx);
	return (0);
}

void hooks(t_mlx *mlx)
{
	mlx_hook(mlx->win, 4, 0, &mouse_event, mlx);
	mlx_hook(mlx->win, 17, 0, &exit_window, mlx);
	mlx_hook(mlx->win, 2, 0, &arrow_event, mlx);
}
