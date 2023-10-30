/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_fts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:55:48 by pjimenez          #+#    #+#             */
/*   Updated: 2023/10/30 14:14:49 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_algorithm(t_list **a)
{
    int len_a;

    len_a = ft_lstsize(a);

    if (len_a >= 2)
    {
        if (len_a == 2)
            extralil_sort(&a);
        else if (len_a == 3)
            lil_sort(&a);
        // else if (len_a > 3)
            //algortimo tocho
        
    }
    else
        return ;
}