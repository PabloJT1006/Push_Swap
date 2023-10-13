/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 03:26:36 by pjimenez          #+#    #+#             */
/*   Updated: 2023/10/12 23:32:40 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define PUSH_SWAP_H

typedef struct	a_list
{
int			    value;
struct a_list	*next;
}               t_list;

int	ft_atoi(const char *nptr);

int	ft_isdigit(int c);

char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
#endif