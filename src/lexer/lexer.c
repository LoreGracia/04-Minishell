/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 18:48:42 by lgracia-          #+#    #+#             */
/*   Updated: 2025/06/11 11:52:21 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	print_token(t_mini mini)
{
	int	i;
	int	j;

	i = -1;
	if (!mini.pipe->token_array[0])
		printf("\n");
	else
	{
		while (mini.num_pipes >= ++i && mini.pipe[i].token_array)
		{
			j = -1;
			while (mini.pipe[i].token_array[++j])
				printf(PRINT_ARRAY, i, j, mini.pipe[i].token_array[j]);
		}
	}
	print_lst_token(mini);
}

void	print_lst_token(t_mini mini)
{
	t_token	*token;
	t_pipe	*pipe;

	pipe = mini.pipe;
	if (!pipe->token_array[0])
		printf("\n");
	else
	{
		while (pipe)
		{
			token = pipe->token;
			while (token)
			{
				printf("\e[35mType [%d] lst_token \"\e[93m%s\e[35m\"\n\e[0m", \
						token->type, token->token);
				if (pipe->fd_here_doc > 0)
					print_here_doc(pipe->fd_here_doc);
				token = token->next;
			}
			pipe = (t_pipe *)pipe->next;
		}
	}
}

t_pipe	*lexer_init(char **read_line, t_mini mini)
{
	char	**line;
	t_pipe	*pipe;
	int		i;

	pipe = is_malloc_error(ft_calloc(sizeof(t_pipe), mini.num_pipes + 1));
	line = split_token(read_line, '|', mini);
	if (!line)
		return (free(pipe), NULL);
	else
	{
		i = -1;
		while (++i <= mini.num_pipes)
		{
			pipe[i].token_array = split_token(&line[i], ' ', mini);
			if (!pipe[i].token_array)
			{
				while (i >= 0)
					clear_array(pipe[i--].token_array);
				return (clear_array(line), free(pipe), NULL);
			}
		}
	}
	clear_array(line);
	return (pipe);
}
