/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 07:34:57 by tmalheir          #+#    #+#             */
/*   Updated: 2024/06/11 12:21:42 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*Allocate (with malloc(3)) and returns a “fresh” string ending with ’\0’
representing the integer n given as argument. Negative numbers must be
supported. If the allocation fails, the function returns NULL.
Return value: the string representing the integer passed as argument.*/

static size_t	ft_nbr_digits(int nbr)
{
	size_t	digit;

	digit = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		digit++;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		digit++;
	}
	return (digit);
}

char	*ft_itoa(int nbr)
{
	char	*str;
	size_t	n_len;

	if (nbr == 0)
		return (str = ft_strdup("0"));
	if (nbr == -2147483648)
		return (str = ft_strdup("-2147483648"));
	n_len = ft_nbr_digits(nbr);
	str = malloc((n_len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[n_len] = '\0';
	if (nbr < 0)
	{
		nbr *= -1;
		str[0] = '-';
	}
	while (nbr > 0)
	{
		str[--n_len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (str);
}
