/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:16:45 by lgracia-          #+#    #+#             */
/*   Updated: 2024/07/02 18:48:42 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*nodo;

	nodo = malloc(sizeof(t_list));
	if (nodo == 0)
		return (NULL);
	nodo->content = content;
	nodo->next = NULL;
	return (nodo);
}
/*
#include <stdio.h>

int	main(void)
{
	t_list	*nodo;
	char *str;

	nodo = ft_lstnew("hello there");
	str = nodo->content;
	printf("%s\n", str);
}*/
