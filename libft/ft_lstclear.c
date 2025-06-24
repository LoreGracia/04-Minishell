/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 19:52:58 by lgracia-          #+#    #+#             */
/*   Updated: 2024/07/13 20:02:33 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next;
	t_list	*aux;

	aux = *lst;
	while (aux)
	{
		next = aux->next;
		del(aux->content);
		free(aux);
		aux = next;
	}
	*lst = NULL;
}
/*
#include <stdio.h>
#include <stdlib.h>

void	del(void *content)
{
	if (content != NULL)
	{
		printf("\nDeleted %s\n", (char *)content);
		free(content); //no funciona | Misterios de la vitta
		printf("\nDeleted Complete\n");
	}
}

void	printlist(t_list *lst)
{
	int	size;
	void *str;

	size = ft_lstsize(lst);
	while (size !=0)
	{
		str = lst->content;
		printf("%s\n", (char *)str);
		lst = lst->next;
		size--;
	}
}

int	main(void)
{
	t_list	*nodo1;
	t_list	*nodo2;
	t_list	*nodo3;
	t_list	*nodo4;
	char	*str1;
	char	*str2;
	char	*str3;
	char	*str4;

	str1 = malloc(sizeof(char) * 12);
	str2 = malloc(sizeof(char) * 6);
	str3 = malloc(sizeof(char) * 9);
	str4 = malloc(sizeof(char) * 8);
	str1 = "hello there\0";
	str2 = "hello\0";
	str3 = "I'm last\0";
	str4 = "I'm new\0";
	nodo1 = ft_lstnew(str1);
	nodo2 = ft_lstnew(str2);
	nodo3 = ft_lstnew(str3);
	nodo4 = ft_lstnew(str4);
	ft_lstadd_front(&nodo2, nodo1);
	ft_lstadd_front(&nodo3, nodo2);
	ft_lstadd_front(&nodo4, nodo3);
	printlist(nodo1);
	ft_lstclear(&nodo1, del);
	printlist(nodo1);
}*/
