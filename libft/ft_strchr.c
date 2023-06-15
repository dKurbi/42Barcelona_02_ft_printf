/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:04:17 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/05/16 10:34:24 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (c == '\0')
		return ((char *) &s[ft_strlen(s)]);
	while (s[i] || s[i] == c % 256)
	{
		if (c % 256 == s[i])
			return ((char *) &s[i]);
		i++;
	}
	return (NULL);
}
