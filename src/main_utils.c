/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 15:52:03 by lgracia-          #+#    #+#             */
/*   Updated: 2025/06/12 10:36:35 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	blanks(const char i)
{
	if (i == ' ' || i == '\r' || i == '\n')
		return (false);
	if (i == '\t' || i == '\v' || i == '\f')
		return (false);
	return (true);
}

int	read_line_is_blanks(char *read_line)
{
	int	i;

	i = jump_blank(read_line);
	if (!read_line[i])
		return (false);
	return (true);
}

int	parse_end(int *npipes, char **read_line, char **original)
{
	*npipes = ccount(*read_line, '|');
	if (*npipes >= 0)
		return (0);
	else if (*npipes == -2)
		return (add_history(*original), -1);
	else
		return (-2);
}

int	ambiguous_in_expander(char *read_line)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = "";
	while (read_line[i])
	{
		if (read_line[i] == '$')
		{
			if (is_ambiguous_redir(&i, &tmp, read_line))
				return (1);
		}
		i++;
	}
	return (0);
}

char	*is_syntax(t_mini *mini)
{
	ft_putstr_fd(SYNTAX, 2);
	add_history(mini->original);
	free(mini->original);
	get_status(true, 2);
	return (NULL);
}
