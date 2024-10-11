/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:08:26 by tmalheir          #+#    #+#             */
/*   Updated: 2024/10/11 03:30:32 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*The  strdup() function returns a pointer to a new string which is a
duplicate of the strings.  Memory for the new string is obtained with
malloc(3), and can be freed with free(3).
On  success,  the strdup() function returns a pointer to the duplicated string.
It returns NULL if insufficient memory was available, with errno set to
indicate the cause of the  error*/

char	*ft_strdup(const char *str)
{
	size_t	idx;
	char	*dst;
	size_t	len;

	idx = 0;
	if (!str)
		return (NULL);
	len = ft_strlen(str);
	dst = (char *)malloc(sizeof(*dst) * (len + 1));
	if (!dst)
		return (NULL);
	while (idx < len)
	{
		dst[idx] = str[idx];
		idx++;
	}
	dst[idx] = '\0';
	return ((char *)dst);
}
