/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 09:16:36 by lgracia-          #+#    #+#             */
/*   Updated: 2024/07/27 11:45:03 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static char	*nworthit(int n)
{
	if (n <= -2147483648)
		return (ft_strdup("-2147483648"));
	else if (n >= 2147483647)
		return (ft_strdup("2147483647"));
	else if (n == 0)
		return (ft_strdup("0"));
	return (0);
}

static int	nlen(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	if (n <= -2147483648 || n >= 2147483647 || n == 0)
		return (nworthit(n));
	len = nlen(n);
	str = malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	str[len] = '\0';
	while (n)
	{
		len--;
		str[len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
/*
#include <stdio.h>

int	main(void)
{
	int	a = -2147483647 -1;
	char	*str;
	int		i = 0;

	str = ft_itoa(a);
	printf("%s\n", str);
	while (str[i] != 0)
	{
		printf("array[%c]\n", str[i]);
		i++;
	}
}*/
