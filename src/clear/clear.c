/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:05:53 by lgracia-          #+#    #+#             */
/*   Updated: 2025/06/03 12:08:47 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

short	clear_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return (false);
	while (array[i])
	{
		if (array[i])
			free(array[i]);
		array[i] = NULL;
		i++;
	}
	if (array)
		free(array);
	array = NULL;
	return (true);
}

short	clear_lst(t_token *lst)
{
	t_token	*lsti;

	if (!lst)
		return (false);
	lsti = (t_token *)lst->next;
	while (lsti)
	{
		free(lst);
		lst = lsti;
		lsti = (t_token *)lst->next;
	}
	if (lst)
		free(lst);
	lst = NULL;
	return (true);
}

short	clear_env(t_env	*env)
{
	t_env	*envi;

	if (!env)
		return (false);
	envi = env;
	while (env)
	{
		free(envi->key);
		free(envi->value);
		envi = env->next;
		free(env);
		env = envi;
	}
	free(env);
	return (true);
}

short	clear_pipe(t_mini *mini)
{
	int	i;

	if (!mini)
		return (false);
	i = -1;
	while (++i != mini->num_pipes + 1 && mini->pipe)
	{
		if (mini->pipe[i].token)
			clear_lst(mini->pipe[i].token);
		if (mini->pipe[i].token_array)
			clear_array(mini->pipe[i].token_array);
		if (mini->pipe[i].fd_here_doc)
			close(mini->pipe[i].fd_here_doc);
	}
	if (mini->original)
		free(mini->original);
	free(mini->pipe);
	return (true);
}

short	print_error(short code_status, char *message)
{
	if (message)
	{
		ft_putstr_fd(message, 2);
		ft_putstr_fd("\n", 2);
		exit(code_status);
	}
	perror(MALLOC);
	exit(code_status);
}
