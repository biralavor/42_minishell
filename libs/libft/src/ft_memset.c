/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:09:39 by tmalheir          #+#    #+#             */
/*   Updated: 2024/06/11 12:22:03 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*The  memset()  function fills the first n bytes of the memory area pointed
to by str with the constant byte c.The memset() function returns a pointer to
the memory area str.*/

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			idx;

	ptr = (unsigned char *)str;
	idx = 0;
	while (idx < n)
	{
		ptr[idx] = (unsigned char)c;
		idx++;
	}
	return (ptr);
}
