/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 09:11:02 by tmalheir          #+#    #+#             */
/*   Updated: 2024/06/11 12:22:11 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_putptr_fd(unsigned long long ptr, int fd)
{
	int		count;
	char	*hexa_low;

	count = 0;
	hexa_low = "0123456789abcdef";
	if (!ptr)
	{
		count += write(1, "(nil)", 5);
		return (count);
	}
	count += write(1, "0x", 2);
	if (ptr < 16)
		count += write(1, &hexa_low[ptr], 1);
	else
	{
		count += ft_puthexa_low_fd((ptr / 16), fd);
		count += ft_puthexa_low_fd((ptr % 16), fd);
	}
	return (count);
}
