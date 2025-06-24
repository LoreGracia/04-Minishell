/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 16:57:44 by lgracia-          #+#    #+#             */
/*   Updated: 2025/06/12 18:18:30 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

short	change(t_env **env, char *key, char *dir)
{
	t_env	*iter;

	if (!env || !*env)
		return (false);
	iter = *env;
	while (iter)
	{
		if (!ft_strncmp(iter->key, key, -1))
		{
			if (iter->value)
				free(iter->value);
			iter->value = dir;
			return (true);
		}
		iter = iter->next;
	}
	if (dir)
		free(dir);
	return (false);
}

char	*get_pwd(void)
{
	char	*dir;

	dir = ft_calloc(PATH_MAX, 1);
	if (!dir)
		print_error(1, NULL);
	if (getcwd(dir, PATH_MAX) == NULL)
		return (free(dir), NULL);
	return (dir);
}

int	update_pwd(t_mini *mini, char **args)
{
	char	*old_path;
	char	*path;
	char	*dir;

	old_path = is_malloc_error(ft_strdup(get_value_env(mini->env, "PWD")));
	path = args[1];
	if (!path || !path[0])
	{
		if (chdir(get_value_env(mini->env, "HOME")) != 0)
			return (free(old_path), \
			ft_putstr_fd("(^v^): cd: HOME not set\n", 2), 1);
	}
	else if (chdir(path) == -1)
	{
		if (access(path, R_OK | W_OK | X_OK))
			return (free(old_path), perror("cd"), 1);
		return (free(old_path), perror("cd"), 1);
	}
	dir = get_pwd();
	if (!dir)
		return (free(old_path), EXIT_FAILURE);
	change(&mini->env, "PWD", dir);
	change(&mini->env, "OLDPWD", old_path);
	return (EXIT_SUCCESS);
}

int	builtin_cd(t_mini *mini, char **args, int num_args)
{
	if (num_args > 2)
	{
		printf("(^v^): cd: too many arguments\n");
		return (get_status(true, EXIT_FAILURE));
	}
	if (num_args == 1)
		get_status(true, update_pwd(mini, args));
	else
		get_status(true, update_pwd(mini, args));
	return (EXIT_SUCCESS);
}
