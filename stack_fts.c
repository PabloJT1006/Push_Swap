/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_fts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 19:06:58 by pjimenez          #+#    #+#             */
/*   Updated: 2023/12/18 13:45:17 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_inistack(int value)
{
	t_list	*n_node;

	n_node = (t_list *)malloc(sizeof(t_list));
	if (!n_node)
		return (NULL);
	n_node->value = value;
	n_node->next = NULL;
	n_node->prev = NULL;
	n_node->target_node = NULL;
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

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
	new->prev = last;
}

void	free_stack(t_list **stack)
{
	t_list	*tmp;

	if (!stack || !(*stack))
		return ;
	tmp = *stack;
	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
		tmp = NULL;
	}
	stack = NULL;
}

void	generate_stack(char *arg, t_list **stack)
{
	int		i;
	int		x;
	char	**values;

	i = 0;
	x = 0;
	if (input_ok(arg))
	{
		values = ft_split(arg, ' ');
		while (values[i])
		{
			x = ft_atoi(values[i]);
			ft_lstadd_back(stack, ft_inistack(x));
			free(values[i]);
			i++;
		}
		free(values);
	}
	else
		errors(stack, stack);
}
