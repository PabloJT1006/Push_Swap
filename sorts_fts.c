/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts_fts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:02:50 by pjimenez          #+#    #+#             */
/*   Updated: 2023/11/06 20:43:32 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//hacer funcion que encuentre el de mayor valor
//si lo es se hace un rotate para ponerlo abajo
//una vez hecho esto hacemo un swap en caso de que haga falta
//hacer comprobacion tambien de que ya esta otrdenado

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
    highest_node = high_node(*a);
    if (highest_node->value == (*a)->value)
        ra(a);
    else if (highest_node->value == (*a)->next->value)
        rra(a);
    if ((*a)->value > (*a)->next->value)
        sa(a);
}

