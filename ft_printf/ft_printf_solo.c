/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_solo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falberti <falberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:23:05 by falberti          #+#    #+#             */
/*   Updated: 2024/04/08 17:07:56 by falberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

void	put_str(char *str, int *count)
{
	int	i = 0;

	if (!str)
		str = "(null)";
	while (str[i])
		*count += write(1, &str[i++], 1);
	return ;
}

void	put_nbr(long long int num, int base, int *count)
{
	char *hexa = "0123456789abcdef";

	if (num < 0)
	{
		*count += write(1, "-", 1);
		num *= -1;
	}
	if (num >= base)
		put_nbr(num / base, base, count);
	*count += write(1, &hexa[num % base], 1);
	return ;
}

static int	checktype(char spe, va_list ap)
{
	int	count = 0;

	if (spe == 's')
		put_str(va_arg(ap, char *), &count);
	else if (spe == 'd')
		put_nbr((long long int)va_arg(ap, int), 10, &count);
	else if (spe == 'x')
		put_nbr((long long int)va_arg(ap, unsigned int), 16, &count);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int	count = 0;
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

int	main(void)
{
	ft_printf("\n");
	ft_printf("Hexadecimal for %d is %x\n", 42, 42);
	ft_printf("Magic %s is %d", "number", -8000000);
	ft_printf("%s\n", "toto");
	return (0);
}
