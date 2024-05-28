/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:31:13 by timschmi          #+#    #+#             */
/*   Updated: 2024/05/28 13:19:03 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac.h"

double	ft_atod(char *str)
{
	double	re;
	double	pos;
	int		i;

	re = 0;
	pos = 10;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9') && str[i] != '.')
	{
		re = re * 10 + str[i] - '0';
		i++;
	}
	i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		re += (double)(str[i] - '0') / pos;
		pos *= 10;
		i++;
	}
	if (str[0] == '-')
		re *= -1;
	return (re);
}
