/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lil_sorts_fts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:02:50 by pjimenez          #+#    #+#             */
/*   Updated: 2023/11/23 17:19:23 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//hacer funcion que encuentre el de mayor valor
//si lo es se hace un rotate para ponerlo abajo
//una vez hecho esto hacemo un swap en caso de que haga falta
//hacer comprobacion tambien de que ya esta otrdenado

int sorted (t_list *a)
{
    t_list *tmp;
    t_list *tmp2;
    int check;

    check = 1;
    tmp = a;
    while (tmp)
    {
        tmp2 = tmp->next;
        while (tmp2)
        {
            if (tmp->value > tmp2->value)
                check = 0;    
            tmp2 = tmp2->next;
        }
        tmp = tmp->next;
        
    }    
    return (check);
}


void    extralil_sort(t_list **a)
{
    if ((*a)->value > (*a)->next->value)
        sa(a);
}

void    lil_sort(t_list **a)
{
    t_list  *highest_node;
    highest_node = find_highest(*a);
    if (highest_node->value == (*a)->value)
        ra(a);
    else if (highest_node->value == (*a)->next->value)
        rra(a);
    if ((*a)->value > (*a)->next->value)
        sa(a);
}

void    sort_five(t_list *a, t_list*b)
{
    set_3nodes(&a,&b);
    lil_sort(&a);
}