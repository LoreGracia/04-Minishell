/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 16:59:47 by lgracia-          #+#    #+#             */
/*   Updated: 2025/06/12 17:36:38 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

short	parsing_unset(char *value)
{
	int	i;

	if (!value)
		return (false);
	if (!ft_isalpha(value[0]) && value[0] != '_')
		return (false);
	i = 1;
	while (value[i])
	{
		if (!ft_isalnum(value[i]))
			return (false);
		i++;
	}
	return (true);
}

void	del_variable(t_env **env, char *arg)
{
	t_env	*curr;
	t_env	*prev;
	t_env	*rm;

	if (!env || !*env || !arg)
		return ;
	curr = *env;
	prev = NULL;
	while (curr)
	{
		if (!ft_strcmp(curr->key, arg))
		{
			rm = curr;
			if (prev)
				prev->next = curr->next;
			else
				*env = curr->next;
			free(rm->key);
			free(rm->value);
			free(rm);
			return ;
		}
		prev = curr;
		curr = curr->next;
	}
}

void	remove_variable(t_mini *mini, char **args)
{
	int	i;

	i = 1;
	while (args[i])
	{
		if (parsing_unset(args[i]))
			del_variable(&mini->env, args[i]);
		else
			mini->status = 0 || printf("(^v^): unset: `%s': %s\n", \
				args[i], "not a valid identifier");
		i++;
	}
}

int	builtin_unset(t_mini *mini, char **args, int num_args)
{
	if (num_args == 1)
		return (EXIT_SUCCESS);
	else
		remove_variable(mini, args);
	return (EXIT_SUCCESS);
}
