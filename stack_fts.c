/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_fts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 19:06:58 by pjimenez          #+#    #+#             */
/*   Updated: 2023/10/18 23:29:00 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_inistack(int value)
{
	t_list	*n_node;
	
	n_node = (t_list*)malloc(sizeof(t_list));
	
	if (!n_node)
		return (NULL);
	n_node->value = value;
	n_node->next = NULL;
	return (n_node);
}


t_list	*ft_lstlast(t_list *lst)
{
	while (lst && lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

void    ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list  *last;
    
    if (!new)
        return ;
    if (!*lst)
    {
        *lst = new;
        return ;
    }
    last = ft_lstlast(*lst);
    last->next = new;
}


void    free_stack(t_list **stack)
{
    t_list  *tmp;
    
    if (!stack || !(*stack))
        return ;
    tmp = *stack;
    while (*stack)
    {
        tmp = *stack;
        *stack = (*stack)->next;
        free(tmp);
    }
    *stack = NULL;
}


//controlar que solo se libere el que esta como Null
void    errors(t_list **a_stack, t_list **b_stack)
{
    if (*a_stack == NULL || *a_stack != NULL)
        free_stack(a_stack);
    if (*b_stack != NULL || *b_stack == NULL)
        free_stack(b_stack);
    write(2,"error\n",6);
    exit(1);
}


