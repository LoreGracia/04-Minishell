/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 20:08:30 by lgracia-          #+#    #+#             */
/*   Updated: 2024/08/04 21:06:51 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	unsigned const char	*s;

	i = n;
	d = (unsigned char *)dest;
	s = (unsigned const char *)src;
	if (d == s || !n)
		return (dest);
	if (d > s)
		while (i-- != 0)
			d[i] = s[i];
	else
		ft_memcpy(d, s, n);
	return (dest);
}
/*
#include <stdio.h>

int	main()
{
	char s[] = "1234567890";
	//char d[] = "hola que tal";
	puts(s);
	ft_memmove(s+2, s, 6);
	puts(s);
}*/
