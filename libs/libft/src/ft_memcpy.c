/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:03:20 by tmalheir          #+#    #+#             */
/*   Updated: 2024/06/11 12:21:54 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*The  memcpy() function copies n bytes from memory area src to memory area
dest. The memory areas must not overlap. The memcpy() function returns a
pointer to dest.*/

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;
	size_t			idx;

	if (!src && !dest)
	{
		return (NULL);
	}
	ptr_dest = (unsigned char *)dest;
	ptr_src = (unsigned char *)src;
	idx = 0;
	while (idx < n)
	{
		ptr_dest[idx] = ptr_src[idx];
		idx++;
	}
	return (ptr_dest);
}
