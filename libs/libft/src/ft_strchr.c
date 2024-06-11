/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:31:13 by tmalheir          #+#    #+#             */
/*   Updated: 2024/06/11 12:22:21 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*The strrchr() function returns a pointer to the first occurrence of the
character c  in  the string str.
The  strchr()  and strrchr() functions return a pointer to the matched
character or NULL if the character is not found.  The terminating null byte
is considered part of the string, so that if c is specified as '\0', these
functions return a pointer to the terminator.*/

char	*ft_strchr(const char *str, int c)
{
	char	find_c;

	find_c = c;
	while (*str != find_c)
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return ((char *)str);
}
