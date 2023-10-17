/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 03:26:36 by pjimenez          #+#    #+#             */
/*   Updated: 2023/10/17 17:36:05 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define PUSH_SWAP_H

typedef struct	t_list
{
int			    value;
struct t_list	*next;
}               t_list;

int	ft_atoi(const char *nptr);

int	ft_isdigit(int c);

char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
void    errors(t_list **a_stack, t_list **b_stack);
void    free_stack(t_list **stack);
t_list	*ft_inistack(int value);
t_list	*ft_lstlast(t_list *lst);
void    ft_lstadd_back(t_list **lst, t_list *new);
void    free_stack(t_list **stack);
void    errors(t_list **a_stack, t_list **b_stack);
int input_ok(char *str);
int duplicate(t_list *stack);
#endif