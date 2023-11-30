/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_limits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:24:21 by pjimenez          #+#    #+#             */
/*   Updated: 2023/11/20 15:24:50 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list  *find_highest(t_list *stack)
{
    t_list  *tmp;
    t_list  *highest;

    tmp = stack;
    highest = stack;
    while (tmp)
    {
        if (tmp->value > highest->value)
            highest = tmp;
        tmp = tmp->next;
    }
    return (highest);
}

t_list *find_smallest(t_list *stack)
{
    t_list  *tmp;
    t_list  *smallest;

    tmp = stack;
    smallest = stack;
    while (tmp)
    {
        if (tmp->value < smallest->value)
            smallest = tmp;
        tmp=tmp->next;
    }
    return (smallest);
}