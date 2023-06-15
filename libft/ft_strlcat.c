/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:19:19 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/05/11 12:46:26 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	s_src;
	size_t	s_dst;
	size_t	ret;
	int		i;

	i = 0;
	s_src = ft_strlen (src);
	s_dst = ft_strlen (dst);
	if (size <= s_dst)
		return (s_src + size);
	else
		ret = s_src + s_dst;
	if (size == 0)
		return (0);
	while (s_dst < size - 1 && src[i])
		dst[s_dst++] = src[i++];
	dst[s_dst] = '\0';
	return (ret);
}
