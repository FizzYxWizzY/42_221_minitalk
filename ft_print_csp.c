/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_csp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 02:13:48 by mflury            #+#    #+#             */
/*   Updated: 2022/12/17 02:13:48 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// print a character, aka ft_putchar.

int	ft_print_c(char c)
{
	write(1, &c, 1);
	return (1);
}

// print a string, aka ft_putstr.

int	ft_print_s(char *str)
{
	int		i;

	i = 0;
	if (!str)
	{
		ft_print_s("(null)");
		return (6);
	}
	while (str[i])
	{
		ft_print_c(str[i++]);
	}
	return (i);
}

// pointer address in hex (base 16).

static int	ft_ptr(uintptr_t n)
{
	char	*hexset;
	int		count;

	hexset = "0123456789abcdef";
	count = 0;
	if (n >= 16)
	{
		count += ft_ptr(n / 16);
		count += ft_ptr(n % 16);
	}
	else
		count += ft_print_c(hexset[n]);
	return (count);
}

// print "0x" meaning its a memory address.
// then print the hex value.
//
// uintptr_t is an unsigned integer memsize-type that can 
// safely store a pointer regardless of the platform capacity.
// The type uintptr_t is similar to the types size_t and UINT_PTR.
// The size of the type depends upon the data model.

int	ft_print_p(uintptr_t addr)
{
	int	count;

	count = 0;
	count += ft_print_s("0x");
	count += ft_ptr(addr);
	return (count);
}
