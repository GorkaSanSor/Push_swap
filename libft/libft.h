/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:35:03 by gsantill          #+#    #+#             */
/*   Updated: 2024/11/12 11:41:10 by gsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
#include"../srcs/push_swap.h"

int		ft_isalpha(int c);
long	ft_long_atoi(const char *str);
void	ft_putstr(char *s);
char	*ft_strdup(char *src);
char	*ft_strjoin_endspace(char *s1, char const *s2);
size_t	ft_strlcpy(char *dest, const char *src, size_t destsize);
int		ft_strlen(const char *str);

#endif