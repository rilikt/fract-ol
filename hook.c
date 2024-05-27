/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:03:40 by timschmi          #+#    #+#             */
/*   Updated: 2024/05/27 16:39:01 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac.h"

int mouse_event(int keycode, int x, int y, t_mlx *mlx)
{
	printf("pos x: %d, pos y: %d\n", x, y);

	t_frac c;

	if (keycode == 4)
	{
		printf("yo %d\n", keycode);
		mlx->mouse_x = x;
		mlx->mouse_y = y;
		mlx->zoom_fac = 1.2;
	}
	else if (keycode == 5)
	{
		printf("ya %d\n", keycode);
		mlx->mouse_x = x;
		mlx->mouse_y = y;
		mlx->zoom_fac = 0.8;
	}
	map_and_zoom(mlx);
	mandelbrot(&c, mlx);
	return (0);
}

int exit_window(int keycode, t_mlx *mlx)
{

	// mlx_destroy_window(mlx->ptr, mlx->win);
	// free(mlx->ptr);
	exit(1);
	return (0);
}

int arrow_event(int keycode, t_mlx *mlx)
{
	t_frac c;
	printf("code:%d\n", keycode);
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
	}
	else if (keycode == 69 || keycode == 78)
	{
		if (keycode == 69)
			mlx->max_iter += 10;
		else
			mlx->max_iter -= 10;
	}
	else if (keycode == 53)
	{
		mlx_destroy_window(mlx->ptr, mlx->win);
		free(mlx->ptr);
		exit(1);
	}
	mandelbrot(&c, mlx);
	return (0);
}

void hooks(t_mlx *mlx)
{
	printf("%p\n", mlx);

	mlx_hook(mlx->win, 4, 0, &mouse_event, mlx);

	mlx_hook(mlx->win, 17, 0, &exit_window, mlx);
	mlx_hook(mlx->win, 2, 0, &arrow_event, mlx);

	mlx_hook(mlx->win, 2, 0, &arrow_event, mlx);

}
