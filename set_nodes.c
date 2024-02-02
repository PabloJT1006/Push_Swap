/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_nodes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:25:37 by pjimenez          #+#    #+#             */
/*   Updated: 2023/12/15 18:32:48 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_curretn_position(t_list *stack)
{
	int	i;
	int	media;

	i = 0;
	if (stack == NULL)
		return ;
	media = ft_lstsize(stack) / 2;
	while (stack)
	{
		stack->position = i;
		if (i <= media)
			stack->bottom_ones = false;
		else
			stack->bottom_ones = true;
		stack = stack->next;
		i++;
	}
}

void	set_targets(t_list *a, t_list *b)
{
	t_list	*target_node;
	t_list	*aux_a;
	long	best_option;

	while (b)
	{
		aux_a = a;
		best_option = LONG_MAX;
		while (aux_a)
		{
			if (aux_a->value > b->value && aux_a->value < best_option)
			{
				best_option = aux_a->value;
				target_node = aux_a;
			}
			aux_a = aux_a->next;
		}
		if (best_option == LONG_MAX)
			b->target_node = find_smallest(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	set_costs(t_list *a, t_list *b)
{
	int	len_b;
	int	len_a;

	len_a = ft_lstsize(a);
	len_b = ft_lstsize(b);
	while (b)
	{
		b->push_price = b->position;
		if (b->bottom_ones)
			b->push_price = len_b - (b->position);
		if (b->target_node->bottom_ones)
			b->push_price += len_a - (b->target_node->position);
		else
			b->push_price += (b->target_node->position);
		b = b->next;
	}
}

void	set_chapest(t_list *stack)
{
	t_list	*cheapest;
	long	best_match;

	cheapest = stack;
	if (stack == NULL)
		return ;
	best_match = LONG_MAX;
	while (stack)
	{
		if (stack->push_price < best_match)
		{
			best_match = stack->push_price;
			cheapest = stack;
		}
		stack = stack->next;
	}
	cheapest->cheapest = true;
}

void	init_nodes(t_list *a, t_list *b)
{
	set_curretn_position(a);
	set_curretn_position(b);
	set_targets(a, b);
	set_costs(a, b);
	set_chapest(b);
}
