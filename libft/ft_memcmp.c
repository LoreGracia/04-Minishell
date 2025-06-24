/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 15:45:31 by lgracia-          #+#    #+#             */
/*   Updated: 2024/07/10 11:05:12 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned const char	*ss1;
	unsigned const char	*ss2;

	i = 0;
	ss1 = (unsigned const char *)s1;
	ss2 = (unsigned const char *)s2;
	if (n == 0)
		return (0);
	while (i + 1 < n && ss1[i] == ss2[i])
	{
		i++;
	}
	return (ss1[i] - ss2[i]);
}
/*
#include <stdio.h>

int 	main()
{
	printf("%d\n", ft_memcmp("hello faq", "hello peq", 9));
}*/
