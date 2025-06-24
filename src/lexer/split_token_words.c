/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_token_words.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 15:42:33 by lgracia-          #+#    #+#             */
/*   Updated: 2025/06/12 12:37:55 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	words_is_c(char *s, char c, int *i, int *count)
{
	if (s[*i] && ((c == '|' && s[*i] == c) || (c == ' ' && !blanks(s[*i]))))
	{
		while ((c == '|' && s[*i] == c) || (c == ' ' && !blanks(s[*i])))
			(*i)++;
		*i = is_quote(s, *i);
		if (is_redirection(s, *i, c) && blanks(s[*i]))
			(*count)++;
		if (s[*i] && ((c == '|' && s[*i] != c) || \
		(c == ' ' && blanks(s[*i]))) && s[*i] != 0)
			(*count)++;
		if (!s[*i])
			return (1);
	}
	return (0);
}

short	words(char *s, char c, int *old)
{
	int	count;
	int	i;

	i = 0;
	if (s && s[i] && ((c == '|' && s[i] == c) || (c == ' ' && !blanks(s[i]))))
		count = 0;
	else
		count = 1;
	while (s && s[i])
	{
		i = is_quote(s, i);
		if (is_redirection(s, i, c) && blanks(s[i]))
			count++;
		if (words_is_c(s, c, &i, &count))
			break ;
		i++;
	}
	*old = count;
	return (0);
}
