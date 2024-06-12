/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:58:37 by tmalheir          #+#    #+#             */
/*   Updated: 2024/06/11 12:22:34 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*Allocates (with malloc(3)) and returns a new string, which is the result of
the concatenation of ’str1’ and ’str2’.*/

char	*ft_strjoin(char const *str1, char const *str2)
{
	char			*str3;
	size_t			idx;
	size_t			len_str1;
	size_t			len_str2;

	len_str1 = ft_strlen(str1);
	len_str2 = ft_strlen(str2);
	str3 = (char *)malloc(len_str1 + len_str2 + 1);
	if (!str3)
		return (NULL);
	idx = 0;
	while (str1[idx])
	{
		str3[idx] = str1[idx];
		idx++;
	}
	while (str2[idx - len_str1])
	{
		str3[idx] = str2[idx - len_str1];
		idx++;
	}
	str3[idx] = '\0';
	return (str3);
}
