/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_fts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:50:12 by pjimenez          #+#    #+#             */
/*   Updated: 2023/11/29 16:53:16 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    reverse_rotate_both(t_list **a, t_list **b, t_list *cheapest)
{
    while (*a != cheapest->target_node && *b != cheapest)
        rrr(a,b);
    //PROBAR CUANDO FUNCIONE SI ESTA LINEA SOBRA O NO
    set_curretn_position(*a);
    set_curretn_position(*b);
    
}
void    rotate_both(t_list **a, t_list **b, t_list *cheapest)
{
    while (*a != cheapest->target_node && *b != cheapest)
        rr(a,b);
    //PROBAR CUANDO FUNCIONE SI ESTA LINEA SOBRA O NO
    set_curretn_position(*a);
    set_curretn_position(*b);
    
}
//funcion para que si no se cumplen las condiciones para acceder a rotates_both
//se hagan los rr y rrr correspondionestes para llevar ambos cheapest al top
void last_rotation(t_list **stack, t_list *cheapest, char name)
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