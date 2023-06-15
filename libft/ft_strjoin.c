/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:56:41 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/05/25 16:21:35 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*rtn;
	int		i;
	int		j;
	int		leng;

	leng = ft_strlen(s1) + ft_strlen(s2);
	rtn = (char *) malloc((leng + 1) * sizeof (char));
	if (!rtn)
		return (NULL);
	i = 0;
	while (s1[i])
	{	
		rtn[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		rtn[i++] = s2[j++];
	rtn[i] = '\0';
	return (rtn);
}
