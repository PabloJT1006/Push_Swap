/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_fts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:55:48 by pjimenez          #+#    #+#             */
/*   Updated: 2023/11/29 17:00:39 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void set_3nodes(t_list **a, t_list **b)
{
    int len;

    len = ft_lstsize(*a);
    while(len > 3)
    {
        pb(a,b);
        len--;
    }
}

void move_nodes(t_list **a, t_list **b)
{
    t_list *cheapest;
    
    cheapest = return_cheapest(*b);
    
    if (cheapest->bottom_ones && cheapest->target_node->bottom_ones)
        reverse_rotate_both(a,b,cheapest);
    else if (!(cheapest->bottom_ones) && !(cheapest->target_node->bottom_ones))
        rotate_both(a,b,cheapest);
    last_rotation(a,cheapest->target_node,'a');
    last_rotation(b,cheapest,'b');
    pa(b,a);
}


void    push_swap(t_list **a, t_list **b)
{
    t_list *smallest;
    int len_a;

    len_a = ft_lstsize(*a);
    if (len_a >= 2)
    {
        if (len_a == 2)
            extralil_sort(a);
        else if (len_a == 3)
            lil_sort(a);
        else if (len_a > 3)
        {
            set_3nodes(a,b);
            lil_sort(a);
            init_nodes(*a,*b);
            while (*b)
            {
                init_nodes(*a,*b);
                move_nodes(a,b);
            }
            // una vez estemos aqui podriamos decir que ya esta ordenado, pero puede que
            // el smallest no este en el top
            set_curretn_position(*a);
            smallest = find_smallest(*a);
            if (smallest->bottom_ones)
                while (*a != smallest)
                    rra(a);
            else
                while (*a != smallest)
                    ra(a);
    }
    else
        return ;
    }
}


