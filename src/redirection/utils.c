/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 13:09:49 by lgracia-          #+#    #+#             */
/*   Updated: 2025/06/09 13:13:58 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

short	reset_fds(t_mini *mini)
{
	if (dup2(mini->term[0], STDIN_FILENO) == -1)
		return (perror(""), EXIT_FAILURE);
	if (dup2(mini->term[1], STDOUT_FILENO) == -1)
		return (perror(""), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

short	parsing_open(int type, char *name_file)
{
	if (type == in)
	{
		if (access(name_file, F_OK) == -1)
			return (perror(""), EXIT_FAILURE);
		else if (access(name_file, R_OK) == -1)
			return (perror("Permission denied"), EXIT_FAILURE);
	}
	else if (type == out || type == append)
	{
		if (!access(name_file, F_OK) && access(name_file, W_OK) == -1)
			return (perror("Permission denied"), EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
