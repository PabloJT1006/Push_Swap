/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:28:47 by pjimenez          #+#    #+#             */
/*   Updated: 2023/12/18 13:46:18 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	input_ok(char *str)
{
	int		i;
	int		j;
	int		result;
	char	**values;

	i = 0;
	result = 1;
	values = ft_split(str, ' ');
	while (values[i])
	{
		j = 0;
		if (values[i][j] == '-' || values[i][j] == '+')
			j++;
		while (values[i][j])
		{
			if (!ft_isdigit(values[i][j]))
				result = 0;
			j++;
		}
		free(values[i]);
		i++;
	}
	free(values);
	return (result);
}

int	duplicate(t_list *stack)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = stack;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->value == tmp2->value)
				return (1);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (0);
}

int	sorted(t_list *a)
{
	t_list	*tmp;
	t_list	*tmp2;
	int		check;

	check = 1;
	tmp = a;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->value > tmp2->value)
				check = 0;
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (check);
}

void	errors(t_list **a_stack, t_list **b_stack)
{
	if (*a_stack == NULL || *a_stack != NULL)
		free_stack(a_stack);
	if (*b_stack != NULL || *b_stack == NULL)
		free_stack(b_stack);
	write(2, "Error\n", 6);
	exit(1);
}
