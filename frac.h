/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 15:09:00 by timschmi          #+#    #+#             */
/*   Updated: 2024/05/29 14:48:01 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAC_H
# define FRAC_H

#include "libft/libft.h"
#include "mlx/mlx.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

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
	double zoom;
	double zoom_fac;
	double mv_y;
	double mv_x;
	int mouse_x;
	int mouse_y;
	int max_iter;
	int color;
	int color_mode;
	int color_index1;
	int color_index2;
	int color_mod;
	double jul_x;
	double jul_y;
	char frac_indc;
	t_data *img;
}	t_mlx;

typedef struct s_plane {
	double x;
	double y;
} t_frac;

int init_window(char *str, double x, double y);
void better_pixel_put (t_data *data, int x, int y, int color);
void mandelbrot(t_mlx *mlx);
int mouse_event(int keycode, int x, int y, t_mlx *mlx);
void hooks(t_mlx *mlx);
void map_and_zoom(t_mlx *mlx);
double ft_atod(char *str);

#endif