/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:40:32 by falberti          #+#    #+#             */
/*   Updated: 2024/04/08 16:21:52 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

static void	ft_put_string(char *str, int *count)
{
	int	i = 0;

	if (!str)
		str = "(null)";
	while (str[i])
	{
		*count += write(1, &str[i], 1);
		i++;
	}
}

static void ft_print_num(long long int num, int base, int *count)
{
	char *hexa = "0123456789abcdef";

	if (num < 0)
	{
		num *= -1;
		*count += write(1, "-", 1);
	}
	if (num >= base)
		ft_print_num((num / base), base, count);
	*count += write(1, &hexa[num % base], 1);
	return ;
}

static int checktype(char spe, va_list ap)
{
	int	count;

	count = 0;
	if (spe == 's')
		ft_put_string(va_arg(ap, char *), &count);
	else if (spe == 'd')
		ft_print_num((long long int)va_arg(ap, int), 10, &count);
	else if (spe == 'x')
		ft_print_num((long long int)va_arg(ap, unsigned int), 16, &count);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int count = 0;
	int	i = 0;
	va_list	ap;

	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%' && (format[i + 1] == 's'
				|| format[i + 1] == 'd' || format[i + 1] == 'x'))
		{
				count += checktype(format[++i], ap);
		}
		else
		{
			count += write(1, &format[i], 1);
		}
		i++;
	}
	va_end(ap);
	return (count);
}

// int	main(void)
// {
// 	ft_printf('\n');
// 	return (0);
// }

