/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:03:40 by timschmi          #+#    #+#             */
/*   Updated: 2024/05/27 12:11:45 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac.h"

int mouse_event(int keycode, int x, int y, t_mlx *mlx)
{
	printf("%p\n", mlx);

	t_frac c;

	if (keycode == 4)
	{
		printf("yo %d\n", keycode);

		mlx->zoom *= 0.5;
	}
	else if (keycode == 5)
	{
		printf("ya %d\n", keycode);

		mlx->zoom *= 2.0;
	}
	mandelbrot(&c, mlx);
	return (0);
}

int close_window(int keycode, t_mlx *mlx)
{
	printf("Closing Window..\n");
	printf("code:%d\n", keycode);
	if (keycode == 53 || keycode < 0)
	{
		mlx_destroy_window(mlx->ptr, mlx->win);
		free(mlx->ptr);
		exit(1);
	}
	return (0);
}

int exit_window(int keycode, t_mlx *mlx)
{

	// mlx_destroy_window(mlx->ptr, mlx->win);
	// free(mlx->ptr);
	exit(1);
	return (0);
}

void hooks(t_mlx *mlx)
{
	printf("%p\n", mlx);

	mlx_hook(mlx->win, 4, 0, &mouse_event, mlx);

	mlx_hook(mlx->win, 17, 0, &exit_window, mlx);
	mlx_hook(mlx->win, 2, 0, &close_window, mlx);



	
}