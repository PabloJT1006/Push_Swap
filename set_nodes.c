/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_nodes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:25:37 by pjimenez          #+#    #+#             */
/*   Updated: 2023/11/23 16:41:48 by pjimenez         ###   ########.fr       */
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



//moirar porque conio esta el de debajo de la media como true
void    set_curretn_position(t_list *stack)
{
    int i;
    int media;
    
    i = 0;
    if (stack == NULL)
        return ;
    media = ft_lstsize(stack) / 2;
    printf("MEDIA: %d\n",media);
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




//best_match_index igualarlo al long_max, si el current_a es menor a esto pero mayor al de be, best_match es igual a este numero
void    set_targets(t_list *a, t_list *b)
{
    t_list  *target_node;
    t_list  *aux_a;
    long     best_option;
    
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



void    set_costs(t_list *a, t_list *b)
{
    int len_b;
    int len_a;

    len_a = ft_lstsize(a);
    len_b = ft_lstsize(b);
    
    while (b)
    {
        b->push_price = b->position;
        
        if (b->bottom_ones)
            b->push_price = len_b - (b->position);
        if (b->target_node->bottom_ones)
            b->push_price += len_a -( b->target_node->position);
        else
            b->push_price += (b->target_node->position);
        b = b->next;
    }
    
}

void    set_chapest(t_list *stack)
{
    t_list *cheapest;
    
    cheapest = stack;
    while(stack)
    {
        if (stack->push_price <= cheapest->push_price
            && stack->position <= cheapest->position)
        {
                cheapest = stack;
                stack->cheapest = 1;
        }
        else
            stack->cheapest = 0;
        stack = stack->next;
        
    }
    
}

void    init_nodes(t_list *a, t_list *b)
{
    set_curretn_position(a);
    set_curretn_position(b);   
    set_targets(a,b);
    set_costs(a,b);
    set_chapest(b);
}

int main ()
{
    t_list *a;
    t_list *b;
    int n;
    
    a = ft_inistack(-23);
    ft_lstadd_back(&a,ft_inistack(96));
    ft_lstadd_back(&a,ft_inistack(-16));
    ft_lstadd_back(&a,ft_inistack(-21));
    
    b = ft_inistack(-48);
    ft_lstadd_back(&b,ft_inistack(100));
    ft_lstadd_back(&b,ft_inistack(9));
    ft_lstadd_back(&b,ft_inistack(-1));
    ft_lstadd_back(&b,ft_inistack(-8));
    ft_lstadd_back(&b,ft_inistack(-20));
    ft_lstadd_back(&b,ft_inistack(77));
    ft_lstadd_back(&b,ft_inistack(10));
    
    

    init_nodes(a,b);

    while (b)
    {
        if (b->bottom_ones == true)
        {
            n = 1;
        }
        printf("value: %d \ttarget_node: %d  \tposition:%d \tbotton_one:%d \tCosts:%d \tcheapest:%d\n",b->value,b->target_node->value,b->position,n, b->push_price,b->cheapest);
        b = b ->next;
    }

}