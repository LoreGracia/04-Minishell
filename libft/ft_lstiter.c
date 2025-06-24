/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:10:27 by lgracia-          #+#    #+#             */
/*   Updated: 2024/07/05 12:07:37 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
#include <stdio.h>

void	print(void *c)
{
	printf("%s\n", (char *)c);
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
	ft_lstiter(nodo1, print);
}*/
