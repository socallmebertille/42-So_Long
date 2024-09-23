/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 19:12:31 by saberton          #+#    #+#             */
/*   Updated: 2024/06/06 14:33:55 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

# define U_MAX 4294967295
# define DEC_BASE "0123456789"
# define HEX_BASE_MIN "0123456789abcdef"
# define HEX_BASE_MAJ "0123456789ABCDEF"

int		ft_printf(const char *format, ...);
int		ft_check_space(const char *format);
int		ft_check_var(char format, va_list args);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_len_nb(size_t nb, size_t len);
int		ft_print_ptr(char *base, void *ptr, size_t len);
void	ft_putptr(char *base, size_t p, size_t len);
int		ft_putnbr(int nbr);
int		ft_putnbr_base(char *base, int nbr, int len);

#endif
