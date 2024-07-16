/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:02:16 by tmalheir          #+#    #+#             */
/*   Updated: 2024/07/16 16:45:35 by umeneses         ###   ########.fr       */
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
	if (n == 0)
		return (0);
	while (n > 0)
	{
		if (*str1 != *str2)
			return (*(unsigned char *)str1 - *(unsigned char *)str2);
		str1++;
		str2++;
		n--;
		if ((*str1 || *str2) == '\0')
			break ;
	}
	return (0);
}
