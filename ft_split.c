/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:00:04 by pjimenez          #+#    #+#             */
/*   Updated: 2023/12/15 18:27:04 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
