/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:50:24 by lgracia-          #+#    #+#             */
/*   Updated: 2025/06/12 12:36:54 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	starts(char **string, char c, int next)
{
	int		start;
	char	*s;

	s = *string;
	start = next;
	while (s[start] && ((c == '|' && s[start] == c) || \
	(c == ' ' && !blanks(s[start]))))
		start++;
	return (start);
}

int	ends_redir(char *s, int *start, int next, char c)
{
	if (!s || !s[*start] || ((c == '|' && s[*start] == c) || \
	(c == ' ' && !blanks(s[*start]))))
		return (1);
	if (c == ' ' && (s[*start] == '>' || s[*start] == '<'))
	{
		if (*start != next)
			return (1);
		while (s[*start] == '>' || s[*start] == '<')
			(*start)++;
		if ((s[next] == '>' || s[next] == '<') && *start == next + 1)
			return (1);
		else if (s[next] == '>' || s[next] == '<')
			return (1);
	}
	else if (s[*start] != '\'' && s[*start] != '"')
		(*start)++;
	return (0);
}

int	ends(char **string, char c, int next, t_mini mini)
{
	int		start;
	char	*s;

	s = *string;
	start = next;
	while (s && s[start] && ((c == '|' && s[start] != c) || \
	(c == ' ' && blanks(s[start]))))
	{
		split_double_quotes(&s, &start, mini, c);
		split_single_quote(&s, &start, mini, c);
		if (s && s[start] && c == '|')
		{
			if (!expand(&s, &start, mini, AMBIGUOS_REDIR))
				return (-1);
		}
		if (ends_redir(s, &start, next, c))
			break ;
	}
	*string = s;
	return (start);
}

char	*split_token_loop(char **s, char c, t_mini mini, int *end)
{
	int		start;

	start = starts(s, c, *end);
	*end = ends(s, c, start, mini);
	if (*end < 0)
		return (NULL);
	return (is_malloc_error(ft_substr(*s, start, *end - start)));
}

char	**split_token(char **s, char c, t_mini mini)
{
	int		i;
	int		count;
	int		end;
	char	**str;

	end = 0;
	i = words(*s, c, &count);
	str = is_malloc_error(ft_calloc((count + 2), sizeof(char *)));
	count = ccount(*s, c);
	if (count < 0)
		return (free(str), NULL);
	while (i < count + 1)
	{
		str[i] = split_token_loop(s, c, mini, &end);
		if (!str[i])
			return (clear_array(str), NULL);
		if (str[i][0] || i == count)
			i++;
		else
		{
			free(str[i]);
			count--;
		}
	}
	return (str);
}
