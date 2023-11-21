/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_targets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:31:53 by pjimenez          #+#    #+#             */
/*   Updated: 2023/11/20 18:32:33 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//best_match_index igualarlo al long_max, si el current_a es menor a esto pero mayor al de be, best_match es igual a este numero
void    set_targets(t_list *a, t_list *b)
{
    t_list  *target_node;
    t_list  *aux_a;
    t_list  *best_option;
    
    while(b)
    {
        aux_a = a;
        best_option = __LONG_MAX__; //esto podira ser tambine el highest de a (creo)
        while(aux_a)
        {
            //si no se cumple esta condicion quieres decir que el nodo actual de b,
            //es de mayor valor que que cualquiera de los de a, por lo tanto target_node = samallest(a)
            if (aux_a->value > b->value &&
                aux_a->value < best_option)
            {
                best_option = aux_a->value;
                target_node = aux_a;
            }
            aux_a = aux_a->next;
        }
        if (best_option == __LONG_MAX__)
        {
            b->target_node=find_smallest(a);
        }
        else
            b->target_node = target_node;
        b = b->next;
    }
}