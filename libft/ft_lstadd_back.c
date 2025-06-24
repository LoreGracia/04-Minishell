/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:07:47 by lgracia-          #+#    #+#             */
/*   Updated: 2024/07/13 16:44:51 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!*lst)
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
}
/*
#include <stdio.h>

int	main(void)
{
	t_list	*nodo1;
	t_list	*nodo2;
	t_list	*nodo3;
	t_list	*nodo4;
	char *str;

	nodo1 = ft_lstnew("hello there");
	nodo2 = ft_lstnew("hello");
	nodo3 = ft_lstnew("I'm last");
	nodo4 = ft_lstnew("I'm new");
	ft_lstadd_front(&nodo2, nodo1);
	ft_lstadd_front(&nodo3, nodo2);
	str = ft_lstlast(nodo1)->content;
	printf("%s\n", str);
	ft_lstadd_back(&nodo1, nodo4);
	str = ft_lstlast(nodo1)->content;
	printf("%s\n", str);
}*/
