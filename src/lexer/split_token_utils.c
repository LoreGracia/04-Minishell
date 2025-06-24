/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_token_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:50:24 by lgracia-          #+#    #+#             */
/*   Updated: 2025/06/12 10:58:06 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

char	*delete_strchar(char *s, int *start, char c, char to_replace)
{
	char	*new;
	char	*tmp;

	if (c != '|' && s[*start] == to_replace)
	{
		if (*start)
		{
			tmp = is_malloc_error(ft_calloc(1, *start + 2));
			ft_strlcpy(tmp, s, *start + 1);
		}
		else
			tmp = is_malloc_error(ft_strdup(""));
		if (!s[*start + 1])
			return (free(s), tmp);
		new = is_malloc_error(ft_strjoin(tmp, &s[*start + 1]));
		free(tmp);
		free(s);
		s = NULL;
		return (new);
	}
	return (s);
}

int	split_double_quotes(char **string, int *start, t_mini mini, char c)
{
	if ((*string)[*start] == '\"')
	{
		(*string) = delete_strchar((*string), start, c, '\"');
		(*start) += (c != ' ');
		while ((*string)[(*start)] != '\"')
		{
			if (!(*string)[*start])
				return (1);
			if (c == ' ')
				expand(string, start, mini, 0);
			if (!(*string))
				return (1);
			*start += ((*string)[*start] && (*string)[*start] != '\"');
		}
		(*string) = delete_strchar((*string), start, c, '\"');
		(*start) += (c != ' ');
		if ((*string)[*start] && (*string)[*start] == '\"')
			split_double_quotes(string, start, mini, c);
		else if ((*string)[*start] && (*string)[*start] == '\'')
			split_single_quote(string, start, mini, c);
	}
	return (0);
}

int	split_single_quote(char **string, int *start, t_mini mini, char c)
{
	char	*s;

	s = *string;
	if (s[*start] == '\'')
	{
		s = delete_strchar(s, start, c, '\'');
		(*start) += (c != ' ');
		while (s[(*start)] != '\'')
		{
			if (!s[*start])
				return (*string = s, 1);
			if (s[*start] && s[*start] != '\'')
				++(*start);
		}
		s = delete_strchar(s, start, c, '\'');
		(*start) += (c != ' ');
		if (s[*start] && s[*start] == '\"')
			split_double_quotes(&s, start, mini, c);
		else if (s[*start] && s[*start] == '\'')
			split_single_quote(&s, start, mini, c);
	}
	*string = s;
	return (0);
}

short	is_redirection(char *read_line, int i, char c)
{
	if (c != ' ')
		return (false);
	if (read_line[i] && (read_line[i] == '<'))
	{
		if (read_line[i + 1] && read_line[i + 1] == '<')
			return (true);
		return (true);
	}
	if (read_line[i] && (read_line[i] == '>'))
	{
		if (read_line[i + 1] && read_line[i + 1] == '>')
			return (true);
		return (true);
	}
	return (false);
}
