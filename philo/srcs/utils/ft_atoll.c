/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efmacm23 <efmacm23@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 11:45:03 by efmacm23          #+#    #+#             */
/*   Updated: 2023/12/27 11:55:03 by efmacm23         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long    ft_atoll(const char *str)
{
    long long	num;
    int			sign;

    num = 0;
    sign = 1;
    if (*str == '-')
        sign = -1;
    if (*str == '+' || *str == '-')
        str++;
    while (ft_isdigit(*str))
    {
        if (num > LLONG_MAX / 10 || \
            (num == LLONG_MAX / 10 && *str - '0' > LLONG_MAX % 10))
        {
            if (sign == -1)
                return (LLONG_MIN);
            return (LLONG_MAX);
        }
        num = (num * 10) + (*str - '0');
        str++;
    }
    return (num * sign);
}

// static int	check_sign(const char **from_ascii, int sign);
// static int	check_flows(unsigned long long digit2p, \
// 	unsigned long long digit1, int sign);

// long	ft_atol(const char *from_ascii)
// {
// 	int					sign;
// 	unsigned long long	to_long;
// 	unsigned long long	digit1;

// 	if (from_ascii == NULL)
// 		return (LONG_MAX);
// 	while (ft_isspace(*from_ascii))
// 		from_ascii += 1;
// 	sign = check_sign(&from_ascii, 0);
// 	if (!ft_isdigit(*from_ascii))
// 		return (LONG_MAX);
// 	to_long = 0;
// 	digit1 = 0;
// 	while (*from_ascii)
// 	{
// 		if (!ft_isdigit(*from_ascii))
// 			return (LONG_MAX);
// 		digit1 = *from_ascii - '0';
// 		if (check_flows(to_long, digit1, sign) == ERROR)
// 			return (LONG_MAX);
// 		to_long = (to_long * 10) + digit1;
// 		from_ascii += 1;
// 	}
// 	return ((long)to_long * sign);
// }
// 		// if (check_flows(to_long, digit1, sign) == UNDERFLOW)
// 		// 	return (LONG_MIN);

// static int	ft_isspace(int chr)
// {
// 	return (chr == ' ' || (chr >= '\t' && chr <= '\r'));
// }

// static int	ft_isdigit(int chr)
// {
// 	return (chr >= '0' && chr <= '9');
// }

// static int	check_sign(const char **from_ascii, int sign)
// {
// 	sign = POSITIVE;
// 	if (**from_ascii == '-' || **from_ascii == '+')
// 	{
// 		if (**from_ascii == '-')
// 			sign *= NEGATIVE;
// 		*from_ascii += 1;
// 	}
// 	return (sign);
// }

// static int	check_flows(unsigned long long digit2p, \
// 	unsigned long long digit1, int sign)
// {
// 	if (sign == POSITIVE)
// 	{
// 		if (digit2p > (unsigned long long)(LLONG_MAX / 10))
// 			return (FLOW);
// 		if (digit2p == (unsigned long long)(LLONG_MAX / 10) \
// 			&& digit1 > (unsigned long long)(LLONG_MAX % 10))
// 			return (FLOW);
// 	}
// 	else if (sign == NEGATIVE)
// 	{
// 		if (digit2p > (unsigned long long)(LLONG_MAX / 10))
// 			return (FLOW);
// 		if (digit2p == (unsigned long long)(LLONG_MAX / 10) \
// 			&& digit1 > (unsigned long long)(LLONG_MIN % 10))
// 			return (FLOW);
// 	}
// 	return (OK);
// }
