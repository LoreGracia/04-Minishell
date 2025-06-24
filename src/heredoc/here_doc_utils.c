/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:32:44 by lgracia-          #+#    #+#             */
/*   Updated: 2025/06/14 13:20:11 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	heredoc_count_redir(char **s, int *i, t_mini mini)
{
	if ((*s)[*i] && (*s)[*i] == '\"')
		return (split_double_quotes(s, i, mini, '|'));
	else if ((*s)[*i] && (*s)[*i] == '\'')
		return (split_single_quote(s, i, mini, '|'));
	return (0);
}

int	heredoc_count_blanknquotes(char *s, int *i, t_mini mini, int *count)
{
	int	error;

	*i += 2;
	if (!parse_redirection(s, i))
		return (-2);
	(*count)++;
	if (*i && (s[*i - 1] == '\"' || s[*i - 1] == '\''))
		(*i)--;
	error = is_heredoc_blanksnquotes(s, *i, mini);
	if (error == -2)
		(*i)++;
	else
		*i = error;
	return (*i);
}

int	heredoc_count(char *s, t_mini mini)
{
	int		i;
	int		count;

	count = 1;
	i = 0;
	while (s[i])
	{
		i = is_heredoc_blanksnquotes(s, i, mini);
		if (i < 0)
			return (-2);
		if (heredoc_count_redir(&s, &i, mini))
			return (-2);
		if (s[i] && s[i] == '<' && s[i + 1] && s[i + 1] == '<')
		{
			i = heredoc_count_blanknquotes(s, &i, mini, &count);
			if (i < 0)
				return (-2);
		}
		else if (s[i])
			i++;
	}
	if (i == -1)
		return (-1);
	return (count);
}

int	is_heredoc_blanksnquotes(char *s, int i, t_mini mini)
{
	while (s[i] && !blanks(s[i]))
		i++;
	if (s[i] && s[i] == '"')
	{
		if (split_double_quotes(&s, &i, mini, '|'))
			return (-2);
	}
	else if (s[i] && s[i] == '\'')
	{
		if (split_single_quote(&s, &i, mini, '|'))
			return (-2);
	}
	return (i);
}

void	is_heredoc_ocurrence_delete(char **read_line, int *i, int *j)
{
	char	*s;
	char	*tmp;

	s = *read_line;
	*j = *i;
	while (s[*j] && !blanks(s[*j]))
		(*j)++;
	if (*j == *i)
		(*j)++;
	(*i)--;
	while (*i && s[*i] == '<')
		(*i)--;
	if (s[*i] == '\'' || s[*i] == '"')
		(*i)++;
	tmp = ft_strdup("");
	s = replacesubstr(s, i, tmp, *j - *i);
	*read_line = s;
}
