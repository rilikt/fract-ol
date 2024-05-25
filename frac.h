/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 15:09:00 by timschmi          #+#    #+#             */
/*   Updated: 2024/05/25 18:54:22 by timschmi         ###   ########.fr       */
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
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_plane {
	double x;
	double y;
} t_plane;

void init_window(void);
void better_pixel_put (t_data *data, int x, int y, int color);
void mandelbrot();


#endif