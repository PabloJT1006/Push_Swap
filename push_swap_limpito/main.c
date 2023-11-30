/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 03:34:57 by pjimenez          #+#    #+#             */
/*   Updated: 2023/11/30 11:12:59 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 2 meter los argumentos en una lista
// 1 checkear que son numeros y que no estan repetidos
// 3 preguntarme porque estoy haciendo esto 
// antes de pasar los numeros al stack castearlo

//COMPROBACION DE QUE EL INPUT ES CORRECTO 


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
            errors(stack,stack);
        free(values[i]);
        i++;
    }
    free(values);
}


int main (int ac, char **av)
{
    int cont = 1;
    t_list *hola = NULL;
    t_list *dest = NULL;
    while (cont < ac)
   {
        generate_stack(av[cont] ,&hola);
        cont ++;
   }
    if (duplicate(hola))
    {
        errors(&hola,&dest);
    }
    push_swap(&hola,&dest);

    while (hola)
    {
        printf("%d\n",hola->value);
        hola = hola->next;
    }
   
    
}