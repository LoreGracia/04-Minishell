/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 18:55:57 by lgracia-          #+#    #+#             */
/*   Updated: 2024/07/06 17:03:45 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
/*
#include <stdio.h>

int	main(void)
{
	t_list	*nodo1;
	t_list	*nodo2;
	t_list	*nodo3;

	nodo1 = ft_lstnew("hello there");
	nodo2 = ft_lstnew("hello there");
	nodo3 = ft_lstnew("hello there");
	ft_lstadd_front(&nodo3, nodo2);
	ft_lstadd_front(&nodo2, nodo1);
	printf("%p\n",nodo1->next);
	printf("%p\n",nodo1);
	printf("%p\n",nodo2->next);
	printf("%p\n",nodo2);
	printf("%p\n",nodo3->next);
	printf("%p\n",nodo3);
	
	printf("%d\n", ft_lstsize(nodo1));
}*/
