/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:25:43 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/06/21 16:41:28 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*mall_str(unsigned int n, int *num_d)
{
	char	*rtn;

	while (n > 0)
	{
		n = n / 10;
		(*num_d)++;
	}
	rtn = (char *) ft_calloc (*num_d + 1, sizeof(char));
	return (rtn);
}

static char	*write_num(char *rtn, unsigned int n, int num_d)
{
	num_d--;
	while (n > 0)
	{
		rtn[num_d--] = n % 10 + '0';
		n = n / 10;
	}
	return (rtn);
}

char	*ft_itoa_u(unsigned int n)
{
	char	*rtn;
	int		num_d;

	if (n == 0)
	{
		rtn = ft_strdup("0");
		return (rtn);
	}
	num_d = 0;
	rtn = mall_str(n, &num_d);
	if (rtn == NULL)
		return (NULL);
	rtn = write_num(rtn, n, num_d);
	return (rtn);
}
