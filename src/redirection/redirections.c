/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 17:06:03 by lgracia-          #+#    #+#             */
/*   Updated: 2025/06/12 09:05:46 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

short	redirection_in(t_mini *mini, t_token *curr, char *name_file)
{
	int	fd;

	if (curr->type == in)
	{
		mini->status = parsing_open(curr->type, name_file);
		if (mini->status)
			return (EXIT_FAILURE);
		fd = open(name_file, O_RDONLY);
		if (fd == -1)
			return (perror(""), EXIT_FAILURE);
		if (dup2(fd, STDIN_FILENO) == -1)
			return (perror(""), EXIT_FAILURE);
		close(fd);
	}
	return (EXIT_SUCCESS);
}

short	redirection_out(t_mini *mini, t_token *curr, char *name_file)
{
	int	flag;
	int	fd;

	flag = O_WRONLY | O_CREAT | O_TRUNC;
	if (curr->type == out)
	{
		mini->status = parsing_open(curr->type, name_file);
		if (mini->status)
			return (EXIT_FAILURE);
		fd = open(name_file, flag, 0666);
		if (fd == -1)
			return (perror(""), EXIT_FAILURE);
		if (dup2(fd, STDOUT_FILENO) == -1)
			return (perror(""), EXIT_FAILURE);
		close(fd);
	}
	return (EXIT_SUCCESS);
}

short	redirection_append(t_mini *mini, t_token *curr, char *name_file)
{
	int	flag;
	int	fd;

	flag = O_WRONLY | O_CREAT | O_APPEND;
	if (curr->type == append)
	{
		mini->status = parsing_open(curr->type, name_file);
		if (mini->status)
			return (EXIT_FAILURE);
		fd = open(name_file, flag, 0666);
		if (dup2(fd, STDOUT_FILENO) == -1)
			return (perror(""), EXIT_FAILURE);
		close(fd);
	}
	return (EXIT_SUCCESS);
}

int	ex_redirections_exec(t_mini *mini, t_token *token)
{
	char	*name_file;

	name_file = ((t_token *)token->next)->token;
	return (redirection_in(mini, token, name_file) \
		+ redirection_out(mini, token, name_file) \
		+ redirection_append(mini, token, name_file));
}

short	ex_redirections(t_mini *mini, t_pipe *curr)
{
	t_token	*token;
	int		status;

	status = 0;
	token = curr->token;
	while (token)
	{
		if (token->type == heredoc)
		{
			if (dup2(curr->fd_here_doc, STDIN_FILENO) == -1)
				return (perror(""), EXIT_FAILURE);
			close(curr->fd_here_doc);
		}
		else if (token->next && token->type != heredoc && token->type & redir)
		{
			status = ex_redirections_exec(mini, token);
			token = token->next;
			if (status)
				return (get_status(true, true));
		}
		if (token)
			token = token->next;
	}
	return (false);
}
