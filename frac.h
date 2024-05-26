/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 15:09:00 by timschmi          #+#    #+#             */
/*   Updated: 2024/05/26 19:05:30 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAC_H
# define FRAC_H

#include "libft/libft.h"
#include "mlx/mlx.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct	s_data {
	int color;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_mlx {
	void *ptr;
	void *win;
}	t_mlx;

typedef struct s_plane {
	double x;
	double y;
	double zoom;
} t_frac;

int init_window();
void better_pixel_put (t_data *data, int x, int y, int color);
void mandelbrot(t_frac *c, t_mlx *mlx);
int mouse_event(int keycode, t_mlx *mlx);
void hooks(t_mlx *mlx);

#endif