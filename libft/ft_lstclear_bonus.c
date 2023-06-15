/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkurcbar <dkurcbar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:31:54 by dkurcbar          #+#    #+#             */
/*   Updated: 2023/06/02 12:22:50 by dkurcbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*nxt;
	t_list	*tmp;

	if (*lst == NULL)
		return ;
	tmp = *lst;
	nxt = (*lst)->next;
	while (nxt != NULL)
	{
		del(tmp->content);
		free(tmp);
		tmp = nxt;
		nxt = tmp->next;
	}
	del(tmp->content);
	free(tmp);
	*lst = NULL;
}
