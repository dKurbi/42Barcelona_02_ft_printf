/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:36:26 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/05/17 14:51:44 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	init_var(size_t *l, char *str, char *c, size_t *i)
{
	l[0] = ft_strlen(str);
	l[1] = ft_strlen(c);
	*i = 0;
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*str;
	char	*c;
	size_t	l[2];
	size_t	i;
	char	*rtn;

	str = (char *) haystack;
	c = (char *) needle;
	init_var(l, str, c, &i);
	if (l[1] == 0)
		return (str);
	else if (l[1] > len)
		return (NULL);
	if ((int) len < 0)
		len = l[0];
	while (i < len)
	{
		rtn = ft_memchr(&str[i], c[0], l[0] - i);
		if (!rtn || rtn + l[1] > str + len)
			return (NULL);
		if (!ft_memcmp(rtn, c, l[1]))
			return (rtn);
	i++;
	}
	return (NULL);
}
