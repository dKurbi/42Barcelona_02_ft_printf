/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:29:04 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/05/15 14:30:02 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	initnum(const char *str, int *sign, int *number)
{
	int	i;

	*number = 0;
	i = 0;
	*sign = 1;
	while ((str[i] > 8 && str [i] < 14) || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		i++;
		*sign = -1;
	}
	else if (str[i] == '+')
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	number;
	int	sign;

	i = initnum(str, &sign, &number);
	while (str[i] && ft_isdigit(str[i]))
	{
		if ((number >= 214748364) && ((str[i] - '0') > 7))
		{
			if (sign > 0)
				return (2147483647);
			else
				return (-2147483648);
		}
		else
			number = (number * 10) + (str[i] - '0');
	i++;
	}
	return (number * sign);
}
