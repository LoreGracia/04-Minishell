/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 17:06:29 by lgracia-          #+#    #+#             */
/*   Updated: 2024/09/04 18:45:39 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!*lst)
		*lst = new;
	else
	{
		new->next = *lst;
		*lst = new;
	}
}
/*
#include <stdio.h>

int	main(void)
{
	t_list	*nodo;
	t_list	*new;
	char *str;

	nodo = ft_lstnew("hello there");
	new = ft_lstnew("adio aqui");
	ft_lstadd_front(&nodo, new);
	str = nodo->content;
	if (nodo == new)
		printf("pass\n");
	printf("%s\n%s\n", (char *)nodo->content,(char *)(nodo->next)->content);
}*/
