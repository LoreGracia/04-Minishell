/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 17:01:23 by lgracia-          #+#    #+#             */
/*   Updated: 2025/06/11 12:57:00 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	update_status(t_mini *mini)
{
	if (mini->status == 131)
	{
		ft_putstr_fd("i'm core dump :c\n", 2);
		get_status(true, mini->status);
	}
	else if (WIFEXITED(mini->status))
		get_status(true, WEXITSTATUS(mini->status));
}

short	command(t_mini *mini)
{
	char	**args;
	pid_t	bb;

	if (mini->num_pipes != 0)
		return (false);
	args = list_to_args(mini->pipe->token);
	if (ex_redirections(mini, mini->pipe))
		return (clear_array(args), true);
	if (is_built_in(mini, args))
		return (reset_fds(mini), clear_array(args), true);
	bb = child_pid(mini, args);
	if (bb == -1)
		print_error(1, NULL);
	if (bb && waitpid(bb, &mini->status, 0) == -1)
	{
		reset_fds(mini);
		print_error(1, NULL);
	}
	update_status(mini);
	if (bb)
		return (reset_fds(mini), clear_array(args), true);
	return (reset_fds(mini), clear_array(args), false);
}

short	commands(t_mini *mini, t_pipe *curr)
{
	char	**args;
	char	*path;
	char	**env;

	args = list_to_args(curr->token);
	if (ex_redirections(mini, curr))
		exit (EXIT_FAILURE);
	if (is_built_in(mini, args))
		exit (get_status(false, false));
	else
	{
		if (!args[0])
			exit(mini->status);
		path = is_absolute_path(args[0]);
		if (!path)
			check_path(mini, &path, args[0]);
		if (get_heredoc_is_cntrl_c(false, false) == 2)
			exit(mini->status);
		env = get_env_array(mini->env);
		execve(path, args, env);
		print_error(clear_array(env) + clear_array(args) + 125, PRINT_CMDNF);
	}
	return (clear_array(args), EXIT_SUCCESS);
}

pid_t	make_pipe(t_mini *mini, t_pipe *curr, int n_pipe)
{
	int			pipe_fd[2];
	pid_t		bb;

	if (pipe(pipe_fd) == -1)
		print_error(1, NULL);
	bb = fork();
	if (bb == -1)
		print_error(1, NULL);
	if (!bb)
	{
		signal(SIGINT, exit);
		signal(SIGQUIT, exit);
		if (n_pipe < mini->num_pipes)
		{
			close(pipe_fd[0]);
			dup2(pipe_fd[1], 1);
			close(pipe_fd[1]);
		}
		commands(mini, curr);
		exit(mini->status);
	}
	close(pipe_fd[1]);
	dup2(pipe_fd[0], 0);
	close(pipe_fd[0]);
	return (bb);
}

void	execute_cmd(t_mini *mini)
{
	int		n_pipes;
	t_pipe	*iter;
	pid_t	*pid;

	n_pipes = 0;
	if (command(mini))
		return ;
	iter = mini->pipe;
	pid = is_malloc_error(ft_calloc(mini->num_pipes + 1, sizeof(pid_t)));
	while (n_pipes < (mini->num_pipes + 1))
	{
		pid[n_pipes] = make_pipe(mini, iter, n_pipes);
		iter = iter->next;
		n_pipes++;
	}
	n_pipes = 0;
	while (n_pipes < (mini->num_pipes + 1))
	{
		waitpid(pid[n_pipes], &mini->status, 0);
		n_pipes++;
	}
	free(pid);
	update_status(mini);
	reset_fds(mini);
}
