/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:10:42 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/06/21 16:40:58 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*mall_str(unsigned long num, int *num_d, int t )
{
	char	*rtn;

	while (num > 0)
	{
		num = num / 16;
		(*num_d)++;
	}
	if (t == 2)
		*num_d += 2;
		rtn = (char *) ft_calloc(*num_d + 1, sizeof(char));
	return (rtn);
}

static char	*detohex(char *rtn, unsigned long num, int num_d, int t)
{
	char	a;

	a = 'a';
	if (t == 1)
		a = 'A';
	if (t == 2)
	{
		rtn[0] = '0';
		rtn[1] = 'x';
	}
	num_d--;
	while (num > 0)
	{
		if ((num % 16) < 10)
			rtn[num_d] = num % 16 + '0';
		else
			rtn[num_d] = num % 16 - 10 + a;
		num = num / 16;
		num_d--;
	}
	return (rtn);
}

char	*ft_itoa_hex(unsigned long num, int t)
{
	char	*rtn;
	int		num_d;

	if (t != 2)
		num = (unsigned int) num;
	num_d = 0;
	if (num == 0)
	{
		if (t == 2)
			rtn = ft_strdup("0x0");
		else
			rtn = ft_strdup("0");
		return (rtn);
	}
	rtn = mall_str(num, &num_d, t);
	if (rtn)
		rtn = detohex(rtn, num, num_d, t);
	return (rtn);
}
