/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:06:50 by timschmi          #+#    #+#             */
/*   Updated: 2024/05/30 16:43:55 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac.h"

void	error_msg(void)
{
	write (2, "\n", 1);
	write (2, "Error. Please enter one of the values listed below.\n", 52);
	write (2, "\n", 1);
	write (2, "=========================\n", 26);
	write (2, "|        Fractals       |\n", 26);
	write (2, "=========================\n", 26);
	write (2, "- mandelbrot\n", 13);
	write (2, "- julia <x> <y> / e.g. x:-0.8 y:0.156\n", 38);
	write (2, "- burningship\n", 14);
	write (2, "\n", 1);
	write (2, "=========================\n", 26);
	write (2, "|        Controls       |\n", 26);
	write (2, "=========================\n", 26);
	write (2, "- 'Arrow keys' / Move view\n", 27);
	write (2, "- '+' '-' on Numpad / In- or Decrease calculations\n", 51);
	write (2, "- 'Enter' on Numpad / Switch colors to gradient\n", 48);
	write (2, "- '6' and '9' on Numpad / Change color palette\n", 47);
	write (2, "\n", 1);
	exit(1);
}
