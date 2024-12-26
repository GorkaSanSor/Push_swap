/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:51:06 by gsantill          #+#    #+#             */
/*   Updated: 2024/12/19 14:03:40 by gsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include"../srcs/push_swap.h"

int	ft_printf(char const *string, ...);
int	ft_print_nbr(int num, char sign);
int	ft_print_char(char c);
int	ft_print_str(char *str);
int	ft_print_pointer(void *ptr);
int	ft_print_hex(unsigned long long num, char may_min);

#endif