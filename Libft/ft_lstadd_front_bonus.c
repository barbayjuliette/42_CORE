/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:14:08 by jbarbay           #+#    #+#             */
/*   Updated: 2024/02/04 18:35:09 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Adds the node ’new’ at the beginning of the list.

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

// int main(void)
// {
// 	char *content = "I am an old node";
// 	t_list *list = ft_lstnew(content);

// 	t_list new;
// 	new.content = "new first node";
// 	new.next = NULL;

// 	ft_lstadd_front(&list, &new);

// 	while (list)
// 	{
// 		printf("Content: %s\n", (char *)list->content);
// 		list = list->next;
// 	}

// 	return 0;
// }
