/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:30:12 by mflury            #+#    #+#             */
/*   Updated: 2023/02/22 13:16:40 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);

int	ft_print_c(char c);
int	ft_print_s(char *str);
int	ft_print_di(int n);
int	ft_print_u(unsigned int n);
int	ft_print_p(uintptr_t addr);
int	ft_print_x(unsigned int n, const char type);

#endif