/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:54:55 by lgracia-          #+#    #+#             */
/*   Updated: 2025/06/12 17:36:38 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_H
# define MINI_H

# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <signal.h>
# include <dirent.h>
# include <string.h>
# include <sys/ioctl.h>
# include <termcap.h>
# include <termios.h>
# include <sys/stat.h>

# define MALLOC			"\e[31;5mMalloc fail\n\e[0m"
# define SYNTAX			"(^v^): syntax error near unexpected token\n"
# define PRINT_ARRAY	"\e[35mPipe[%d]array_token[%d]\"\e[93m%s\e[35m\"\n\e[0m"
# define PRINT_CMDNF	"(^v^): command not found"
# define AMBIGUOS_REDIR	1	

enum e_bolean
{
	false,
	true,
};

enum e_type
{
	flag,
	arg,
	redir = 1 << 5,
	in = 1 << 6 | redir,// <
	out = 1 << 7 | redir,// >
	append = 1 << 8 | redir,//>>
	heredoc = 1 << 9 | redir,//<<
	add,
	replace,
};

typedef struct s_env
{
	char	*key;
	char	*value;
	void	*next;
}				t_env;

typedef struct s_token
{
	char	*token;
	int		type;
	void	*next;
}				t_token;

typedef struct s_pipe
{
	t_token	*token;
	char	**token_array;
	int		fd_here_doc;
	void	*next;
}				t_pipe;

typedef struct s_mini
{
	t_pipe	*pipe;
	int		status;
	int		term[2];
	int		num_pipes;
	char	*original;
	short	is_redir_signals;
	t_env	*env;
}				t_mini;

/*	main_utils.c			*/
int		blanks(const char i);
int		read_line_is_blanks(char *read_line);
int		parse_end(int *npipes, char **read_line, char **original);
char	*is_syntax(t_mini *mini);
int		ambiguous_in_expander(char *read_line);

/*	utils.c			*/
int		is_quote(char *read_line, int i);
int		next_is_pipe(char *read_line);
int		jump_blank(char *read_line);
int		parse_redirection(char *s, int *i);
void	*ft_memsetint(void *s, int c, size_t n);

/*	here_doc/here_doc.c		*/
void	is_heredoc_ocurrence(char **read_line, int *iter, int *fd);
int		init_here_doc(char **read_line, int **fd, t_mini *mini);
/*	here_doc/here_doc_closestr.c		*/
char	*is_closestr(char **read_line, int *iter, int *err, t_mini mini);
/*	here_doc/here_doc_exec.c		*/
int		here_doc_exec(char **closestr, int *err, t_mini *mini);
/*	here_doc/here_doc_utils.c		*/
int		heredoc_count(char *s, t_mini mini);
void	is_heredoc_ocurrence_delete(char **read_line, int *i, int *j);
int		is_heredoc_blanksnquotes(char *s, int i, t_mini mini);
/*	here_doc/add_here_doc.c	*/
short	parse_pipe(char *s, int *i);
void	add_here_doc(int **fd, t_mini *mini);
void	print_here_doc(int fd);

/*	char_count.c	*/
int		ccount(char *read_line, char c);

/*	clear/utils.c	*/
void	*is_malloc_error(void *ptr);

/*	clear/clear.c	*/
short	print_error(short code_status, char *message);
short	clear_array(char **array);
short	clear_lst(t_token *lst);
short	clear_pipe(t_mini *mini);
short	clear_env(t_env *env);

/*	lexer/lexer.c	*/
void	print_token(t_mini mini);
void	print_lst_token(t_mini mini);
t_pipe	*lexer_init(char **readline, t_mini mini);
/*	lexer/split_token.c	*/
char	**split_token(char **s, char c, t_mini mini);
/*	lexer/split_token_utils.c	*/
short	is_redirection(char *readline, int i, char c);
int		split_double_quotes(char **string, int *start, t_mini mini, char c);
int		split_single_quote(char **string, int *start, t_mini mini, char c);
/*	lexer/split_token_words.c	*/
short	words(char *s, char c, int *old);
/*	lexer/lexer_to_lst.c	*/
int		array_to_lst(t_mini *mini, char *read_line);
/*	lexer/lexer_to_lst_utils.c	*/
int		is_quoted_redirection(char c, int type, char *read_line, int *j);

/* env_management.c */
t_env	*new_env_v(char *variable);
t_env	*env_to_lst(char **envpc);
void	envadd_back(t_env **lst, t_env *new);
t_env	*new_env_k_v(char *key, char*value);

/*	expander/expander.c	*/
char	*expand(char **string, int *start, t_mini mini, short redir_flag);
/*	expander/expander_utils.c	*/
char	*replacesubstr(char *s, int *start, char *replace, int len);
int		is_char(char *read_line, char c);
int		is_ambiguous_redir(int *start, char **tmp, char *s);

/*	utils.c	*/
int		parse_redirection(char *s, int *i);
/*	signal.c	*/
void	signals(short *is_redir);
void	cntrl_c_redir(int num);
int		get_status(short flag, int status);
short	get_heredoc_is_cntrl_c(short flag, short is_heredoc);

/* builtins */
int		builtin_pwd(void);
int		builtin_echo(char **args, int num_args);
char	*get_value_env(t_env *env, char *key);
char	**get_env_array(t_env *env);
short	set_var_env(t_env **env, char *arg, char *key, short flag);
int		builtin_env(t_env *env, int num_args);
int		builtin_export(t_mini *mini, char **args, int num_args);
char	*get_pwd(void);
int		builtin_cd(t_mini *mini, char **args, int num_args);
int		builtin_unset(t_mini *mini, char **args, int num_args);
int		builtin_exit(t_mini *mini, char **args, int num_args);
/* builtins/utils.c */
void	no_value(t_env **env, char *key, char *arg, int len);
char	*find_key_env(t_env *env, char *key);

/* redirections/redirections.c */
short	redirection_in(t_mini *mini, t_token *curr, char *name_file);
short	redirection_out(t_mini *mini, t_token *curr, char *name_file);
short	redirection_append(t_mini *mini, t_token *curr, char *name_file);
short	ex_redirections(t_mini *mini, t_pipe *curr);
/* redirections/utils.c */
short	parsing_open(int type, char *name_file);
short	reset_fds(t_mini *mini);

/* execute/execute.c */
char	*get_executable_path(t_mini mini, char *cmd);
char	*is_absolute_path(char *cmd);
void	check_path(t_mini *mini, char **path, char *arg);
/* execute/utils.c */
void	execute_cmd(t_mini *mini);
int		size_filtered_list(t_token *iter);
char	**list_to_args(t_token *iter);
size_t	size_array(char **array);
short	is_built_in(t_mini *mini, char **args);
pid_t	child_pid(t_mini *mini, char **args);

#endif
