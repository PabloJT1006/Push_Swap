/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_fts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 03:30:13 by pjimenez          #+#    #+#             */
/*   Updated: 2023/10/23 17:46:46 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rotate(t_list **first)
{
    t_list  *last_node;
    
    if (*first == NULL)
        return ;
    last_node = ft_lstlast(*first);
    last_node->next = *first;
    (*first) = (*first)->next;
    (*first)->prev=NULL;
    // last_node->next->prev = last_node;
    last_node->next->next = NULL;
}

void    ra(t_list **a)
{
    rotate(a);
    write(1,"ra\n",3);
}
void    rb(t_list **b)
{
    rotate(b);
    write(1,"rb\n",3);
} 
void    rr(t_list **a,t_list **b)
{
    rotate(a);
    rotate(b);
    write(1,"rr\n",3);
} 
