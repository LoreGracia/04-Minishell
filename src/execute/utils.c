/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 09:39:13 by codespace         #+#    #+#             */
/*   Updated: 2025/06/11 18:53:39 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	size_filtered_list(t_token *iter)
{
	int	size;

	if (!iter)
		return (0);
	size = 0;
	while (iter)
	{
		if (iter->type & redir && iter->next && iter->type != heredoc)
			iter = iter->next;
		else if (iter->type != heredoc)
			size++;
		iter = iter->next;
	}
	return (size);
}

char	**list_to_args(t_token *iter)
{
	char	**args;
	int		i;

	if (!iter)
		return (NULL);
	i = 0;
	args = ft_calloc(sizeof(char *), size_filtered_list(iter) + 1);
	while (iter)
	{
		if (iter->type & redir && iter->next && iter->type != heredoc)
			iter = iter->next;
		else
		{
			if (iter->type != heredoc)
				args[i++] = is_malloc_error(ft_strdup(iter->token));
		}
		if (iter)
			iter = iter->next;
	}
	return (args);
}

size_t	size_array(char **array)
{
	size_t	i;

	i = 0;
	if (!array || !*array)
		return (i);
	while (array[i])
		i++;
	return (i);
}

short	is_built_in(t_mini *mini, char **args)
{
	char	*cmd;
	size_t	size;

	cmd = args[0];
	size = size_array(args);
	if (!cmd)
		return (reset_fds(mini), false);
	if (!ft_strncmp(cmd, "echo", -1))
		return (builtin_echo(args, size), true);
	if (!ft_strncmp(cmd, "cd", -1))
		return (builtin_cd(mini, args, size), true);
	if (!ft_strncmp(cmd, "pwd", -1))
		return (builtin_pwd(), true);
	if (!ft_strncmp(cmd, "export", -1))
		return (builtin_export(mini, args, size), true);
	if (!ft_strncmp(cmd, "unset", -1))
		return (builtin_unset(mini, args, size), true);
	if (!ft_strncmp(cmd, "env", -1))
		return (builtin_env(mini->env, size), true);
	if (!ft_strncmp(cmd, "exit", -1))
		return (builtin_exit(mini, args, size), true);
	return (false);
}

pid_t	child_pid(t_mini *mini, char **args)
{
	char	**env;
	char	*path;
	pid_t	bb;

	bb = fork();
	if (!bb)
	{
		signal(SIGQUIT, NULL);
		if (!args[0])
			exit(mini->status);
		path = is_absolute_path(args[0]);
		if (!path)
		{
			path = get_executable_path(*mini, args[0]);
			if (!path)
				print_error(127, PRINT_CMDNF);
		}
		if (get_heredoc_is_cntrl_c(false, false) == 2)
			exit(mini->status);
		env = get_env_array(mini->env);
		execve(path, args, env);
		clear_array(env);
		print_error(127, PRINT_CMDNF);
	}
	return (bb);
}
