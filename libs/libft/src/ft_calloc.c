/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:27:27 by tmalheir          #+#    #+#             */
/*   Updated: 2024/06/11 12:21:11 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*The calloc() function allocates memory for an array of nmemb elements of size
bytes each and returns a pointer  to  the  allocated  memory. The  memory is
set to zero.  If nmemb or size is 0, then calloc() returns either NULL, or a
unique pointer value that can later be successfully passed to free(). If the
multiplication of nmemb and size would result in integer overflow, then
calloc() returns an error.
The calloc() function returns a pointer to the allocated memory, which is
suitably aligned for any built-in type. On  error, this  function returns NULL.
NULL may also be returned by a successful call to calloc() with nmemb or size
equal to zero.*/

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	size_t	total_size;

	total_size = nmemb * size;
	if (total_size != 0 && (total_size / nmemb) != size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, (size * nmemb));
	return (ptr);
}
