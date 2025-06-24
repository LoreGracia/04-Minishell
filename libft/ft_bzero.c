/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:02:27 by lgracia-          #+#    #+#             */
/*   Updated: 2024/06/26 14:54:00 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	s[4];

	strcpy(s,"hola");
	puts(s);
	int n = 3;

	for(int i = 0; i < 11; i++)
		printf("str[%d]: '%c' | %d\n", i, s[i], s[i]);
	ft_bzero(s, n);
	//puts(s);
	for(int i = 0; i < 11; i++)
		printf("str[%d]: '%c' | %d\n", i, s[i], s[i]);
}*/
