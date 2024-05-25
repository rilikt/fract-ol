/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 15:10:27 by timschmi          #+#    #+#             */
/*   Updated: 2024/05/25 15:53:37 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac.h"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		//Mandelbrot
		init_window();
	}
	else if (argc == 4)
	{
		// Julia

	}
	else
	{
		write (2, "Enter the correct args.\n", 25);
		exit(1);
	}

}