/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:07:20 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/05/10 15:05:04 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*str_src;
	unsigned char		*str_dest;

	if (!src && !dest)
		return (dest);
	str_src = src;
	str_dest = dest;
	i = 0;
	while (i++ < n)
		str_dest[i - 1] = str_src[i - 1];
	return (dest);
}
