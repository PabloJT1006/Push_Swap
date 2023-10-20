/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 03:34:57 by pjimenez          #+#    #+#             */
/*   Updated: 2023/10/20 04:45:30 by pjimenez         ###   ########.fr       */
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

// gilipollas cada arg que este separado por los espacios se coge como un str
int main (int argc, char **argv)
{ 
   t_list *hola;
   t_list *src;
   t_list *dest = NULL;
   t_list *aux;
    int cont = 1;
    //COMO NO INICIALICES EL NODO TE VAS A LA PUTA :)
    hola = NULL;
    // while (i < argv)
    // {
        
    // }
// GENERANDO STACK----------------------------------------------------------------------
   while (cont < argc)
   {
        generate_stack(argv[cont] ,&hola);
        cont ++;
   }
    if (duplicate(hola))
    {
        errors(&hola,&dest);
    }
// PROBANDO ROTATE---------------------------------------------------------------------------
aux = hola;
src = hola;
while (hola)
{
    printf("Vhola:%d\n",hola->value);
    hola = hola->next;
}
    printf("USOS DEL ROTATE\n");
    rotate(&aux);

   while (aux)
   {
        printf("Vaux:%d\n",aux->value);
        aux = aux->next;
   }
// COMPROBANDO PUSH ------------------------------------------------------
printf("\n\nCOMPROBACION DEL PUSH---------------------------------->\n");
push(&src,&dest);

printf("valores del origen---------------------------\n");

while (src)
{
    printf("Vb:%d\n",src->value);
    src = src->next;
}
printf("------------------------------------------------\n\n");
printf("valores del destino---------------------------\n");
while (dest)
{
    printf("Vb:%d\n",dest->value);
    dest = dest->next;
}
printf("------------------------------------------------\n\n");

}
