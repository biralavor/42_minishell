/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:07:23 by tmalheir          #+#    #+#             */
/*   Updated: 2024/06/11 15:02:02 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	check_format(char type, va_list ap);

int	ft_printf(const char *arg, ...)
{
	va_list	ap;
	int		count;
	int		idx;

	if (!arg)
		return (-1);
	va_start(ap, arg);
	count = 0;
	idx = 0;
	while (arg[idx])
	{
		if (arg[idx] == '%')
		{
			count += check_format((arg[idx + 1]), ap);
			++idx;
		}
		else
			count += write(1, &arg[idx], 1);
		++idx;
	}
	va_end (ap);
	return (count);
}

int	check_format(char type, va_list ap)
{
	int	count;

	count = 0;
	if (type == 'c')
		count += ft_putchar_fd(va_arg(ap, int), 1);
	if (type == 's')
		count += ft_putstr_fd(va_arg(ap, char *), 1);
	if (type == 'p')
		count += ft_putptr_fd(va_arg(ap, unsigned long long), 1);
	if (type == 'd' || type == 'i')
		count += ft_putnbr_fd(va_arg(ap, int), 1);
	if (type == 'u')
		count += ft_putnbr_unsg_fd(va_arg(ap, unsigned int), 1);
	if (type == 'x')
		count += ft_puthexa_low_fd(va_arg(ap, unsigned int), 1);
	if (type == 'X')
		count += ft_puthexa_up_fd(va_arg(ap, int), 1);
	if (type == '%')
		count += ft_putchar_fd('%', 1);
	return (count);
}
