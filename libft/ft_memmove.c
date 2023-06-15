/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:42:50 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/05/10 15:33:46 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char		*new_src;
	unsigned char			*new_dest;

	if (!src && !dest)
		return (dest);
	if (src > dest)
	{
		ft_memcpy(dest, src, n);
		return (dest);
	}
	new_src = src;
	new_dest = dest;
	while (0 < n--)
		new_dest[n] = new_src[n];
	return (dest);
}
