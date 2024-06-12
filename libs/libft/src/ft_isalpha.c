/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:10:41 by tmalheir          #+#    #+#             */
/*   Updated: 2024/06/11 12:21:19 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*Checks  for  an  alphabetic character. The values returned are nonzero if the
character c falls into the tested class, and zero if not.*/

int	ft_isalpha(int c)
{
	if ((c >= 'A' & c <= 'Z') || (c >= 'a' & c <= 'z'))
		return (1);
	else
		return (0);
}
