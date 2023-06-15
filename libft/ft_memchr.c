/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:05:08 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/05/16 14:33:38 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int value, size_t num)
{
	unsigned char	*src;
	size_t			i;
	unsigned char	c;

	i = 0;
	src = (unsigned char *) ptr;
	c = (unsigned char) value;
	while (i < num)
	{
		if (c == src[i])
			return ((void *) &src[i]);
		i++;
	}
	return (NULL);
}
