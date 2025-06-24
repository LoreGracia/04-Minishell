/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 16:44:43 by lgracia-          #+#    #+#             */
/*   Updated: 2025/06/11 18:09:44 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

short	set_var_env(t_env **env, char *arg, char *key, short flag)
{
	char	*tmp;
	t_env	*i;

	i = *env;
	while (i)
	{
		if (flag == append && !ft_strncmp(i->key, key, -1))
		{
			tmp = i->value;
			i->value = ft_strjoin(tmp, &arg[ft_strchrpos(arg, '=') + 1]);
			return (free(tmp), true);
		}
		else if (flag == replace && !ft_strncmp(i->key, key, -1))
		{
			free(i->value);
			i->value = ft_strdup(&arg[ft_strchrpos(arg, '=') + 1]);
			return (true);
		}
		i = i->next;
	}
	return (false);
}

int	get_env_len(t_env *env)
{
	int		len;

	len = 0;
	while (env)
	{
		if (env->key)
			len++;
		env = env->next;
	}
	return (len);
}

char	*get_value_env(t_env *env, char *key)
{
	if (!env || !key)
		return (NULL);
	while (env)
	{
		if (!ft_strncmp(env->key, key, -1))
			return (env->value);
		env = env->next;
	}
	return ("");
}

char	**get_env_array(t_env *env)
{
	int		i;
	char	**env_array;
	char	*tmp;

	if (!env)
		return (NULL);
	env_array = is_malloc_error(ft_calloc(sizeof(char *), \
	(get_env_len(env) + 1)));
	i = 0;
	while (env)
	{
		tmp = ft_strjoin(env->key, "=");
		if (!tmp)
			print_error(1, NULL);
		env_array[i] = tmp;
		if (env->value && env->value[0])
		{
			env_array[i] = is_malloc_error(ft_strjoin(env_array[i], \
			env->value));
			free(tmp);
		}
		env = env->next;
		i++;
	}
	return (env_array);
}

int	builtin_env(t_env *env, int num_args)
{
	if (num_args != 1)
	{
		ft_putstr_fd("env: too many arguments\n", 2);
		return (get_status(true, EXIT_FAILURE));
	}
	while (env)
	{
		if (env->key && env->value[0])
			printf("%s=%s\n", env->key, env->value);
		env = env->next;
	}
	return (get_status(true, EXIT_SUCCESS));
}
