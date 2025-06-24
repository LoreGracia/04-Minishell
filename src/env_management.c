/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 17:27:57 by lgracia-          #+#    #+#             */
/*   Updated: 2025/05/17 16:41:37 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

t_env	*new_env_k_v(char *key, char*value)
{
	t_env	*v;

	v = ft_calloc(sizeof(t_env), 1);
	if (!v)
		print_error(1, NULL);
	v->key = ft_strdup(key);
	v->value = ft_strdup(value);
	if (!v->key || !v->value)
		print_error(1, NULL);
	v->next = NULL;
	return (v);
}

t_env	*new_env_v(char *variable)
{
	int		alen;
	int		blen;
	t_env	*v;

	v = is_malloc_error(ft_calloc(sizeof(t_env), 1));
	blen = ft_strlen(ft_strchr(variable, '='));
	alen = ft_strlen(variable) - blen;
	v->key = is_malloc_error(ft_calloc(sizeof(char), alen + 1));
	v->value = is_malloc_error(ft_calloc(sizeof(char), blen));
	ft_strlcpy(v->key, variable, alen + 1);
	ft_strlcpy(v->value, &variable[alen + 1], blen);
	v->next = NULL;
	return (v);
}

t_env	*envlast(t_env *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	envadd_back(t_env **lst, t_env *new)
{
	t_env	*last;

	if (!*lst)
		*lst = new;
	else
	{
		last = envlast(*lst);
		last->next = new;
	}
}

t_env	*env_to_lst(char **envpc)
{
	int		i;
	t_env	*env;
	t_env	*tmp;

	i = 0;
	env = new_env_v(envpc[i]);
	tmp = env;
	while (envpc[++i])
		envadd_back(&tmp, new_env_v(envpc[i]));
	return (env);
}
