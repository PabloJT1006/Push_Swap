/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_fts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:50:12 by pjimenez          #+#    #+#             */
/*   Updated: 2023/12/15 18:23:57 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_both(t_list **a, t_list **b, t_list *cheapest)
{
	while (*a != cheapest->target_node && *b != cheapest)
		rrr(a, b);
	set_curretn_position(*a);
	set_curretn_position(*b);
}

void	rotate_both(t_list **a, t_list **b, t_list *cheapest)
{
	while (*a != cheapest->target_node && *b != cheapest)
		rr(a, b);
	set_curretn_position(*a);
	set_curretn_position(*b);
}

void	last_rotation(t_list **stack, t_list *cheapest, char name)
{
	while (*stack != cheapest)
	{
		if (name == 'a')
		{
			if (cheapest->bottom_ones)
				rra(stack);
			else
				ra(stack);
		}
		else if (name == 'b')
		{
			if (cheapest->bottom_ones)
				rrb(stack);
			else
				rb(stack);
		}
	}
}
