/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:48:52 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/05/29 18:03:26 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**mall_lines(char const *s, char c)
{	
	int		i;
	int		wc;
	char	**rtn;

	i = 0;
	wc = 1;
	while (s[i])
	{
		if (s[i] == c)
		{
			wc++;
			while (s[i + 1] == c)
				i++;
		}
	i++;
	}
	rtn = (char **) ft_calloc((wc + 1), sizeof(char *));
	if (rtn == NULL)
		return (NULL);
	return (rtn);
}

static char	**copy_str(char const *s, char **rtn, char c)
{
	int	i[3];

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	while (s[i[0]])
	{	
		if (s[i[0]] == c)
		{
			rtn[i[1]][i[2]] = '\0';
			i[2] = 0;
			i[1]++;
			while (s[i[0]] == c)
				i[0]++;
		}
		else
		{	
			rtn[i[1]][i[2]] = s[i[0]];
			i[2]++;
			i[0]++;
		}
	}
	return (rtn);
}

static int	init_free_finish(char **rtn, int *cc, int p)
{
	if (p == 0)
	{
		cc[0] = 0;
		cc[1] = 0;
		return (0);
	}
	if (p == 2)
	{
		rtn[cc[1]] = (char *) ft_calloc ((cc[0] + 1), sizeof(char));
		if (rtn[cc[1]] == NULL)
			p = 1;
		else
		{
			return (0);
		}
	}
	if (p == 1)
	{
		while (cc[1] >= 0)
			free(rtn[cc[1]--]);
		free (rtn);
		return (1);
	}
	return (0);
}

static char	**mall_words(const char *s, char **rtn, char c)
{
	int		i;
	int		cc[2];

	i = init_free_finish(rtn, cc, 0);
	while (s[i])
	{
		if (s[i] == c)
		{
			rtn[cc[1]] = (char *) ft_calloc ((cc[0] + 1), sizeof (char));
			if (rtn[cc[1]] == NULL)
			{
				init_free_finish(rtn, cc, 1);
				return (NULL);
			}
			cc[0] = 0;
			cc[1]++;
			while (s[i + 1] == c)
				i++;
		}		
		else
			cc[0]++;
	i++;
	}
	(init_free_finish(rtn, cc, 2) && (rtn = NULL));
	return (rtn);
}	

char	**ft_split(char const *s, char c)
{
	char	**rtn;
	char	d[2];
	char	*str;

	if (s == NULL)
		return (NULL);
	d[0] = c;
	d[1] = '\0';
	str = ft_strtrim(s, d);
	if (str == NULL)
		return (NULL);
	if (ft_strlen(str) == 0)
	{
		rtn = (char **) ft_calloc (1, sizeof(char *));
		free(str);
		return (rtn);
	}
	rtn = mall_lines(str, c);
	if (rtn != NULL)
		rtn = mall_words(str, rtn, c);
	if (rtn != NULL)
		rtn = copy_str(str, rtn, c);
	free (str);
	return (rtn);
}
