/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:16:10 by tmalheir          #+#    #+#             */
/*   Updated: 2024/06/11 12:21:50 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*The memcmp() function compares the first n bytes (each interpreted as
unsigned char) of the memory areas str1 and str2.
Return value: the  memcmp() function returns an integer less than, equal to,
or greater than zero if the first n bytes of str1 is found, respectively, to
be less than, to match, or be greater than the first n bytes of str2. For a
nonzero return value, the sign is determined by the sign of the difference
between the first pair of bytes (interpreted as  unsigned  char) that differ
in str1 and str2. If n is zero, the return value is zero.*/

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned const char	*ptr1;
	unsigned const char	*ptr2;
	size_t				idx;

	ptr1 = (unsigned const char *)str1;
	ptr2 = (unsigned const char *)str2;
	idx = 0;
	while (idx < n)
	{
		if (ptr1[idx] != ptr2[idx])
		{
			if (ptr1[idx] < ptr2[idx])
				return (-1);
			if (ptr1[idx] > ptr2[idx])
				return (1);
		}
		idx++;
	}
	return (0);
}
