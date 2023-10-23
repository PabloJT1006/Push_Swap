/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_fts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 04:03:48 by pjimenez          #+#    #+#             */
/*   Updated: 2023/10/23 13:18:11 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// A DESTINO NO SE LE PUEDE HACER UN PUSH EN EL QUE SE MODIFIQUE EL TAMÑO ORIGINAL DE SRC
// POR LO QUE NOSE PUEDE AÑADIR NUEVOS NODOS YA QUE SRC Y DEST COMPARTIRAN TAMAÑO
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
    else
    {
        //le decimos al nodo a meter que el siguiente es el primero de destino
        push_node->next = (*dest);
        //tmb le decimios que el previo va a ser null, ya que al ser primero no hay
        push_node->next->prev = push_node;
        push_node->prev = NULL;
        //con estos datos guardados en push_node, esteblecemos el primero de dest como push_node
        (*dest) = push_node;
    }
}