/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_fts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 02:39:08 by pjimenez          #+#    #+#             */
/*   Updated: 2023/12/15 18:38:00 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_nodes(t_list **top)
{
	t_list	*first;

	if (*top == NULL || (*top)->next == NULL)
		return ;
	first = *top;
	*top = (*top)->next;
	first->prev = *top;
	first->next = (*top)->next;
	(*top)->prev = NULL;
	(*top)->next = first;
}

void	sa(t_list **a)
{
	swap_nodes(a);
	write(1, "sa\n", 3);
}

void	sb(t_list **b)
{
	swap_nodes(b);
	write(1, "sb\n", 3);
}

void	ss(t_list **a, t_list **b)
{
	swap_nodes(a);
	swap_nodes(b);
	write(1, "ss\n", 3);
}
