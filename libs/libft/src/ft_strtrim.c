/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:14:55 by tmalheir          #+#    #+#             */
/*   Updated: 2024/06/11 12:23:02 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*Allocates (with malloc) and returns a copy of 'str' with the characters
specified in 'set' removed from the beginning and the end of the string.*/

static unsigned int	ft_findchr(char c, char const *set)
{
	unsigned int	idx;

	idx = 0;
	while (set[idx])
	{
		if (c == set[idx])
			return (1);
		idx++;
	}
	return (0);
}

char	*ft_strtrim(char const *str, char const *set)
{
	char	*trim_str;
	size_t	start;
	size_t	end;
	size_t	idx;

	if (!str || !set)
		return (NULL);
	start = 0;
	while (str[start] && ft_findchr(str[start], set))
		start++;
	end = ft_strlen(str);
	while (end > start && ft_findchr(str[end - 1], set))
		end--;
	trim_str = malloc(sizeof(char) * (end - start + 1));
	if (!trim_str)
		return (NULL);
	idx = 0;
	while (start < end)
		trim_str[idx++] = str[start++];
	trim_str[idx] = '\0';
	return (trim_str);
}
