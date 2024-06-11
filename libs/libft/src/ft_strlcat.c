/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 08:21:04 by tmalheir          #+#    #+#             */
/*   Updated: 2024/06/11 12:22:38 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	idx;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	idx = 0;
	if (!size)
		return (len_src);
	while (src[idx] && (len_dst + idx < size - 1))
	{
		dst[len_dst + idx] = src[idx];
		idx++;
	}
	dst[len_dst + idx] = '\0';
	if (len_dst < size)
		return (len_dst + len_src);
	return (size + len_src);
}
