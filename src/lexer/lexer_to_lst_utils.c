/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_to_lst_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 15:58:00 by lgracia-          #+#    #+#             */
/*   Updated: 2025/06/12 17:01:59 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	is_q_redir_nextbytype(char c, int type, char *read_line, int *j)
{
	if (read_line[*j] == c && read_line[*j + 1] && read_line[*j + 1] == c \
		&& type != in && type != out)
	{
		(*j) += 2;
		return (1);
	}
	else if ((type == in || type == out) && read_line[*j] == c)
	{
		(*j) += 1;
		return (1);
	}
	return (0);
}

int	is_quoted_redir_ocurrence(char c, int type, char *read_line, int *j)
{
	if ((read_line[*j] == '\'' || read_line[*j] == '\"') && \
	type == heredoc && read_line[*j + 1] == c)
	{
		if ((read_line[*j + 2] == '\'' || read_line[*j + 2] == '\"') && \
		(read_line[*j + 3] == '\'' || read_line[*j + 3] == '\"'))
		{
			if (read_line[*j + 4] && read_line[*j + 4] == c && \
				(read_line[*j + 5] == '\'' || read_line[*j + 5] == '\"'))
			{
				*j += 6;
				return (3);
			}
		}
	}
	return (0);
}

int	is_quoted_redirection(char c, int type, char *read_line, int *j)
{
	static short	single_quote;
	static short	double_quote;

	if (!read_line)
	{
		single_quote = 1;
		double_quote = 2;
		return (0);
	}
	while (read_line && read_line[*j])
	{
		if (is_quoted_redir_ocurrence(c, type, read_line, j))
			return (3);
		if (read_line[*j] == '\'' && double_quote > 0)
			single_quote *= -1;
		else if (read_line[*j] == '\"' && single_quote > 0)
			double_quote *= -1;
		if (is_q_redir_nextbytype(c, type, read_line, j))
			break ;
		(*j)++;
	}
	if (double_quote < 0 || single_quote < 0)
		return (3);
	return (type);
}
