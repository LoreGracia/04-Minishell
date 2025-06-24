/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 16:48:34 by lgracia-          #+#    #+#             */
/*   Updated: 2025/06/12 13:46:49 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

char	*get_executable_path(t_mini mini, char *cmd)
{
	char	**path_env;
	char	*path;
	char	*tmp;
	int		i;

	if (!cmd || !mini.env)
		return (NULL);
	path_env = ft_split(get_value_env(mini.env, "PATH"), ':');
	if (!path_env)
		print_error(1, NULL);
	i = -1;
	while (path_env[++i])
	{
		tmp = ft_strjoin(path_env[i], "/");
		if (!tmp)
			print_error(1, NULL);
		path = ft_strjoin(tmp, cmd);
		if (!path)
			print_error(1, NULL);
		free(tmp);
		if (access(path, F_OK) == 0)
			break ;
		free(path);
	}
	return (clear_array(path_env), path);
}

char	*is_absolute_path(char *cmd)
{
	struct stat	stats;
	int			result;

	if (!cmd)
		return (NULL);
	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, F_OK) == -1)
			print_error(127, "(^v^): No such file or directory");
		result = stat(cmd, &stats);
		if (result == 0 && (stats.st_mode & S_IFMT) == S_IFDIR)
			print_error(126, "(^v^): /: Is a directory");
		else if (result == -1)
			print_error(1, NULL);
		return (cmd);
	}
	return (NULL);
}

void	check_path(t_mini *mini, char **path, char *arg)
{
	*path = get_executable_path(*mini, arg);
	if (!*path)
		print_error(127, PRINT_CMDNF);
}
