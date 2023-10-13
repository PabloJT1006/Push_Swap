/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:43:22 by pjimenez          #+#    #+#             */
/*   Updated: 2023/10/12 23:30:59 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//creo la lista con malloc con el numero de items por el size(tipo de content)
//despues utilizamos el bzero para rellenar esos espacios con ceros
//la lista la unizializamos como void ya que no sabemos
//de que tipo va a ser la final
void	*ft_calloc(size_t count, size_t size)
{
	void	*temp;

	temp = (void *) malloc(count * size);
	if (temp == NULL)
	{
		return (NULL);
	}
	ft_bzero (temp, count * size);
	return (temp);
}
