/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_fts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 04:03:48 by pjimenez          #+#    #+#             */
/*   Updated: 2023/10/20 05:09:15 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push (t_list **src, t_list **dest)
{
    t_list  *push_node;
    if (*src == NULL)
        return ;
    push_node = *src;
    *src = (*src)->next;
    if (*src)
        (*src)->prev = NULL;
    
    if (*dest == NULL)
       *dest = ft_inistack(push_node->value);
    (*dest)->prev = push_node;
    push_node->prev = NULL;
}