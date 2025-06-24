/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:58:24 by lgracia-          #+#    #+#             */
/*   Updated: 2025/04/26 12:27:25 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (0);
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}
/*void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned const char	*s2;
	unsigned char		*s;

	i = 0;
	s = (unsigned char *)dest;
	s2 = (unsigned char *)src;
	while (dest == src || !n)
		return (dest);
	while (i < n)
	{
		s[i] = s2[i];
		i++;
	}
	return (dest);
}*/
/*
#include <stdio.h>
#include <string.h>

int	main()
{
	char s[9];
	strcpy(s,"hello");
	puts(s);
	char s2[] = "aeiou turutu";
	int n = 4;

	ft_memcpy(s, s2 , n);
	puts(s);
}*/
