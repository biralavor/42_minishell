/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:17:29 by tmalheir          #+#    #+#             */
/*   Updated: 2024/06/11 12:21:59 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*The memmove() function copies n bytes from memory area src to memory area
dest. The memory areas may overlap: copying takes place as though the bytes
in src are first copied  into a temporary  array  that does not overlap src
or dest, and the bytes are then copied from the temporary array to dest.
The memmove() function returns a pointer to dest.*/

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*ptr_dst;
	unsigned char	*ptr_src;

	ptr_dst = (unsigned char *)dst;
	ptr_src = (unsigned char *)src;
	if (!dst && !src)
		return (0);
	if (ptr_dst > ptr_src)
	{
		while (n > 0)
		{
			n--;
			ptr_dst[n] = ptr_src[n];
		}
	}
	ft_memcpy(ptr_dst, ptr_src, n);
	return (ptr_dst);
}
