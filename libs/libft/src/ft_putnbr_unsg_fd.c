/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsg_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 09:11:02 by tmalheir          #+#    #+#             */
/*   Updated: 2024/06/12 14:16:07 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

unsigned int	ft_putnbr_unsg_fd(unsigned int nbr, int fd)
{
	char	n_char;
	long	n_long;
	int		count;

	n_long = nbr;
	count = 0;
	if (n_long >= 0 && n_long <= 9)
	{
		n_char = n_long + '0';
		count += write(1, &n_char, 1);
	}
	else
	{
		count += ft_putnbr_unsg_fd((n_long / 10), fd);
		count += ft_putnbr_unsg_fd((n_long % 10), fd);
	}
	return (count);
}
