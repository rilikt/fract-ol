/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 15:10:27 by timschmi          #+#    #+#             */
/*   Updated: 2024/05/29 11:23:07 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac.h"

int main(int argc, char **argv)
{
	
	if (argc == 2 && ft_strncmp(argv[1], "mandelbrot", 10) == 0 && ft_strlen(argv[1]) == 10)
		init_window(argv[1], 0.0 , 0.0);
	else if (argc == 4 && ft_strncmp(argv[1], "julia", 5) == 0 && ft_strlen(argv[1]) == 5)
		init_window(argv[1], ft_atod(argv[2]), ft_atod(argv[3]));
	else if (argc == 2 && ft_strncmp(argv[1], "burningship", 11) == 0 && ft_strlen(argv[1]) == 11)
		init_window(argv[1], 0.0 , 0.0);
	else
	{
		write (2, "Enter the correct args.\n", 25);
		exit(1);
	}
	return (0);
}
