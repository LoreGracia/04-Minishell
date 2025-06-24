/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:59:36 by lgracia-          #+#    #+#             */
/*   Updated: 2025/06/12 12:57:37 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

char	*input_parse(char *read_line, t_mini *mini)
{
	int		*fd;
	int		error;

	error = init_here_doc(&read_line, &fd, mini);
	if (error == -2)
		return (free(read_line), is_syntax(mini));
	if (error)
		return (free(fd), free(read_line), is_syntax(mini));
	error = parse_end(&mini->num_pipes, &read_line, &(mini->original));
	if (error)
		return (free(fd), free(read_line), is_syntax(mini));
	mini->pipe = lexer_init(&read_line, *mini);
	if (mini->pipe)
		add_here_doc(&fd, mini);
	else
	{
		if (ambiguous_in_expander(read_line))
			return (free(read_line), add_history(mini->original), free(fd), \
			clear_pipe(mini), printf("(^v^): ambiguous redirect\n"), NULL);
		return (free(fd), free(read_line), is_syntax(mini));
	}
	add_history(mini->original);
	free(mini->original);
	mini->original = NULL;
	return (read_line);
}

void	is_read_line(t_mini *mini, char *av, char **read_line)
{
	if (array_to_lst(mini, *read_line))
		print_error(1, NULL);
	if (av && !ft_strcmp(av, "print_arg"))
		print_token(*mini);
	if (mini->pipe[0].token_array[0])
		execute_cmd(mini);
	free(*read_line);
	clear_pipe(mini);
}

void	read_loop_ocurrence(char **read_line, t_mini *mini, char *av)
{
	if (!read_line_is_blanks(*read_line))
	{
		add_history(*read_line);
		free(*read_line);
	}
	else
	{
		mini->original = is_malloc_error(ft_strdup(*read_line));
		*read_line = input_parse(*read_line, mini);
		if (*read_line)
			is_read_line(mini, av, read_line);
		else if (*read_line && !(*read_line)[0])
			free(*read_line);
	}
}

int	read_loop(t_mini *mini, char *av)
{
	char	*read_line;

	while ("0.0")
	{
		get_heredoc_is_cntrl_c(true, false);
		read_line = readline("\e[32m(^v^) \e[0m");
		mini->status = get_status(false, mini->status);
		if (!read_line)
			exit(0);
		if (read_line && read_line[0])
			read_loop_ocurrence(&read_line, mini, av);
		else if (read_line && !read_line[0])
			free(read_line);
	}
}

int	main(int ac, char **av, char **pc_env)
{
	t_mini	mini;

	(void)ac;
	if (!pc_env || !*pc_env)
		print_error(1, "(^v^) Error: null ptr env");
	if (av[1] && ft_strcmp(av[1], "print_arg"))
		print_error(1, "Unreconized argument\n");
	if (av[1] && av[2])
		print_error(1, "Too many arguments\n");
	mini.term[0] = dup(STDIN_FILENO);
	mini.term[1] = dup(STDOUT_FILENO);
	mini.status = 0;
	mini.is_redir_signals = false;
	signals(&(mini.is_redir_signals));
	mini.env = is_malloc_error(env_to_lst(pc_env));
	read_loop(&mini, av[1]);
	clear_env(mini.env);
	rl_clear_history();
}
