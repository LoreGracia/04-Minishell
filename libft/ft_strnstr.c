/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 17:14:22 by lgracia-          #+#    #+#             */
/*   Updated: 2024/07/15 17:06:10 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*b;
	char	*l;

	b = (char *)big;
	l = (char *)little;
	i = 0;
	j = 0;
	if (l[j] == '\0')
		return (b);
	while (i + 1 <= len && b[i] != '\0')
	{
		j = 0;
		while (b[i + j] != '\0' && l[j] == b[i + j] && i + j <= len)
		{
			j++;
		}
		if (l[j] == '\0' && i + j <= len)
			return (&b[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>

int 	main()
{
	printf("%s\n", ft_strnstr("aaabcabcd", "a", 1));
	printf("%s\n", ft_strnstr("hello faq", "lo", 7));
	printf("%s\n", ft_strnstr("MZIRIBMZIRIBMZE123", "MZIRIBMZE", 7));
	printf("%s\n", ft_strnstr("hello", "hello", 5));
	printf("%s\n", ft_strnstr("hello faq", "lo", 20));
}*/
