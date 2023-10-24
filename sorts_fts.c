/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts_fts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:02:50 by pjimenez          #+#    #+#             */
/*   Updated: 2023/10/24 14:54:39 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//hacer funcion que encuentre el de mayor valor
//si lo es se hace un rotate para ponerlo abajo
//una vez hecho esto hacemo un swap en caso de que haga falta


t_list  *high_node(t_list *stack)
{
    t_list  *tmp;
    t_list  *tmp2;
    t_list  *highest;

    tmp = stack;
    
    while (tmp)
    {
        tmp2 = tmp->next;
        while (tmp2)
        {
            if (tmp->value > tmp2->value)
                highest = tmp;
            else
                highest = tmp2;
            tmp2=tmp2->next;
        }
        tmp=tmp->next;
    }
    return (highest);
}


void    lil_sort(t_list **a)
{
    t_list  *highest_node;
    
    highest_node = high_node(a);

    if (highest_node== (*a))
        ra(&a);
    else if (highest_node->value == ft_lstlast(a)->value)
    {
        
    }
    
    if ((*a)->value > (*a)->next->value)
        sa(&a);
    
    
    
    
}