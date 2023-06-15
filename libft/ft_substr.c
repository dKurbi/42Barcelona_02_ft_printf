/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 12:39:15 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/05/29 18:03:59 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*rtn;
	size_t	slen;

	slen = ft_strlen(s);
	if ((len < 1) || (start >= slen))
	{
		rtn = (char *) ft_calloc (1, sizeof(char));
		if (rtn == NULL)
			return (NULL);
		rtn[0] = '\0';
		return (rtn);
	}
	if (slen < len)
		len = slen;
	if (len > slen - start)
		len = slen - start;
	rtn = (char *) ft_calloc((len + 1), sizeof (char));
	if (rtn == NULL)
		return (NULL);
	ft_strlcpy(rtn, &s[start], len + 1);
	rtn[len] = '\0';
	return (rtn);
}
