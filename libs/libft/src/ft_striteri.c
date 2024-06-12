/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:24:10 by tmalheir          #+#    #+#             */
/*   Updated: 2024/06/11 12:22:28 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/* Applies the function ’f’ on each character of the string passed as argument,
passing its index as first argument. Each character is passed by address to ’f’
to be modified if necessary.*/

void	ft_striteri(char *str, void (*f)(unsigned int, char*))
{
	unsigned int	idx;

	idx = 0;
	if (str || f)
	{
		while (str[idx])
		{
			f(idx, &str[idx]);
			idx++;
		}
	}
}
