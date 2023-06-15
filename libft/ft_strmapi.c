/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:37:35 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/05/31 16:51:07 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*mall_str(const char *s)
{
	int		l;
	char	*rtn;

	l = ft_strlen(s);
	rtn = (char *) ft_calloc(l + 1, sizeof(char));
	return (rtn);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*rtn;

	rtn = mall_str(s);
	if (rtn == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		rtn[i] = f(i, s[i]);
		i++;
	}
	return (rtn);
}
