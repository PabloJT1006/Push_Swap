/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:59:01 by pjimenez          #+#    #+#             */
/*   Updated: 2023/12/15 15:39:59 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_atoi_errors(long int result)
{
	if (result > INT_MAX || result < INT_MIN)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

long int	ft_atoi(const char *nptr)
{
	long int	result;
	int			i;
	int			negative;

	result = 0;
	i = 0;
	negative = 0;
	while (nptr[i] == ' ' || nptr[i] == '\f' || nptr[i] == '\n'
		|| nptr[i] == '\r' || nptr[i] == '\t' || nptr[i] == '\v')
		i++;
	if (nptr[i] == '-')
		negative = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result *= 10;
		result += nptr[i] - '0';
		i++;
	}
	if (negative)
		result = result * -1;
	ft_atoi_errors(result);
	return (result);
}
