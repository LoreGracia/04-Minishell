/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:47:12 by lgracia-          #+#    #+#             */
/*   Updated: 2024/07/14 13:51:36 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (str[i] != (char)c && str[i])
		i++;
	if (str[i] == (char)c)
	{
		return ((char *)&str[i]);
	}
	return (0);
}
/*
#include <stdio.h>

int	main()
{
	const char d[] = "tripouille";
	printf("%s\n", ft_strchr(d, 't' + 256));
}*/
