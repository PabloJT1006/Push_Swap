/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_fts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 19:06:58 by pjimenez          #+#    #+#             */
/*   Updated: 2023/10/16 19:23:51 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void    free_stack(t_list **stack)
{
    t_list  **tmp;
       
    if (!stack || !(*stack))
        return ;
    
    while (*stack)
    {
        tmp = (*stack)->next;
        free(*stack);
        *stack = tmp;
    }
    //quedaria un unltimo nodo porlo que
    *stack = NULL;
}

void    errors(t_list **a_stack, t_list **b_stack)
{
    if ()
    {
        /* code */
    }
    
}


