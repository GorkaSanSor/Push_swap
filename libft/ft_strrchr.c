/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:43:04 by gsantill          #+#    #+#             */
/*   Updated: 2024/10/02 11:32:12 by gsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int search_c)
{
	int	i;

	i = ft_strlen(str);
	while (i >= 0)
	{
		if (*(str + i) == (char)search_c)
			return ((char *)str + i);
		i--;
	}
	if ((char)search_c == '\0')
		return ((char *)str + i);
	return (0);
}
