/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:19:42 by lgracia-          #+#    #+#             */
/*   Updated: 2025/04/05 12:35:58 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	size_t		len1;
	size_t		len2;
	char		*s;

	if (!s1 || !s2)
		return (0);
	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	s = ft_calloc((len1 + len2 + 1), sizeof(char));
	if (s == NULL)
		return (0);
	while (i < len1)
	{
		s[i] = s1[i];
		i++;
	}
	while (i - len1 < (len2))
	{
		s[i] = s2[i - len1];
		i++;
	}
	s[i] = '\0';
	return (s);
}
/*
#include <stdio.h>

int	main(void)
{
	char *s = ft_strjoin("hello ", "there");
	char *d = ft_strjoin("abc", NULL);
	printf("%s\n%s\n", s, d);
	free(s);
	free(d);
}*/
