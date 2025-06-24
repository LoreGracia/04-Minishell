/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_closestr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 12:15:28 by lgracia-          #+#    #+#             */
/*   Updated: 2025/06/12 13:01:25 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	is_closestr_quote_ocurrence(int *j, int result)
{
	if (result)
		return (1);
	(*j)--;
	return (0);
}

int	is_closestr_quotes(char **read_line, int *i, t_mini mini, int *err)
{
	int		j;
	char	*s;

	j = *i;
	s = *read_line;
	if (s[j] && s[j] == '\"')
	{
		*err = 1;
		if (is_closestr_quote_ocurrence(&j, \
			split_double_quotes(read_line, &j, mini, 'h')))
			return (1);
	}
	else if (s[j] && s[j] == '\'')
	{
		*err = 1;
		if (is_closestr_quote_ocurrence(&j, \
			split_single_quote(&s, &j, mini, 'h')))
		{
			*read_line = s;
			return (1);
		}
		*read_line = s;
	}
	*i = j;
	return (0);
}

int	is_closestr_end(char **read_line, int *j, int *err, t_mini mini)
{
	char	*s;

	s = *read_line;
	while (s[*j] && blanks(s[*j]))
	{
		if (!s[*j] || (s[*j] == '<' || s[*j] == '>') || s[*j] == '|')
			break ;
		if (is_closestr_quotes(read_line, j, mini, err))
			return (1);
		s = *read_line;
		if (s[*j] && (blanks(s[*j]) && s[*j] != '|' && \
			s[*j] != '<' && s[*j] != '>'))
			(*j)++;
	}
	*read_line = s;
	return (0);
}

int	is_closestr_start(char *s, int *i)
{
	if (!s[*i])
		return (1);
	while (s[*i] && !blanks(s[*i]))
		(*i)++;
	if (!s[*i] || (s[*i] == '<' && s[*i + 1] && s[*i + 1] == '<'))
		return (1);
	if ((s[*i] == '<' && !s[*i + 1]) || s[*i] == '|')
		return (1);
	return (0);
}

char	*is_closestr(char **read_line, int *iter, int *err, t_mini mini)
{
	char			*s;
	int				i;
	int				j;
	char			*close;

	s = *read_line;
	i = *iter + 2;
	if (is_closestr_start(s, &i))
		return (NULL);
	j = i;
	if (is_closestr_end(read_line, &j, err, mini))
		return (NULL);
	s = *read_line;
	close = ft_substr(s, i, j - i);
	*read_line = s;
	while (i && s[i] && !blanks(s[i]))
		i--;
	*read_line = replacesubstr(*read_line, &i, NULL, j - i);
	i--;
	*iter = i;
	printf("\e[30mClose heredoc token |\e[36m%s\e[30m|\e[0m\n", close);
	return (close);
}
