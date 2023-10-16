/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 03:34:57 by pjimenez          #+#    #+#             */
/*   Updated: 2023/10/16 19:22:45 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 2 meter los argumentos en una lista
// 1 checkear que son numeros y que no estan repetidos
// 3 preguntarme porque estoy haciendo esto 
// antes de pasar los numeros al stack castearlo

//COMPROBACION DE QUE EL INPUT ES CORRECTO 
t_list	*ft_inistack(int value)
{
	t_list	*n_node;
	
	n_node = (t_list*)malloc(sizeof(t_list));
	
	if (!n_node)
		return (NULL);
	n_node->value = value;
	n_node->next = NULL;
	return (n_node);
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst && lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

void    ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list  *last;
    
    if (!new)
        return ;
    if (!*lst)
    {
        *lst = new;
        return ;
    }
    last = ft_lstlast(*lst);
    last->next = new;
}

int input_ok(char *str)
{
    int i = 0;
    
    if (str[i] == '-' || str[i] == '+')
        i++;
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}

int duplicate(t_list *stack)
{
    t_list  *tmp;
    t_list  *tmp2;

    tmp = stack;

    while (tmp)
    {
        tmp2 = tmp->next;
        while(tmp2)
        {
            if (tmp->value == tmp2->value)
                return (0);
            tmp2 = tmp2->next;
        }
        tmp= tmp->next;
    }
    return (1);
}

void    generate_stack(char *arg, t_list **stack)
{
    int i;
    int x;
    //creamos esta aux ya que si no, no estaremos pasandole a "input_ok" el correcto formato
    char **values;
    
    i = 0;
    x = 0;
    
    values = ft_split(arg,' ');
    
    while (values[i])
    {
        if (input_ok(values[i]))
        {
            x = ft_atoi(values[i]);
            // printf("values %d \n",x);
            ft_lstadd_back(stack, ft_inistack(x));
        }
        else
            printf("mamaste");
        free(values[i]);
        i++;
    }
    free(values);
}





// gilipollas cada arg que este separado por los espacios se coge como un str
int main (int argc, char **argv)
{ 
   t_list *hola;
    int cont = 1;
    //COMO NO INICIALICES EL NODO TE VAS A LA PUTA :)
    hola = NULL;
    // while (i < argv)
    // {
        
    // }


   while (cont < argc)
   {
        generate_stack(argv[cont] ,&hola);
        printf("valor %d %d\n",cont,hola->value);
        hola = hola->next;
        cont ++;
   }
   if (duplicate(hola))
        printf("mamaste");
}