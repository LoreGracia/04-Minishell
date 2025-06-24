/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 15:48:06 by lgracia-          #+#    #+#             */
/*   Updated: 2024/07/14 18:17:31 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb *= -1;
	}
	if (nb >= 10)
		ft_putnbr_fd(nb / 10, fd);
	ft_putchar_fd(nb % 10 + '0', fd);
}
/*
int	main(void)
{
	ft_putnbr_fd(-2147483648, 1);
	ft_putnbr_fd(0, 1);
	ft_putnbr_fd(-10000043, 1);
	ft_putnbr_fd(1234567, 1);
	ft_putnbr_fd(10000043, 1);
	ft_putnbr_fd(-987441, 2);
}*/
