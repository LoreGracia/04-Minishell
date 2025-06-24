/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 12:06:28 by lgracia-          #+#    #+#             */
/*   Updated: 2024/07/13 15:30:13 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, s + i);
		i++;
	}
}
/*

#include <stdio.h>

void	function(unsigned int i, char *s)
{
	printf("%c\n", ft_tolower(s[i]));
}

int	main(void)
{
	char 	*str = "HELLO THERE";
	int		i = 0;

	ft_striteri(str, function);
}*/
