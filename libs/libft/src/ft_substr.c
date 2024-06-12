/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 15:00:40 by tmalheir          #+#    #+#             */
/*   Updated: 2024/06/11 12:23:05 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*Allocates (whith malloc) and returns a substring from the string 'str'.
The substring begins at index 'start' and is of maximum size 'len'.*/

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char			*substr;
	size_t			idx_str;
	size_t			idx_substr;

	if (!str)
		return (NULL);
	if (ft_strlen(str) < start)
		return (ft_strdup(""));
	if (ft_strlen(str + start) < len)
		len = ft_strlen(str + start);
	substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	idx_str = (size_t)start;
	idx_substr = 0;
	while (idx_str < ft_strlen(str) && idx_substr < len)
	{
		substr[idx_substr] = str[idx_str + idx_substr];
		idx_substr++;
	}
	substr[idx_substr] = '\0';
	return (substr);
}
