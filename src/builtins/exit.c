/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 16:43:52 by lgracia-          #+#    #+#             */
/*   Updated: 2025/06/12 17:36:38 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	parsing_exit(char **args)
{
	int	i;

	if (ft_strlen(args[1]) > 20)
		print_error(2, "exit\n(^v^): numeric argument required");
	if (args[1][0] && (args[1][0] == '+' || args[1][0] == '-') \
			&& !args[1][1])
		print_error(2, "exit\n(^v^): numeric argument required");
	i = 0 + (args[1][0] && (args[1][0] == '+' || args[1][0] == '-'));
	while (args[1][i])
	{
		if (!ft_isdigit(args[1][i]))
			print_error(2, "exit\n(^v^): numeric argument required");
		i++;
	}
}

int	ft_is_over_flow(char *args)
{
	int		iter;
	long	prev;
	long	curr;

	iter = 0;
	curr = 0;
	while (args[iter])
	{
		prev = curr;
		curr = args[iter] - '0' + curr * 10;
		if (curr < prev)
			return (true);
		iter++;
	}
	return (false);
}

int	builtin_exit(t_mini *mini, char **args, int num_args)
{
	if (num_args == 1)
		exit(mini->status);
	else if ((num_args >= 2))
	{
		parsing_exit(args);
		if (num_args > 2)
			return (ft_putstr_fd("exit\n(^v^): exit: too many arguments\n", 2), \
			get_status(true, 1));
		printf("exit\n");
		if (mini->pipe)
			clear_pipe(mini);
		if (ft_is_over_flow(args[1]))
		{
			ft_putstr_fd("numeric argument required\n", 2);
			exit(2);
		}
		exit((unsigned char)ft_atoi(args[1]));
	}
	return (EXIT_SUCCESS);
}
