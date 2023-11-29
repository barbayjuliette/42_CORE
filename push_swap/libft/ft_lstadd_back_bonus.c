/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay<marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 20:54:06 by jbarbay           #+#    #+#             */
/*   Updated: 2023/09/08 20:54:13 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_listadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*temp;

	temp = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		// (*lst)->previous = NULL;
	}
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new;
		// new->previous = temp;
		new->next = NULL;
	}
}

// int main(void)
// {
// 	t_list *list;
// 	t_list *new;

// 	list = ft_lstnew("hello");
// 	new = ft_lstnew("world");
// 	list->next = new;

// 	ft_lstadd_back(&list, new);
// 	list = list->next;
// 	printf("%s", (char *)list->content);
// 	return 0;
// }
