/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_fts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 03:30:13 by pjimenez          #+#    #+#             */
/*   Updated: 2023/10/20 04:12:45 by pjimenez         ###   ########.fr       */
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
    last_node->next->next = NULL;
}