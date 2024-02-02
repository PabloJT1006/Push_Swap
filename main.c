/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 03:34:57 by pjimenez          #+#    #+#             */
/*   Updated: 2024/01/09 15:44:46 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int		cont;
	t_list	*a;
	t_list	*b;

	cont = 1;
	a = NULL;
	b = NULL;
	while (cont < ac)
	{
		generate_stack(av[cont], &a);
		cont++;
	}
	if (duplicate(a))
		errors(&a, &b);
	if (sorted(a))
	{
		free_stack(&a);
		return (0);
	}
	push_swap(&a, &b);
	free_stack(&a);
}
