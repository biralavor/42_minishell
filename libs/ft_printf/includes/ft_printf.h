/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 09:02:16 by tmalheir          #+#    #+#             */
/*   Updated: 2024/04/11 15:01:11 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int				ft_printf(const char *arg, ...);
int				ft_putchar_fd(char c, int fd);
int				ft_putnbr_fd(int nbr, int fd);
unsigned int	ft_putnbr_unsg_fd(unsigned int nbr, int fd);
int				ft_putstr_fd(char *str, int fd);
int				ft_puthexa_low_fd(unsigned long long nbr, int fd);
int				ft_puthexa_up_fd(unsigned int nbr, int fd);
int				ft_putptr_fd(unsigned long long ptr, int fd);

#endif
