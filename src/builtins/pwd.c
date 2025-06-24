/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 16:37:21 by lgracia-          #+#    #+#             */
/*   Updated: 2025/06/11 18:34:37 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	builtin_pwd(void)
{
	char	*dir;

	dir = get_pwd();
	if (!dir)
	{
		ft_putstr_fd("(^v^): cannot access parent directories: \
No such file or directory\n", 2);
		return (get_status(true, EXIT_FAILURE));
	}
	if (dir)
	{
		printf("%s\n", dir);
		free(dir);
		dir = NULL;
	}
	return (get_status(true, EXIT_SUCCESS));
}
