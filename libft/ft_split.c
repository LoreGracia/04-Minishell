/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:50:24 by lgracia-          #+#    #+#             */
/*   Updated: 2025/06/11 18:08:11 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static int	words(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	if (s[i] == c || s[i] == '\0')
		count = 0;
	else
		count = 1;
	while (s[i])
	{
		if (s[i] == c || s[i] == '\0')
		{
			while (s[i] == c)
				i++;
			if (s[i] != c && s[i] != 0)
				count++;
			if (!s[i])
				return (count);
		}
		i++;
	}
	return (count);
}

static int	starts(char const *s, char c, int next, int point)
{
	int	start;

	start = next;
	if (point == 0)
	{
		while (s[start] == c && s[start])
			start++;
	}
	else
	{
		while (s[start] != c && s[start])
			start++;
	}
	return (start);
}

static void	*full_free(char **str, int words)
{
	int	i;

	i = 0;
	while (i != words)
	{
		if (str[i])
		{
			free(str[i]);
			str[i] = NULL;
		}
		i++;
	}
	free(str);
	str = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		count;
	int		start;
	int		end;

	if (!s)
		return (NULL);
	i = 0;
	end = 0;
	count = words(s, c);
	str = malloc((count + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	while (i < count)
	{
		start = starts(s, c, end, 0);
		end = starts(s, c, start, 1);
		str[i] = ft_substr(s, start, end - start);
		if (!str[i])
			return (full_free(str, i));
		i++;
	}
	str[i] = NULL;
	return (str);
}
/*
#include <stdio.h>

int	main(void)
{
	char *s = "    hello   there   ";
	char **str = ft_split(s,' ');
	int	i = 0;

	if (!str)
		return (1);

	while (str[i])
	{
		printf("array[%d]: \"%s\"\n", i, str[i]);
		i++;
	}
	printf("pass");
}*/
