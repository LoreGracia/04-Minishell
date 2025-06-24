/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 18:11:25 by lgracia-          #+#    #+#             */
/*   Updated: 2025/06/12 12:33:17 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	is_next_expand(char *s, int *start)
{
	int	i;

	i = *start;
	if (i && !blanks(s[i - 1]))
	{
		while (s[i] && !blanks(s[i]))
		{
			i++;
			if (s[i] && s[i] == '$')
			{
				*start = i;
				return (1);
			}
		}
	}
	return (0);
}

char	*find_envv(char *s, int *start, int *len)
{
	char	*tmp;

	(*len)++;
	while (s[*start + *len] && blanks(s[*start + *len]) \
		&& s[*start + *len] != '|' && s[*start + *len] != '$' \
		&& s[*start + *len] != '"' \
		&& s[*start + *len] != '\'')
		(*len)++;
	tmp = is_malloc_error(ft_calloc(1, *len + 2));
	if (!ft_strlcpy(tmp, &s[*start + 1], *len))
	{
		free(tmp);
		tmp = is_malloc_error(ft_strdup(""));
	}
	return (tmp);
}

char	*cp_venv(t_env *env, char *tmp)
{
	char	*new;

	new = get_value_env(env, tmp);
	if (tmp)
		free(tmp);
	if (!new)
		return (ft_strdup(""));
	else
		return (ft_strdup(new));
}

char	*is_expansion(char *s, int *start, t_mini mini, short redir_flag)
{
	char	*tmp;
	int		len;

	if (s[*start + 1] == '?')
	{
		tmp = is_malloc_error(ft_itoa(mini.status));
		s = replacesubstr(s, start, tmp, 2);
	}
	else if (!next_is_pipe(&(s[*start])))
	{
		len = 0;
		tmp = find_envv(s, start, &len);
		tmp = is_malloc_error(cp_venv(mini.env, tmp));
		if (redir_flag && is_ambiguous_redir(start, &tmp, s))
			return (free(tmp), NULL);
		s = replacesubstr(s, start, tmp, len);
	}
	else
		(*start)++;
	if (s[*start] && (s[*start] == '$'
			|| (is_next_expand(s, start) && !tmp[0])))
		return (expand(&s, start, mini, redir_flag));
	return (s);
}

char	*expand(char **string, int *start, t_mini mini, short redir_flag)
{
	char	*tmp;
	int		i;
	char	*s;

	s = *string;
	i = 0;
	if (s[*start] && s[*start] != 36)
		return (s);
	while (s[*start + i] && s[*start + 1 + i]
		&& s[*start] == 36 && s[*start + i + 1] == 36)
		i += 2;
	if (i)
	{
		tmp = is_malloc_error(ft_strdup(""));
		s = replacesubstr(s, start, tmp, i);
		*string = s;
	}
	if (s[*start] && s[*start] == 36 && s[*start + 1])
		*string = is_expansion(s, start, mini, redir_flag);
	return (*string);
}
