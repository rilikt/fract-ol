/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:31:13 by timschmi          #+#    #+#             */
/*   Updated: 2024/05/30 15:09:23 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac.h"

char	*sign_and_space(char *str, int *sign)
{
	int	i;

	i = 0;
	*sign = 1;
	while (str[i] <= 32)
		i++;
	if (str[i] == '-')
		*sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	return (str + i);
}

void	check_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!((str[i] >= '0' && str[i] <= '9') || str[i] == '.'))
			error_msg();
		i++;
	}
	return ;
}

double	ft_atod(char *str)
{
	double	re;
	double	pos;
	int		i;
	int		sign;

	re = 0;
	pos = 10;
	i = 0;
	str = sign_and_space(str, &sign);
	check_str(str);
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
	return (re * sign);
}
