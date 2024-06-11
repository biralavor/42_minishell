/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_low_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 09:11:02 by tmalheir          #+#    #+#             */
/*   Updated: 2024/06/11 15:02:16 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_puthexa_low_fd(unsigned long long nbr, int fd)
{
	int		count;
	char	*hexa_low;

	count = 0;
	hexa_low = "0123456789abcdef";
	if (nbr < 16)
		count += write(1, &hexa_low[nbr], 1);
	else
	{
		count += ft_puthexa_low_fd((nbr / 16), fd);
		count += ft_puthexa_low_fd((nbr % 16), fd);
	}
	return (count);
}
