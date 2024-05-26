/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:03:40 by timschmi          #+#    #+#             */
/*   Updated: 2024/05/26 19:05:47 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac.h"

int mouse_event(int keycode, t_mlx *mlx)
{
	printf("%p\n", mlx);

	t_frac c;

	if (keycode == 4)
	{
		printf("yo %d\n", keycode);

		c.zoom = 2.0;
	}
	else if (keycode == 5)
	{
		printf("ya %d\n", keycode);

		c.zoom = 0.5;
	}
	mandelbrot(&c, mlx);
	return (0);
}

void hooks(t_mlx *mlx)
{
	printf("%p\n", mlx);

	mlx_mouse_hook(mlx->win, &mouse_event, mlx);
}