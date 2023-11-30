/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:00:04 by pjimenez          #+#    #+#             */
/*   Updated: 2023/10/12 23:20:11 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//lo primero de todo funcion que te cunte la cantidad de palabras para alocar
//segun ese numero de palabras generar la cantidad de filas
//Utilizar un contador de caracteres para cada palabra y y este resultado
//utilizarlo para el len de substr(te coje una lista de caracteres desde 0 hasta
//hasta el len calculado), el resultado dara la palabra hasta la coma, y asi
//alocamos cada celda el tamaño perfecto

#include "push_swap.h"

static int	word_counter(char const *str, char c)
{
	size_t	i;
	int		cont;

	i = 0;
	cont = 0;
	while (str[i] == c)
	{
		i++;
	}
	while (i < ft_strlen(str))
	{
		if (str[i] == c && str[i - 1] != c)
		{
			cont++;
		}
		if (str[i] != c && str[i + 1] == '\0')
		{
			cont++;
		}
		i++;
	}
	return (cont);
}
//cuenta el numero de letras hasta que encuentra un split,
//en la principal al ir incrementando el puntero directamente
//esta funcion recorrera la cadeana hasta que encuentre el split

static int	char_count(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
	{
		i++;
	}
	return (i);
}
//al ser una bidimensional de una sola columna,
//con alocar las filas(words) valdria

static char	**memory_allocate(char const *s, char c)
{
	char	**str;
	int		rows;

	rows = word_counter(s, c);
	str = (char **)malloc(sizeof(char *) * (rows + 1));
	if (!s || !str)
	{
		return (NULL);
	}
	return (str);
}
//funcion para liberar fila por fila

static void	ft_free(char **str, int i)

{
	while (i-- > 0)
	{
		free(str[i]);
	}
	free(str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		j;
	int		ctrl;

	j = 0;
	ctrl = 0;
	str = memory_allocate(s, c);
	if (!str || !s)
		return (ft_free(str, j), NULL);
	while (*s != '\0')
	{
		if (*s != c && ctrl == 0)
		{
			str[j] = ft_substr(s, 0, char_count(s, c));
			if (!str[j])
				return (ft_free(str, j), NULL);
			ctrl = 1;
			j++;
		}
		if (*s == c && ctrl == 1)
			ctrl = 0;
		s++;
	}
	str[j] = NULL;
	return (str);
}
// int main (void)
// {
// 	char **tabstr;

// 	if (!(tabstr = ft_split("", 'z')))
//         printf("NULL");
//     else
//         if (!tabstr[0])
//             printf("ok\n");
// 	return (0);
// }
