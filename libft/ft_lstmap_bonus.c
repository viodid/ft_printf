/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 00:04:15 by dyunta            #+#    #+#             */
/*   Updated: 2023/02/08 00:04:15 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Iterates the list ’lst’ and applies the function
’f’ on the content of each node. Creates a new
list resulting of the successive applications of
the function ’f’. The ’del’ function is used to
delete the content of a node if needed. */

static void	*ft_clear(void *i, t_list *new_list, void del(void *))
{
	(del)(i);
	ft_lstclear(&new_list, del);
	return (0);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;
	void	*i;

	i = 0;
	if (!lst || !f)
		return (NULL);
	new = NULL;
	while (lst)
	{
		i = f(lst->content);
		if (!i)
			return (ft_clear(i, new, del));
		tmp = ft_lstnew(i);
		if (!tmp)
		{
			return (ft_clear(i, new, del));
		}
		ft_lstadd_back(&new, tmp);
		lst = lst->next;
	}
	return (new);
}
