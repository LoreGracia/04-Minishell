/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:39:40 by lgracia-          #+#    #+#             */
/*   Updated: 2024/07/17 10:30:06 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static void	concatenate(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	count;
	size_t	len;

	len = ft_strlen(src);
	count = ft_strlen(dst);
	i = 0;
	if (size != 0 && len != 0 && sizeof(dst) != 0)
	{
		while (i + count < size -1 && src[i] != '\0')
		{
			dst[i + count] = src[i];
			i++;
		}
	}
	dst[i + count] = '\0';
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t				count;
	size_t				len;

	len = ft_strlen(src);
	count = ft_strlen(dst);
	if (count >= size)
		return (len + size);
	concatenate(dst, src, size);
	return (count + len);
}
/*
#include <stdio.h>

int	main()
{
	char *s = "abcd\0";
	char d[15] = "pqrstuvwxyz\0";
	printf("%zu\n", ft_strlcat(d, s, 20));
	printf("%s | %s\n", s, d);
	//printf("%zu\n", ft_strlcat(d, "", sizeof(d)));
	//printf("%zu\n", ft_strlcat(d, s, 0));
}*/
