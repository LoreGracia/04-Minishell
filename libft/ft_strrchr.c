/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 18:38:25 by lgracia-          #+#    #+#             */
/*   Updated: 2024/07/14 16:09:54 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	*str;
	size_t			j;

	i = 0;
	str = (unsigned char *)s;
	j = ft_strlen(s);
	while (str[j - i] != (char)c && j - i != 0)
		i++;
	if (str[j - i] == (char)c)
	{
		return ((char *)&str[j - i]);
	}
	return (0);
}
/*
#include <stdio.h>

int	main()
{
	const char d[] = "60000";
	printf("%s\n", ft_strrchr((const char *)d, '6'));
}*/
