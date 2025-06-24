/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:26:44 by lgracia-          #+#    #+#             */
/*   Updated: 2025/06/14 13:19:32 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	is_heredoc_iter(char *s, int *i, int **fd, int *n)
{
	if (s[*i] && s[*i] == '|')
		(*n)++;
	else if (!s[*i])
	{
		(*n)++;
		(*fd)[*n] = -2;
		return (1);
	}
	if (s[*i] && (s[*i] != '"' && s[*i] != '\'') && \
	((s[*i] == '<' && ((s[*i + 1] && s[*i + 1] != '<') || \
	!s[*i + 1])) || s[*i] != '<'))
		(*i)++;
	return (0);
}

void	is_heredoc_ocurrence(char **read_line, int *iter, int *fd)
{
	char	*s;
	int		j;
	int		i;

	i = *iter;
	s = *read_line;
	j = i;
	while (s[j] && s[j] != '|' && !(s[j] == '\'' || s[j] == '"'))
	{
		if (s[j] && s[j] == '<' && s[j + 1] && s[j + 1] && \
			s[j + 1] == '<')
		{
			if (*fd != -1 && close(*fd))
				print_error(1, "Close error\n");
			is_heredoc_ocurrence_delete(&s, &i, &j);
			break ;
		}
		else if (j && s[j] == '<' && s[j - 1] == '<')
			i++;
		j++;
	}
	*iter = i;
	*read_line = s;
}

int	is_heredoc_exec(char **s, int *i, t_mini *mini, int *fd)
{
	int		err;
	char	*closestr;

	err = 0;
	closestr = is_closestr(s, i, &err, *mini);
	if (!closestr)
		return (1);
	*fd = here_doc_exec(&closestr, &err, mini);
	is_heredoc_ocurrence(s, i, fd);
	return (0);
}

int	is_heredoc(char **s, int **fd, int count, t_mini *mini)
{
	int		i;
	int		n;
	int		c;

	c = 0;
	i = 0;
	n = 0;
	*fd = is_malloc_error(ft_calloc(sizeof(int), count + 2));
	*fd = ft_memsetint(*fd, -1, count + 2);
	while (c != count)
	{
		i = is_heredoc_blanksnquotes((*s), i, *mini);
		if (i == -2 || parse_pipe(*s, &i))
			return (-2);
		if ((*s)[i] && (*s)[i] == '<' && (*s)[i + 1] && (*s)[i + 1] == '<')
		{
			if (is_heredoc_exec(s, &i, mini, &((*fd)[n])))
				return (-2);
			c++;
		}
		if (is_heredoc_iter((*s), &i, fd, &n))
			break ;
	}
	return (1);
}

int	init_here_doc(char **read_line, int **fd, t_mini *mini)
{
	int		count;
	int		error;

	error = 0;
	count = heredoc_count(*read_line, *mini);
	if (count == -2)
		return (-2);
	else if (count != 1)
	{
		error = is_heredoc(read_line, fd, count, mini);
		if (error == -2)
			return (-1);
	}
	else
	{
		*fd = is_malloc_error(ft_calloc(sizeof(int), 1));
		(*fd)[0] = -2;
	}
	return (0);
}
