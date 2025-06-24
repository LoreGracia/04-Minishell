/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 15:46:12 by lgracia-          #+#    #+#             */
/*   Updated: 2025/06/12 12:47:52 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	ccount_redir_else(char *read_line, int *iter, int *count, int c)
{
	int	j;
	int	i;

	i = *iter;
	j = i + 1;
	j += (read_line[j - 1] == '>' && read_line[j] == '>');
	if (!parse_redirection(read_line, &j))
		return (-2);
	if (i && blanks(read_line[i - 1]))
		(*count)++;
	while (read_line[i] && (read_line[i] == '<' || \
		read_line[i] == '>'))
		i++;
	if (c == ' ' && read_line[i] && blanks(read_line[i]))
		(*count)++;
	else if (c == ' ' && (!read_line[i] || read_line[i] == '|' || \
		(read_line[i] == '<' || read_line[i] == '>')))
		return (-2);
	i--;
	*iter = i;
	return (0);
}

int	ccount_redir(char *read_line, int *iter, int *count, int c)
{
	int	i;

	i = *iter;
	if (c == ' ' && read_line[i] && (read_line[i] == '<' || \
	read_line[i] == '>'))
	{
		if (read_line[i] == '<' && read_line[i + 1] == '<')
		{
			i++;
			count++;
		}
		else
		{
			if (ccount_redir_else(read_line, &i, count, c))
				return (-2);
		}
		*iter = i;
	}
	return (0);
}

int	ccount_loop(char *read_line, char c, int *count)
{
	int	j;
	int	i;

	j = jump_blank(read_line);
	i = j - 1;
	while (read_line[++i])
	{
		if ((c == '|' && read_line[i] == c) || \
		(c == ' ' && !blanks(read_line[i])))
		{
			if (c == '|' && (i == j || next_is_pipe(&read_line[i])))
				return (-2);
			while (read_line[i] && c == ' ' && !blanks(read_line[i]))
				i++;
			(*count)++;
		}
		if (!read_line[i])
			break ;
		i = is_quote(read_line, i);
		if (i == -4)
			return (-1);
		if (ccount_redir(read_line, &i, count, c))
			return (-2);
	}
	return (i);
}

void	ccount_end_n_count(char *read_line, int *count, int *i, char c)
{
	if (c == ' ')
		(*count)--;
	(*i)--;
	while (read_line[*i] && !blanks(read_line[*i]))
		--(*i);
}

int	ccount(char *read_line, char c)
{
	int	i;
	int	count;

	count = 0;
	if (!read_line)
		return (-1);
	i = ccount_loop(read_line, c, &count);
	if (i < 0)
		return (i);
	if (i)
		--i;
	if (i && read_line[i] && !blanks(read_line[i]))
		ccount_end_n_count(read_line, &count, &i, c);
	if (i < 0 || count < 0)
		count = 0;
	if (read_line[i] == '|')
		return (-1);
	return (count);
}
