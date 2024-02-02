/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts_fts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:02:50 by pjimenez          #+#    #+#             */
/*   Updated: 2023/12/15 18:27:39 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	extralil_sort(t_list **a)
{
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

void	lil_sort(t_list **a)
{
	t_list	*highest_node;

	highest_node = find_highest(*a);
	if (highest_node->value == (*a)->value)
		ra(a);
	else if (highest_node->value == (*a)->next->value)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

void	sort_five(t_list **a, t_list **b)
{
	while (ft_lstsize(*a) > 3)
	{
		init_nodes(*a, *b);
		last_rotation(a, find_highest(*a), 'a');
		pb(a, b);
	}
}
