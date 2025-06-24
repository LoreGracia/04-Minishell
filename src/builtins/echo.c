/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 16:42:35 by lgracia-          #+#    #+#             */
/*   Updated: 2025/06/04 14:59:15 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static short	parsing_echo(char *arg)
{
	int	i;

	i = 1;
	if (!arg)
		return (false);
	if (arg[0] && arg[0] == '-' && arg[1])
	{
		while (arg[i] && arg[i] == 'n')
			i++;
		if (!arg[i])
			return (true);
	}
	return (false);
}

static void	print_args(char **args, int pos)
{
	while (args[pos])
	{
		printf("%s", args[pos]);
		if (args[pos + 1])
			printf(" ");
		pos++;
	}
}

static void	process_echo(char **args, int pos1, int pos2)
{
	int	flag;

	while (args[pos1])
	{
		flag = parsing_echo(args[pos1]);
		while (flag)
		{
			pos1++;
			pos2++;
			flag = parsing_echo(args[pos1]);
		}
		if (!flag)
			break ;
	}
	flag = parsing_echo(args[pos1 - 1]);
	pos2 = pos1;
	print_args(args, pos2);
	if (!flag)
		printf("\n");
}

int	builtin_echo(char **args, int num_args)
{
	if (num_args == 1)
		printf("\n");
	if (num_args >= 2)
		process_echo(args, 1, 2);
	return (get_status(true, EXIT_SUCCESS));
}
