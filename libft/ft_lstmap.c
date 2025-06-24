/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 12:09:32 by lgracia-          #+#    #+#             */
/*   Updated: 2024/07/14 19:52:13 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	void	*c;
	t_list	*newnode;
	t_list	*newlist;

	newlist = NULL;
	while (lst)
	{
		c = f(lst->content);
		newnode = ft_lstnew(c);
		if (newnode == NULL)
		{
			ft_lstclear(&newlist, del);
			del(c);
			return (0);
		}
		ft_lstadd_back(&newlist, newnode);
		lst = lst->next;
	}
	return (newlist);
}
/*
#include <stdio.h>

void	del(void *content)
{
	if (content != NULL)
	{
		free(content); 
	}
}

void	*print(void *c)
{
	char *cc;
	
	cc = c;
	cc = ft_strchr(cc, ' ');
	return (cc);
}

void	printlist(t_list *lst)
{
	int	size;
	void *str;

	size = ft_lstsize(lst);
	printf("printing list\n%d\n", size);
	while (lst)
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
	t_list	*newlist;
	char	*str1;
	char	*str2;
	char	*str3;
	char	*str4;

	str1 = malloc(sizeof(char) * 12);
	str2 = malloc(sizeof(char) * 6);
	str3 = malloc(sizeof(char) * 9);
	str4 = malloc(sizeof(char) * 8);
	str1 = "hello there\0";
	str2 = "hello world\0";
	str3 = "I'm last\0";
	str4 = "I'm new\0";
	nodo1 = ft_lstnew(str1);
	nodo2 = ft_lstnew(str2);
	nodo3 = ft_lstnew(str3);
	nodo4 = ft_lstnew(str4);
	ft_lstadd_back(&nodo1, nodo2);
	ft_lstadd_back(&nodo1, nodo3);
	ft_lstadd_back(&nodo1, nodo4);
	printlist(nodo1);
	newlist = ft_lstmap(nodo1, print, del);
	printlist(newlist);
}*/
