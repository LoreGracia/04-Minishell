/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 20:12:57 by lgracia-          #+#    #+#             */
/*   Updated: 2025/05/11 17:35:14 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (str);
}
/*
#include <stdio.h>
#include <string.h>

int	main()
{
	char s[9];
	strcpy(s,"hello");
	puts(s);
	int c = 'a';
	int n = 4;

	ft_memset(s, c , n);
	puts(s);
}*/
