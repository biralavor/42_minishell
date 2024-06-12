/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:21:45 by tmalheir          #+#    #+#             */
/*   Updated: 2024/06/11 12:22:59 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*The strrchr() function returns a pointer to the last occurrence of the
character c  in  the string s.
The  strchr()  and strrchr() functions return a pointer to the matched
character or NULL if the character is not found.  The terminating null byte
is considered part of the string, so that if c is specified as '\0', these
functions return a pointer to the terminator.*/

char	*ft_strrchr(const char *str, int c)
{
	int		idx;

	idx = 0;
	while (str[idx])
		idx++;
	while (idx >= 0)
	{
		if (str[idx] == (char)c)
			return ((char *)str + idx);
		idx--;
	}
	return (0);
}
