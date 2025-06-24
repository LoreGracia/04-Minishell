/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 11:09:57 by lgracia-          #+#    #+#             */
/*   Updated: 2024/07/13 15:18:20 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s);
	str = malloc(sizeof(char) * len + 1);
	if (str == 0)
		return (NULL);
	while (i < len)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
char	function(unsigned int i, char c)
{
	char a;

	i *= 1;
	a = ft_tolower(c);
	return (a);
}

#include <stdio.h>

int	main(void)
{
	char 	*str = "HELLO THERE";
	int		i = 0;
	char	*a;

	a = ft_strmapi(str, function);
	printf("%s\n", a);
	while (a[i] != 0)
	{
		printf("array[%c]\n", a[i]);
		i++;
	}
}*/
