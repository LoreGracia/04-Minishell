/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 20:40:10 by lgracia-          #+#    #+#             */
/*   Updated: 2024/07/08 12:06:47 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t				i;
	size_t				len;

	i = 0;
	len = ft_strlen(src);
	if (size != 0 && len != 0 && sizeof(dst) != 0)
	{
		while (i < size - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
	}
	if (size > 0)
		dst[i] = '\0';
	return (ft_strlen(src));
}
/*
#include <stdio.h>

int	main()
{
	char s[11] = "HELLO THERE";
	char d[15] = "hello there";
	char z[0];
	puts(d);
	printf("%lu\n", sizeof(d));
	printf("%zu\n", ft_strlcpy(d, s, sizeof(d)));
	printf("%zu\n", ft_strlcpy(d, "", sizeof(d)));
	printf("%zu\n", ft_strlcpy(d, s, 2));
	printf("%zu\n", ft_strlcpy(d, s, 0));
	printf("%zu\n", ft_strlcpy(z, s, sizeof(d)));
	puts(d);
}*/
