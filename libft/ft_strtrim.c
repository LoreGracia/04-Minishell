/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:37:24 by lgracia-          #+#    #+#             */
/*   Updated: 2024/07/16 18:23:41 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = ft_strlen(s1);
	while (i < j && ft_strchr(set, s1[i]) != 0)
		i++;
	while (j >= 0 && ft_strchr(set, s1[j]) != 0 && j > i)
		j--;
	s = ft_substr(s1, i, (j + 1 - i));
	if (s == 0)
		return (0);
	return (s);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%s\n", ft_strtrim("abcdbaaa Hello there abbaadbccdb","bdca"));
	printf("%s\n", ft_strtrim("  \t \t \n   \n\n\n\t","\n\t "));
	return(0);
}*/
