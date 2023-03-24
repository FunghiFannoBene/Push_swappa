/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:48:20 by marvin            #+#    #+#             */
/*   Updated: 2023/03/23 19:48:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void convert_and_insert(char **argv, push_swappa **a)
{
	int i;
	i = 1;
	push_swappa *new_a;
	new_a = malloc(sizeof(push_swappa));
	new_a->indice = i;
	new_a->valore = atoi(argv[i]);
	new_a->next = NULL;
	new_a->prev = NULL;
	i++;
	*a = new_a;
	while(argv[i])
   {
        // crea un nuovo elemento push_swappa e assegnagli il valore di argv[i]
        push_swappa *element_i = malloc(sizeof(push_swappa));
        element_i->indice = i;
        element_i->valore = atoi(argv[i]);
        element_i->prev = *a;
        element_i->next = NULL;

        // aggiungi il nuovo elemento alla fine della lista
        push_swappa *scorri = *a;
        while (scorri->next != NULL) {
            scorri = scorri->next;
        }
        scorri->next = element_i;
        element_i->prev = scorri;

        // passa alla stringa successiva
        i++;
    }
}

int main(int argc, char **argv)
{
	int *value;
	push_swappa *a;
	push_swappa *b;
	a = (push_swappa *)malloc(sizeof(push_swappa));
	b = (push_swappa *)malloc(sizeof(push_swappa));
	a = NULL;
	b = NULL;
	if(argc > 2)
	{
	convert_and_insert(argv, &a);
	}
	push_swappa *current = a;
    while (current != NULL) {
    printf("indice: %d, valore: %d\n", current->indice, current->valore);
    current = current->next;
    }
}