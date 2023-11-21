/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_nodes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:31:53 by pjimenez          #+#    #+#             */
/*   Updated: 2023/11/21 13:55:25 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


//FUNCION INIT NODES LA CUAL SE UTILIZARA PARA CADA VEZ QUE HAGAMOS UN
//MOVIMIENTO SE ACTUALICE LA INFO DEL NODO
//COSAS A UPDATEAR
    //current position de a y b (done)
    //target node (done)
    //set_prices (learning)
    //set_cheapest(b)(ola)

void    init_nodes(t_list *a, t_list *b)
{
    set_curretn_position(a);
    set_curretn_position(b);
    set_targets(a,b);
    //set_prices
    //set_cheapest
}

//moirar porque conio esta el de debajo de la media como true
void    set_curretn_position(t_list *stack)
{
    int i;
    int media;
    
    i = 0;
    if (stack == NULL)
        return ;
    media = ft_lstsize(stack) / 2;
    while (stack)
    {
        stack->position = i;
        if (i <= media)
            stack->top_ones = true;
        else
            stack->top_ones = false;
        stack = stack->next;
        i++;
    }
}




//best_match_index igualarlo al long_max, si el current_a es menor a esto pero mayor al de be, best_match es igual a este numero
void    set_targets(t_list *a, t_list *b)
{
    t_list  *target_node;
    t_list  *aux_a;
    long     best_option;
    
    while(b)
    {
        aux_a = a;
        best_option = find_highest(a)->value; //esto podira ser tambine el highest de a (creo)
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
        if (best_option == find_highest(a)->value)
        {
            b->target_node=find_smallest(a);
        }
        else
            b->target_node = target_node;
        b = b->next;
    }
}

int main ()
{
    t_list *a;
    t_list *b;
    
    a = ft_inistack(10);
    ft_lstadd_back(&a,ft_inistack(2));
    ft_lstadd_back(&a,ft_inistack(-3));
    
    b = ft_inistack(-4);
    ft_lstadd_back(&b,ft_inistack(1));
    ft_lstadd_back(&b,ft_inistack(11));
    ft_lstadd_back(&b,ft_inistack(-3));

    set_targets(a,b);

    while (b)
    {
        printf("value: %d \ttarget_node: %d\n",b->value,b->target_node->value);
        b = b ->next;
    }

}