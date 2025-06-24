/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:01:06 by lgracia-          #+#    #+#             */
/*   Updated: 2025/06/12 12:29:59 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	is_quote(char *read_line, int i)
{
	if (read_line[i] && read_line[i] == 34)
	{
		i++;
		while (read_line[i] != 34)
		{
			if (!read_line[i])
				return (-4);
			i++;
		}
	}
	else if (read_line[i] && read_line[i] == 39)
	{
		i++;
		while (read_line[i] != 39)
		{
			if (!read_line[i])
				return (-4);
			i++;
		}
	}
	return (i);
}

int	next_is_pipe(char *read_line)
{
	int	i;

	i = 1;
	while (read_line[i] && !blanks(read_line[i]))
		i++;
	if (read_line[i] && read_line[i] == '|')
		return (1);
	return (0);
}

int	jump_blank(char *read_line)
{
	int	j;

	j = 0;
	while (!blanks(read_line[j]))
		j++;
	return (j);
}

int	parse_redirection(char *s, int *i)
{
	while (s[*i] && !blanks(s[*i]))
		(*i)++;
	if (!s[*i] || s[*i] == '|' || s[*i] == '<' || s[*i] == '>')
		return (0);
	return (1);
}

void	*ft_memsetint(void *s, int c, size_t n)
{
	size_t			i;
	unsigned int	*str;

	i = 0;
	str = (unsigned int *)s;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (str);
}
