/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 10:19:39 by lgracia-          #+#    #+#             */
/*   Updated: 2025/06/10 13:14:24 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	get_status(short flag, int status)
{
	static int	new;

	if (flag)
		new = status;
	return (new);
}

short	get_heredoc_is_cntrl_c(short flag, short is_heredoc)
{
	static short	bool;

	if (flag)
		bool = is_heredoc;
	return (bool);
}

void	cntrl_c_redir(int num)
{
	(void)num;
	get_heredoc_is_cntrl_c(true, false);
}

void	cntrl_c(int num)
{
	(void)num;
	printf("\n");
	get_status(true, 130);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	signals(short *is_redir)
{
	if (*is_redir != true)
		signal(SIGINT, cntrl_c);
	else
		signal(SIGINT, cntrl_c_redir);
	signal(SIGQUIT, SIG_IGN);
}
