/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 15:35:19 by lgracia-          #+#    #+#             */
/*   Updated: 2025/06/12 12:39:17 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	is_ambiguous_redir(int *start, char **tmp, char *s)
{
	int	i;

	i = *start - (*start);
	while (i && !blanks(s[i]))
		i--;
	if ((s[i] == '>' || s[i] == '<') && (!(*tmp)[0] || is_char(*tmp, ' ')))
	{
		if ((i && s[i - 1] == '<') || (!i && s[i + 1] && s[i + 1] == '<'))
			return (0);
		(*start)++;
		get_status(true, 1);
		return (1);
	}
	return (0);
}

int	is_char(char *read_line, char c)
{
	int	i;

	i = 0;
	while (read_line [i] && !((c == '|' && read_line[i] == c) || \
	(c == ' ' && blanks(read_line[i]))))
		i++;
	if (read_line[i])
		return (1);
	return (0);
}

char	*theres_end(char *s, int start, char *tmp, int len)
{
	char	*new;

	if (s[start + len])
	{
		new = is_malloc_error(ft_strjoin(tmp, &s[start + len]));
		free(s);
		free(tmp);
		return (new);
	}
	else
	{
		free(s);
		return (tmp);
	}
}

char	*replacesubstr(char *s, int *start, char *replace, int len)
{
	char	*new;
	char	*tmp;

	if (*start)
	{
		new = is_malloc_error(ft_substr(s, 0, *start));
		if (replace)
		{
			tmp = is_malloc_error(ft_strjoin(new, replace));
			free(new);
			free(replace);
			return (theres_end(s, *start, tmp, len));
		}
		else
			return (theres_end(s, *start, new, len));
	}
	else
	{
		if (replace)
			return (theres_end(s, *start, replace, len));
		else
		{
			return (theres_end(s, *start, ft_strdup(""), len));
		}
	}
}
