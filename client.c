/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:17:52 by mflury            #+#    #+#             */
/*   Updated: 2023/06/02 20:22:30 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


// classic atoi function,
// chars to int.
int	ft_atoi(const char *str)
{
	int				res;
	int				sign;
	unsigned int	i;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || \
			str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			sign *= -1;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}

// convert a char to his binary representation in byte.
// 1 byte -> 8 bits
// 0x01 = 1 in hex = 00000001 in binary.
// (0x01 << bit) is a left shift of "bit" times,
// so (0x01 << 3) would be 00001000.
// & compare the corresponding bits,
// if both are 1, result 1, else return 0.
// c & (0x01 << bit) bitwise AND operation between c and (0x01 << bit),
// c will vary in 0 and 1, (0x01 << bit) will always be 1,
// so if both = 1 & return 1, if only 1 is 1, it return 0.
// SIGUSR1 used as 1, SIGUSR2 used as 0. 
void	ft_atob(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		bit++;
	}
}

// wanted to make it more user friendly,
// multi words support w/o "",
// space between words,
// \n at the end of the transmition for readability.
void	multi_argv(int pid, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 2;
	while (argv[j])
	{
		while (argv[j][i])
			ft_atob(pid, argv[j][i++]);
		i = 0;
		j++;
		if (argv[j])
			ft_atob(pid, ' ');
		else
			ft_atob(pid, '\n');
	}
}

// because why not a main in 10 lines,
// and also put a \n for readability.
void	single_argv(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
		ft_atob(pid, str[i++]);
	ft_atob(pid, '\n');
}

// client part, transmit a string to a specified pid,
// needs a pid and a string as arguments,
// atoi the pid to have it as an int,
// atob char by char using signals to transmit them.
int	main(int argc, char **argv)
{
	int	pid;

	if (argc < 3)
		error("not enough arguments");
	pid = ft_atoi(argv[1]);
	if (argc > 3)
		multi_argv(pid, argv);
	if (argc == 3)
		single_argv(pid, argv[2]);
	return (0);
}
