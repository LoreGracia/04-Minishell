/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 18:23:32 by lgracia-          #+#    #+#             */
/*   Updated: 2024/09/07 20:03:43 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static int	blanks(const char i)
{
	if (i == ' ' || i == '\r' || i == '\n')
		return (0);
	if (i == '\t' || i == '\v' || i == '\f')
		return (0);
	return (1);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	ptr;
	int	sign;

	i = 0;
	ptr = 0;
	sign = 1;
	while (blanks(nptr[i]) == 0)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] <= '9' && nptr[i] >= '0')
	{
		ptr = nptr[i] - '0' + (10 * ptr);
		i++;
	}
	ptr *= sign;
	return (ptr);
}
/*
#include <stdio.h>

int	main()
{
	printf("%d\n", ft_atoi("\n\t\r-123-45678"));
}*/
