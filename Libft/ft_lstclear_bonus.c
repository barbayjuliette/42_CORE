/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay<marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 22:22:08 by jbarbay           #+#    #+#             */
/*   Updated: 2023/09/08 22:22:13 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Deletes and frees the given node and every
// successor of that node, using the function ’del’
// and free(3).
// Finally, the pointer to the list must be set to
// NULL

#include "libft.h"

// void	del(void *ptr)
// {
// 	free(ptr);
// }

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next;
	t_list	*current;

	current = *lst;
	while (current)
	{
		next = current->next;
		del(current->content);
		free(current);
		current = next;
	}
	*lst = NULL;
}

// int main(void)
// {
// 	char *content;
// 	char *cont;
// 	content = ft_strdup("hello");
// 	t_list *list = ft_lstnew(content);

// 	t_list *new;
// 	cont = ft_strdup("node content");
// 	new = ft_lstnew(cont);
// 	new->next = NULL;

// 	ft_lstadd_front(&list, new);
// 	ft_lstclear(&list, del);

// 	return 0;
// }
