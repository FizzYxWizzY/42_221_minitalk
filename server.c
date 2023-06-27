/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:18:06 by mflury            #+#    #+#             */
/*   Updated: 2023/06/08 19:41:01 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// convert binar signals to char,
// using SIGUSR1 as 1 and SIGUSR2 as 0.
// |= is a bitwise OR operation, combine i
// with the result of the bit shift operation 
// i |= (0x01 << bit) set the bit-th bit of i to 1.
// when the whole byte is done, print his char representation.
void	ft_btoa(int sig)
{
	static int	bit;
	static int	i;

	if (sig == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
}

// server part, listen with signal() in an infinite loop.
// doesnt take arguments.
// get his pid with getpid() and print it so the client can use it.
// wait a SIGUSR1 and SIGUSR2 in an infinte loop.
int	main(int argc, char **argv)
{
	int	pid;

	(void) argv;
	if (argc != 1)
		error("No arguments needed.");
	pid = getpid();
	ft_printf("server's pid: %d\n", pid);
	while (argc == 1)
	{
		signal(SIGUSR1, ft_btoa);
		signal(SIGUSR2, ft_btoa);
		pause();
	}
	return (0);
}
