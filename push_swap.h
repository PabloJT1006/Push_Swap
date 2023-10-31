/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 03:26:36 by pjimenez          #+#    #+#             */
/*   Updated: 2023/10/31 13:16:39 by pjimenez         ###   ########.fr       */
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
int             index;
struct t_list	*next;
struct t_list	*prev;
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
void swap_nodes(t_list **top);
void    rotate(t_list **stack);
void    reverse_rotate(t_list **stack);
void    ra(t_list **a);
void    rb(t_list **b);
void    rr(t_list **a,t_list **b);
void rra(t_list **a);
void rrb(t_list **b);
void rrr(t_list **a, t_list **b);
void sa(t_list **a);
void sb(t_list **b);
void ss(t_list **a,t_list **b);
t_list  *high_node(t_list *stack);
void push (t_list **src, t_list **dest);
void    lil_sort(t_list **a);
int ft_lstsize(t_list *lst);
void    extralil_sort(t_list **a);
int sorted (t_list *a);
#endif