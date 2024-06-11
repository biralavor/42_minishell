/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:02:16 by tmalheir          #+#    #+#             */
/*   Updated: 2024/06/11 12:22:52 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief Compares the first (at most) n bytes of 'str1' and 'str2'.
 * It returns an integer less than, equal to, or greater than zero if str1
 * is found, respectively, to be less than, to match, or be greater than s2.
*/

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t			idx;
	unsigned char	*ptr_str1;
	unsigned char	*ptr_str2;

	idx = 0;
	ptr_str1 = (unsigned char *)str1;
	ptr_str2 = (unsigned char *)str2;
	while ((ptr_str1[idx] || ptr_str2[idx]) && idx < n)
	{
		if (ptr_str1[idx] < ptr_str2[idx])
			return (-1);
		if (ptr_str1[idx] > ptr_str2[idx])
			return (1);
		idx++;
	}
	return (0);
}
