/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 03:26:36 by pjimenez          #+#    #+#             */
/*   Updated: 2023/10/12 07:11:22 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define PUSH_SWAP_H

typedef struct	a_list
{
int			value;
struct s_list	*next;
}               t_list;

#endif