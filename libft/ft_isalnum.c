/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:32:54 by lgracia-          #+#    #+#             */
/*   Updated: 2024/07/06 18:40:21 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_isalnum(int c)
{
	if (c > 64 && c < 91)
		return (8);
	else if (c > 96 && c < 123)
		return (8);
	else if (c > 47 && c < 58)
		return (8);
	else
		return (0);
}
/*
#include <stdio.h>

int	main()
{
	printf("%d\n", ft_isalnum('4'));
	printf("%d\n", ft_isalnum('*'));
	printf("%d\n", ft_isalnum('i'));
	printf("%d\n", ft_isalnum(1));
	printf("%d\n", ft_isalnum('a'));
	printf("%d\n", ft_isalnum('z'));
	printf("%d\n", ft_isalnum('A'));
	printf("%d\n", ft_isalnum('Z'));
	printf("%d\n", ft_isalnum('0'));
	printf("%d\n", ft_isalnum('9'));
}*/
