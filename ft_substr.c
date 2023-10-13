/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:41:10 by pjimenez          #+#    #+#             */
/*   Updated: 2023/10/12 23:22:24 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//funcion la cual devuelve una cadena de lo contenido en s
//desde el start hasta len(long maxima del substr)
//si el s_len es mayor a la diferencia entre start y len este se igualara
//len se igualara a la diferencia entre s_len y start para que se llegue hasta
//el final de la cadena e vez de que se pase de tamaño
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*cpy;
	int		i;

	i = 0;
	if (start >= ft_strlen(s))
		return (ft_calloc (1, sizeof(char)));
	if (len > (ft_strlen(s) - start))
	{
		len = ft_strlen(s) - start;
	}
	cpy = malloc(sizeof(char) * (len + 1));
	if (s == NULL || cpy == NULL)
		return (NULL);
	while (i < (int)len)
	{
		cpy[i] = s[start];
		i++;
		start++;
	}
	cpy[i] = '\0';
	return (cpy);
}
