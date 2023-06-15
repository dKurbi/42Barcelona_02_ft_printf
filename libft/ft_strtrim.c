/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:23:52 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/05/29 13:52:16 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(char const *s1, char const *set)
{
	int	c;
	int	i;
	int	len;

	i = 0;
	c = 0;
	len = ft_strlen(s1);
	while (ft_strchr(set, s1[i++]) && c < len)
		c++;
	if (c >= len)
		return (0);
	i = 1;
	while (ft_strchr(set, s1[len - i++]) && c < len)
		c++;
	return (len - c);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	int		i;
	int		j;
	char	*rtn;

	if (!s1 || !set)
		return (NULL);
	len = count(s1, set);
	rtn = (char *) ft_calloc ((len + 1), sizeof(char));
	if (rtn == NULL)
		return (NULL);
	if (len == 0)
	{
		rtn[0] = '\0';
		return (rtn);
	}
	i = 0;
	while (ft_strchr(set, s1[i]))
		i++;
	j = 0;
	while (j < len)
		rtn[j++] = s1[i++];
	rtn[j] = '\0';
	return (rtn);
}
