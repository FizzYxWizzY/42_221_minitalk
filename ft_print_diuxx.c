/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_diuxx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:23:26 by mflury            #+#    #+#             */
/*   Updated: 2022/12/19 16:23:26 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// print an int, aka ft_putnbr.

static int	ft_nbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		count += ft_print_s("-2147483648");
	else if (n < 0)
	{
		count += ft_print_c('-');
		n = n * -1;
		count += ft_nbr(n);
	}
	else
	{
		if (n >= 10)
		{
			count += ft_nbr(n / 10);
			count += ft_nbr(n % 10);
		}
		else
			count += ft_print_c(n + 48);
	}
	return (count);
}

// print an int in base 10. 

int	ft_print_di(int n)
{
	int	count;

	count = 0;
	count += ft_nbr(n);
	return (count);
}

// print an unsigned int in base 10.

int	ft_print_u(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
	{
		count += ft_nbr(n / 10);
		count += ft_nbr(n % 10);
	}
	else
			count += ft_print_c(n + 48);
	return (count);
}

// print an hex value using the chosen hexset.

static int	ft_hex(unsigned int n, char *hexset)
{
	int	count;

	count = 0;
	if (n >= 16)
	{
		count += ft_hex(n / 16, hexset);
		count += ft_hex(n % 16, hexset);
	}
	else
		count += ft_print_c(hexset[n]);
	return (count);
}

// choose the hexset for X/x to make upper or lower letters hex.

int	ft_print_x(unsigned int n, const char type)
{
	char	*hexset;

	if (type == 'x')
		hexset = "0123456789abcdef";
	if (type == 'X')
		hexset = "0123456789ABCDEF";
	return (ft_hex(n, hexset));
}
