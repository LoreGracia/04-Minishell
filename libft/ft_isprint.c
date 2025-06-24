/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 20:00:08 by lgracia-          #+#    #+#             */
/*   Updated: 2024/06/26 14:56:08 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_isprint(int c)
{
	if (c > 31 && c < 127)
		return (16384);
	else
		return (0);
}
/*
#include <stdio.h>

int	main()
{
	printf("%d\n", ft_isprint('i'));
	printf("%d\n", ft_isprint(127));
	printf("%d\n", ft_isprint(11));
}*/
