/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:12:21 by timschmi          #+#    #+#             */
/*   Updated: 2024/05/30 16:29:00 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac.h"

int	interpolate(int color1, int color2, double factor)
{
	t_color	c1;
	t_color	c2;
	t_color	re;

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

unsigned int	palette(int i, int j)
{
	unsigned int	p[5][4];

	p[0][0] = 0xFFFFFF;
	p[0][1] = 0xC0C0C0;
	p[0][2] = 0x808080;
	p[0][3] = 0x404040;
	p[1][0] = 0x0000FF;
	p[1][1] = 0x00FFFF;
	p[1][2] = 0x00FF00;
	p[1][3] = 0xFFFF00;
	p[2][0] = 0xFFA500;
	p[2][1] = 0xFF0000;
	p[2][2] = 0x8B00FF;
	p[2][3] = 0xFF00FF;
	p[3][0] = 0x00FF00;
	p[3][1] = 0x7FFF00;
	p[3][2] = 0x32CD32;
	p[3][3] = 0x008000;
	p[4][0] = 0xFF6347;
	p[4][1] = 0xFF4500;
	p[4][2] = 0xFFD700;
	p[4][3] = 0xFFA07A;
	return (p[i][j]);
}

int	generate_color(int iter, t_mlx *mlx)
{
	int		index;
	double	factor;

	if (iter == mlx->max_iter)
		return (0);
	index = iter % 4;
	factor = (double)iter / (double)mlx->max_iter;
	if (mlx->color_mode)
		return (palette(mlx->color, index));
	else
		return (interpolate(palette(mlx->color, mlx->color_index1),
				palette(mlx->color + mlx->color_mod, mlx->color_index2),
				factor));
}

int	color_event2(int keycode, t_mlx *mlx)
{
	if (keycode == 87)
	{
		mlx->color_index2 += 1;
		if (mlx->color_index2 > 3)
			mlx->color_index2 = 0;
	}
	else if (keycode == 91)
	{
		mlx->color_index1 += 1;
		if (mlx->color_index1 > 3)
			mlx->color_index1 = 0;
	}
	else if (keycode == 86)
	{
		if (mlx->color_mod + mlx->color >= 4)
			return (0);
		mlx->color_mod += 1;
	}
	else if (keycode == 89)
	{
		if (mlx->color_mod + mlx->color != 0)
			mlx->color_mod -= 1;
	}
	return (0);
}

int	color_event(int keycode, t_mlx *mlx)
{
	if (keycode == 92)
	{
		if (mlx->color != 0)
			mlx->color -= 1;
	}
	else if (keycode == 88)
	{
		if (mlx->color >= 4)
			return (0);
		mlx->color += 1;
	}
	else if (keycode == 76)
	{
		if (mlx->color_mode)
			mlx->color_mode = 0;
		else
			mlx->color_mode = 1;
	}
	else
		color_event2(keycode, mlx);
	return (0);
}
