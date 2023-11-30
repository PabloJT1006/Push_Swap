/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:28:47 by pjimenez          #+#    #+#             */
/*   Updated: 2023/10/18 23:50:26 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int input_ok(char *str)
{
    int i = 0;
    
    if (str[i] == '-' || str[i] == '+')
        i++;
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}

int duplicate(t_list *stack)
{
    t_list  *tmp;
    t_list  *tmp2;

    tmp = stack;

    while (tmp)
    {
        tmp2 = tmp->next;
        while(tmp2)
        {
            if (tmp->value == tmp2->value)
                return (1);
            tmp2 = tmp2->next;
        }
        tmp= tmp->next;
    }
    return (0);
}