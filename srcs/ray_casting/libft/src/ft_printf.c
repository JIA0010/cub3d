/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjia <cjia@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:03:15 by cjia              #+#    #+#             */
/*   Updated: 2023/08/28 14:24:27 by cjia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int	check_args(const char *input, va_list arg)
{
	size_t	i;

	i = 0;
	if (*input == 'c')
		i += printf_c(va_arg(arg, int));
	else if (*input == 's')
		i += printf_s(va_arg(arg, char *));
	else if (*input == 'p')
		i += printf_p(va_arg(arg, uintptr_t));
	else if (*input == 'd' || *input == 'i')
		i += printf_i(va_arg(arg, int));
	else if (*input == 'u')
		i += printf_u(va_arg(arg, unsigned int));
	else if (*input == 'x')
		i += lowercase_hex(va_arg(arg, unsigned int));
	else if (*input == 'X')
		i += uppercase_hex(va_arg(arg, unsigned int));
	return (i);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	size_t	i;

	i = 0;
	va_start(args, input);
	while (*input)
	{
		if (*input == '%')
		{
			input++;
			if (ft_strchr("cspdiuxX", *input))
				i += check_args(input, args);
			else if (*input == '%')
				i += printf_c('%');
		}
		else
			i += printf_c(*input);
		input++;
	}
	va_end(args);
	return (i);
}

// int	main(void)
// {
// 	int	result;

// 	result = ft_printf("Hello, %s! The answer is %d.\n", "John", -2147483648);
// 	printf("Hello, %s! The answer is %ld.\n", "John", -2147483648);
// 	return (0);
// }

// int	main(void)
// {
// 	printf("%%\n");
// 	ft_printf("%%\n");
// 	return (0);
// }
