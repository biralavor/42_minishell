/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:44:04 by tmalheir          #+#    #+#             */
/*   Updated: 2024/06/11 12:22:49 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	unsigned int	idx;
	char			*new_str;

	if (!str)
		return (NULL);
	new_str = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!new_str)
		return (NULL);
	idx = 0;
	while (str[idx])
	{
		new_str[idx] = f(idx, str[idx]);
		idx++;
	}
	new_str[idx] = '\0';
	return (new_str);
}
