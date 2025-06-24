# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgracia- <lgracia-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/07 11:35:38 by lgracia-          #+#    #+#              #
#    Updated: 2025/06/12 13:19:28 by lgracia-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CFLAGS = -Wall -Wextra -Werror  -g -fsanitize=address -Wmisleading-indentation -Wparentheses

INCS = inc/

SRCS = clear/clear.c clear/utils.c \
	expander/expander_utils.c expander/expander.c \
	lexer/lexer.c lexer/split_token.c lexer/split_token_words.c lexer/split_token_utils.c lexer/lexer_to_lst.c lexer/lexer_to_lst_utils.c\
	heredoc/here_doc.c heredoc/here_doc_utils.c heredoc/here_doc_closestr.c heredoc/here_doc_exec.c heredoc/add_here_doc.c \
	main.c main_utils.c signal.c env_management.c char_count.c utils.c\
	builtins/echo.c builtins/env.c builtins/exit.c builtins/export.c builtins/pwd.c builtins/cd.c builtins/unset.c builtins/utils.c \
	execute/execute.c execute/get_path.c execute/utils.c \
	redirection/redirections.c redirection/utils.c

DSRCS = $(addprefix src/, $(SRCS))

DOBJ = .obj

OBJS =  $(addprefix $(DOBJ)/, $(SRCS:.c=.o))

DEPS = $(addprefix $(DOBJ)/, $(SRCS:.c=.d))

LIBS =  ./libft/libft.a -ltermcap -lreadline

CC = cc

all: make_lib dir $(NAME)

dir:
	mkdir -p $(DOBJ)
	mkdir -p $(DOBJ)/clear
	mkdir -p $(DOBJ)/expander
	mkdir -p $(DOBJ)/lexer
	mkdir -p $(DOBJ)/builtins
	mkdir -p $(DOBJ)/execute
	mkdir -p $(DOBJ)/redirection
	mkdir -p $(DOBJ)/heredoc

make_lib:
	$(MAKE) -C ./libft

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

$(DOBJ)/%.o:src/%.c Makefile
	$(CC) $(CFLAGS) -I $(INCS) -MMD -o $@ -c $<

clean:
	@$(MAKE) -C ./libft fclean
	rm -rf $(DOBJ) 

fclean: clean
	@$(MAKE) -C ./libft fclean
	rm -rf $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re make_lib
