/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_to_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 15:48:41 by lgracia-          #+#    #+#             */
/*   Updated: 2025/06/08 15:58:55 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	type_parse(char **array, int i, char *read_line, int *j)
{
	if (array[i] && array[i][0] == '-')
		return (flag);
	else if (!array[i])
		return (-1);
	else if (!ft_strncmp(array[i], "<", -1))
		return (is_quoted_redirection('<', in, read_line, j));
	else if (!ft_strncmp(array[i], ">", -1))
		return (is_quoted_redirection('>', out, read_line, j));
	else if (!ft_strncmp(array[i], ">>", -1))
		return (is_quoted_redirection('>', append, read_line, j));
	else if (!ft_strncmp(array[i], "<<", -1))
		return (is_quoted_redirection('<', heredoc, read_line, j));
	else
		return (3);
}

t_token	*array_token_to_lst(char **array, int i, char *read_line, int *j)
{
	t_token	*token;

	token = ft_calloc(sizeof(t_token), 1);
	if (!token)
		print_error(1, NULL);
	if (!array)
		return (NULL);
	(*token).token = array[i];
	(*token).type = type_parse(array, i, read_line, j);
	if (array[i + 1])
	{
		(*token).next = array_token_to_lst(array, i + 1, read_line, j);
		if (!(*token).next)
			return (clear_lst(token), NULL);
	}
	else
	{
		(*token).next = NULL;
		i = -1;
	}
	return (token);
}

int	array_to_lst(t_mini *mini, char *read_line)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	is_quoted_redirection(0, 0, NULL, 0);
	while (++i != mini->num_pipes + 1)
	{
		mini->pipe[i].token = array_token_to_lst(mini->pipe[i].token_array, \
			0, read_line, &j);
		if (!mini->pipe[i].token)
			return (clear_pipe(mini));
		if (i != mini->num_pipes)
			mini->pipe[i].next = &mini->pipe[i + 1];
	}
	return (0);
}
