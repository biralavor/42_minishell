/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 09:11:02 by tmalheir          #+#    #+#             */
/*   Updated: 2024/09/03 00:17:17 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_putstr_fd(char *str, int fd)
{
	int	idx;

	idx = 0;
	if (!str)
		return (write(fd, "(null)", 6));
	else
	{
		while (str && str[idx])
		{
			write(fd, &str[idx], sizeof(char));
			idx++;
		}
	}
	return (idx);
}
