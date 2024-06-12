/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:36:12 by tmalheir          #+#    #+#             */
/*   Updated: 2024/06/11 12:21:29 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*Checks  for  a digit (0 trough 9). The values returned are nonzero if the
character c falls into the tested class, and zero if not.*/

int	ft_isdigit(int c)
{
	if (c >= '0' & c <= '9')
		return (1);
	else
		return (0);
}
