/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:56:01 by tmalheir          #+#    #+#             */
/*   Updated: 2024/06/11 12:22:15 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*Allocates (with malloc(3)) and returns an array of strings obtained by
splitting ’str’ using the character ’c’ as a delimiter. The array must end with
a NULL pointer.*/

static	size_t	ft_substr_count(const char *str, char c)
{
	size_t	idx;
	size_t	count;

	idx = 0;
	count = 0;
	if (str)
	{
		while (str[idx])
		{
			while (str[idx] == c)
				idx++;
			if (str[idx] && str[idx] != c)
				count++;
			while (str[idx] && str[idx] != c)
				idx++;
		}
	}
	return (count);
}

char	**ft_split(char const *str, char c)
{
	char	**array;
	size_t	size;
	size_t	idx_p;
	size_t	idx_sub;

	if (!str)
		return (NULL);
	size = ft_substr_count(str, c);
	array = (char **)ft_calloc((size + 1), sizeof(char *));
	if (!array)
		return (NULL);
	idx_p = 0;
	while (idx_p < size)
	{
		idx_sub = 0;
		while (*str && *str == c)
			str++;
		while (str[idx_sub] && str[idx_sub] != c)
			idx_sub++;
		array[idx_p] = ft_substr(str, 0, idx_sub);
		str += idx_sub;
		idx_p++;
	}
	return (array);
}
