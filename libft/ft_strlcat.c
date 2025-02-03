/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsantill <gsantill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:46:21 by gsantill          #+#    #+#             */
/*   Updated: 2024/10/11 14:44:50 by gsantill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	src_len;
	size_t	dst_len;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	i = dst_len;
	j = 0;
	if (dstsize > src_len + dst_len)
		dstsize = src_len + dst_len + 1;
	while (i < dstsize - 1 && src[j] != '\0' && dstsize > 0)
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	dst[i] = '\0';
	if (src_len + dst_len > src_len + dstsize)
		return (src_len + dstsize);
	else
		return (src_len + dst_len);
}
