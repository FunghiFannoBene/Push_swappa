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

void circular_struct_build(char **argv, push_swappa **a)
{
	int i;
	i = 1;
	push_swappa *new_a;
	new_a = malloc(sizeof(push_swappa));
	new_a->indice = i;
	new_a->valore = atoi(argv[i]);
	new_a->next = NULL;
	i++;
	*a = new_a;
	head_a=a;
	while(argv[i])
   {
        // crea un nuovo elemento push_swappa e assegnagli il valore di argv[i]
        push_swappa *element_i = malloc(sizeof(push_swappa));
        element_i->indice = i;
        element_i->valore = atoi(argv[i]);
        element_i->next = NULL;

        // aggiungi il nuovo elemento alla fine della lista
        push_swappa *scorri = *a;
        while (scorri->next != NULL) {
            scorri = scorri->next;
        }
		tail_a = element_i;
        scorri->next = element_i;
        // passa alla stringa successiva
        i++;
    }
	tail_a->next = *head_a;
}

int main(int argc, char **argv)
{
	push_swappa *a;
	push_swappa *b;
	if(argc > 2)
	{
	circular_struct_build(argv, &a);
	}
	push_swappa *current = a;
    while (current != tail_a) {
    printf("indice: %d, valore: %d head: %d tail: %d\n", current->indice, current->valore, (*head_a)->valore, tail_a->valore);
    current = current->next;
    }
	printf("indice: %d, valore: %d head: %d tail: %d\n", current->indice, current->valore, (*head_a)->valore, tail_a->valore);

	push_swappa *current2 = a;
	while(current2->indice != 4)
	{
		current2 = current2->next;
	}
	printf("%d", current2->valore);
}