/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_here_doc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 17:58:42 by lgracia-          #+#    #+#             */
/*   Updated: 2025/06/14 13:12:57 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

short	parse_pipe(char *s, int *i)
{
	if (s[*i] == '|')
	{
		if (!s[*i + 1])
			return (1);
		if (next_is_pipe(&s[*i]))
			return (1);
		(*i)++;
		while (s[*i] && !blanks(s[*i]))
			(*i)++;
	}
	return (0);
}

void	print_here_doc(int fd)
{
	char	*buff;
	int		r;

	printf("\e[35mHere_doc \"");
	while (1)
	{
		buff = ft_calloc(sizeof(char), 11);
		r = read(fd, buff, 10);
		if (r < 0)
			print_error(1, "Read of here_doc error\n");
		if (!r)
		{
			free(buff);
			break ;
		}
		printf("\e[93m%s\e[35m", buff);
		free(buff);
	}
	printf("\e[35m\"\n\e[0m");
}

void	add_here_doc(int **fd, t_mini *mini)
{
	int	i;

	i = 0;
	while ((*fd)[i] && (*fd)[i] != -2)
	{
		if ((*fd)[i] > 0)
			mini->pipe[i].fd_here_doc = (*fd)[i];
		i++;
	}
	free(*fd);
}
