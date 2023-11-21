/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_fts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:55:48 by pjimenez          #+#    #+#             */
/*   Updated: 2023/11/21 13:48:01 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"





void set_3nodes(t_list **a, t_list **b)
{
    int len;

    len = ft_lstsize(*a);
    while(len != 3)
    {
        pb(a,b);
        len = ft_lstsize(*a);
    }
}
// void    sort_algorithm(t_list **a, t_list **b)
// {
//     int len_a;

//     len_a = ft_lstsize(a);

//     if (len_a >= 2)
//     {
//         if (len_a == 2)
//             extralil_sort(&a);
//         else if (len_a == 3)
//             lil_sort(&a);
//         else if (len_a > 3)
//         {
//             set_3nodes(&a,&b);
//             lil_sort(&a);
//             //llamar al siguiente algoritmo
//         }
        
//     }
//     else
//         return ;
// }


