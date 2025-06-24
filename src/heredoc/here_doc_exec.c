/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 12:47:24 by lgracia-          #+#    #+#             */
/*   Updated: 2025/06/10 16:23:01 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	here_doc_expand(char **read_line, int *err, t_mini mini)
{
	int		i;

	if (!*err)
	{
		i = 0;
		while ((*read_line)[i])
		{
			if ((*read_line)[i] == '$')
				expand(read_line, &i, mini, 0);
			else
				i++;
		}
	}
}

int	hd_exec_signal_c(char **closestr, int *tmp, t_mini *mini, \
	rl_getc_func_t *rltmp)
{
	rl_getc_function = rltmp;
	get_heredoc_is_cntrl_c(true, 2);
	(*mini).is_redir_signals = false;
	mini->status = get_status(true, 130);
	signals(&((*mini).is_redir_signals));
	return (close(tmp[1]), free(*closestr), tmp[0]);
}

int	hd_exec_signal_d(char **closestr, int *tmp, t_mini *mini, \
	rl_getc_func_t *rltmp)
{
	rl_getc_function = rltmp;
	get_heredoc_is_cntrl_c(true, 3);
	(*mini).is_redir_signals = false;
	mini->status = get_status(true, 0);
	signals(&((*mini).is_redir_signals));
	return (close(tmp[1]), free(*closestr), tmp[0]);
}

int	hd_exec_loop(char **closestr, int *err, t_mini *mini, \
	rl_getc_func_t *rltmp)
{
	int		tmp[2];
	char	*read_line;

	pipe(tmp);
	while (true)
	{
		rl_getc_function = getc;
		read_line = readline("\e[30mheredoc>\e[0m ");
		if (!get_heredoc_is_cntrl_c(false, false))
			return (free(read_line), \
			hd_exec_signal_c(closestr, tmp, mini, rltmp));
		if (!read_line)
			return (hd_exec_signal_d(closestr, tmp, mini, rltmp));
		if (!ft_strcmp(read_line, *closestr))
			break ;
		here_doc_expand(&read_line, err, *mini);
		write(tmp[1], read_line, ft_strlen(read_line));
		write(tmp[1], "\n", 1);
		free(read_line);
	}
	free(read_line);
	return (free(*closestr), close(tmp[1]), tmp[0]);
}

int	here_doc_exec(char **closestr, int *err, t_mini *mini)
{
	int					fd;
	rl_getc_func_t		*rltmp;

	rltmp = rl_getc_function;
	if (!*closestr)
		return (-1);
	(*mini).is_redir_signals = true;
	get_heredoc_is_cntrl_c(true, true);
	signals(&((*mini).is_redir_signals));
	fd = hd_exec_loop(closestr, err, mini, rltmp);
	(*mini).is_redir_signals = false;
	signals(&((*mini).is_redir_signals));
	rl_getc_function = rltmp;
	return (fd);
}
