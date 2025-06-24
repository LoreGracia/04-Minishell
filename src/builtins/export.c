/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 16:45:56 by lgracia-          #+#    #+#             */
/*   Updated: 2025/06/12 17:36:38 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static void	print_env_export(t_env *env)
{
	if (!env)
		return ;
	while (env)
	{
		if (env->key && env->value)
			printf("declare -x %s=\"%s\"\n", env->key, env->value);
		else if (env->key)
			printf("declare -x %s\n", env->key);
		env = env->next;
	}
	get_status(true, 0);
}

short	parsing_export(char *value, int *flag)
{
	int	i;

	if (!value)
		return (false);
	if (!ft_isalpha(value[0]) && value[0] != '_')
		return (false);
	i = 1;
	while (value[i] && value[i] != '+' && value[i] != '=')
	{
		if (!ft_isalnum(value[i]))
			return (false);
		i++;
	}
	if (!value[i])
		return (true);
	if (value[i] == '+')
		*flag = i;
	if (*flag == -1 && !value[i])
		return (true);
	if ((*flag != -1 && value[i + 1] != '\0' && value[i + 1] != '=')
		|| (*flag != -1 && !value[i + 1]))
		return (false);
	return (true);
}

void	select_add(t_env **env, char *arg, int plus)
{
	char	*find;
	char	*key;
	int		len;
	short	eql;

	len = plus;
	if (plus == -1)
		len = ft_strchrpos(arg, '=');
	if (!len)
		len = ft_strlen(arg);
	eql = 0 || ft_strchrpos(arg, '=');
	key = is_malloc_error(ft_strndup(arg, len));
	find = find_key_env(*env, key);
	if (find)
	{
		if (plus == -1 && eql && (arg[len + 1] || !arg[len + 1]))
			set_var_env(env, arg, key, replace);
		else if (plus != -1 && eql && (arg[len + 1] || !arg[len + 1]))
			set_var_env(env, arg, key, append);
	}
	else
		no_value(env, key, arg, plus);
	free(key);
}

void	add_variable(t_mini *mini, char **args)
{
	int	i;
	int	plus;

	i = 1;
	plus = -1;
	while (args[i])
	{
		if (parsing_export(args[i], &plus))
			select_add(&mini->env, args[i], plus);
		else
		{
			mini->status = 0 || printf("(^v^): export: `%s': %s\n", \
				args[i], "not a valid identifier");
		}
		i++;
	}
	get_status(true, 0);
	if (mini->status)
		get_status(true, mini->status);
}

int	builtin_export(t_mini *mini, char **args, int num_args)
{
	if (num_args == 1)
		print_env_export(mini->env);
	else
		add_variable(mini, args);
	return (EXIT_SUCCESS);
}
