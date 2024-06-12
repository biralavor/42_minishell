/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 09:11:02 by tmalheir          #+#    #+#             */
/*   Updated: 2024/06/12 14:16:04 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_putnbr_fd(int nbr, int fd)
{
	char	n_char;
	long	n_long;
	int		count;

	n_long = nbr;
	count = 0;
	if (n_long < 0)
	{
		count += write(1, "-", 1);
		n_long = -n_long;
	}
	if (n_long >= 0 && n_long <= 9)
	{
		n_char = n_long + '0';
		count += write(1, &n_char, 1);
	}
	else
	{
		count += ft_putnbr_fd((n_long / 10), fd);
		count += ft_putnbr_fd((n_long % 10), fd);
	}
	return (count);
}
