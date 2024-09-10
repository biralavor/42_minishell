/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_strings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 23:23:53 by umeneses          #+#    #+#             */
/*   Updated: 2024/09/10 13:43:35 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_merge_strings(char *str1, char *str2)
{
	char	*merged;

	merged = ft_strjoin(str1, str2);
	if (str1)
		free(str1);
	if (str2)
		free(str2);
	return (merged);
}
