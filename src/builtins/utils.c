/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 17:49:28 by lgracia-          #+#    #+#             */
/*   Updated: 2025/06/12 10:13:38 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	no_value(t_env **env, char *key, char *arg, int plus)
{
	short	eql;
	int		len;

	len = plus;
	if (plus == -1)
		len = ft_strchrpos(arg, '=');
	if (!len)
		len = ft_strlen(arg);
	eql = 0 || ft_strchrpos(arg, '=');
	if (plus == -1 && eql && arg[len + 1])
		envadd_back(env, new_env_k_v(key, &arg[len + 1]));
	else if (plus != -1 && eql && arg[len + 1] && arg[len + 2])
		envadd_back(env, new_env_k_v(key, &arg[len + 2]));
	else
		envadd_back(env, new_env_k_v(key, ""));
}

char	*find_key_env(t_env *env, char *key)
{
	if (!env || !key)
		return (NULL);
	while (env)
	{
		if (!ft_strncmp(env->key, key, -1))
			return (env->key);
		env = env->next;
	}
	return (NULL);
}
