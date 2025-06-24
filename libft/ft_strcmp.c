/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 19:47:06 by lgracia-          #+#    #+#             */
/*   Updated: 2025/02/24 12:35:18 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*ss1;
	unsigned char	*ss2;

	i = 0;
	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	while (ss1[i] == ss2[i] && ss1[i] && ss2[i])
		i++;
	return (ss1[i] - ss2[i]);
}
/*
#include <stdio.h>

int 	main()
{
	printf("%d\n", ft_strncmp("abc", "abc\0hello there", 7));
	printf("%d\n", ft_strncmp("hello p", "", 0));
	printf("%d\n", ft_strncmp("", "hello f", 0));
	printf("%d\n", ft_strncmp("hello ", "hello f", 7));
	printf("%d\n", ft_strncmp("hello ", "hell", 10));
	printf("%d\n", ft_strncmp("hell", "hello", 10));
	printf("%d\n", ft_strncmp("hello there", "hel\375xx", 5));
}*/
