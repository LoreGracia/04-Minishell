/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:01:29 by lgracia-          #+#    #+#             */
/*   Updated: 2024/07/13 20:00:53 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}
/*
#include <stdio.h>

int	main(void)
{
	t_list	*nodo1;
	t_list	*nodo2;
	t_list	*nodo3;
	t_list	*nod;
	char *str;

	nodo1 = ft_lstnew("hello there");
	nodo2 = ft_lstnew("hello");
	nodo3 = ft_lstnew("I'm last");
	ft_lstadd_front(&nodo2, nodo1);
	ft_lstadd_front(&nodo3, nodo2);
	nod = ft_lstlast(nodo1);
	str = nod->content;
	printf("%s\n", str);
}*/
