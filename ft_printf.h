/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:18:45 by iouazzan          #+#    #+#             */
/*   Updated: 2021/12/02 16:18:50 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_putchar(char c, int *rtn);
void	ft_putnbr_hl(unsigned int nb, int *rtn);
void	ft_putnbr_hu(unsigned int nb, int *rtn);
void	ft_putnbr(int nb, int *rtn);
void	ft_putstr(char *str, int *rtn);
void	ft_putnbr_uns(unsigned int nb, int *rtn);
void	ft_pointer(unsigned long p, int *rtn);
int		ft_printf(const char *str, ...);
#endif
