/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_fts.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:16:23 by pjimenez          #+#    #+#             */
/*   Updated: 2023/12/15 18:32:03 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_list **stack)
{
	t_list	*first_node;
	t_list	*last_node;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first_node = *stack;
	last_node = ft_lstlast(*stack);
	while (*stack)
	{
		if ((*stack)->next->next == NULL)
		{
			(*stack)->next = NULL;
			break ;
		}
		*stack = (*stack)->next;
	}
	last_node->next = first_node;
	last_node->prev = NULL;
	*stack = last_node;
}

void	rra(t_list **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_list **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **a, t_list **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}
