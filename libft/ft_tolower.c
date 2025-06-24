/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:28:42 by lgracia-          #+#    #+#             */
/*   Updated: 2024/07/10 10:03:21 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_tolower(int c)
{
	if (c > 64 && c < 91)
		c += 32;
	return (c);
}
/*
#include <stdio.h>

int	main()
{
	printf("%c", ft_tolower('A'));
	printf("%c", ft_tolower('a'));
	printf("%c", ft_tolower('z'));
	printf("%c", ft_tolower('Z'));
}*/
