/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 09:11:02 by tmalheir          #+#    #+#             */
/*   Updated: 2024/06/11 15:02:32 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putstr_fd(char *str, int fd)
{
	int	idx;

	idx = 0;
	if (!str)
		return (write(1, "(null)", 6));
	else
	{
		while (str && str[idx])
		{
			write(1, &str[idx], fd);
			idx++;
		}
	}
	return (idx);
}
