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

void freelist(t_push_swappa	**a)
{
	t_push_swappa	*tmp;
	tmp = *a;
	while (*a != NULL) 
	{
    tmp = *a;
    *a = (*a)->next;
    free(tmp);
	}
}

int	main(int argc, char **argv)
{
	t_push_swappa	*a = NULL;
	t_push_swappa	*b = NULL;
	t_push_swappa	**tail_a;
	t_push_swappa	**tail_b;
	// t_push_swappa	*curr_a;
	// t_push_swappa	*curr_b;
	int len;

	tail_a = malloc(sizeof(t_push_swappa *));
	tail_b = malloc(sizeof(t_push_swappa *));
	if (tail_a == NULL || tail_b == NULL) {
    free(tail_a);
    free(tail_b);
    return 0;
	}
	*tail_a = NULL;
	*tail_b = NULL;


	if (argc > 1)
	{
		if (argc == 2)
			argv = ft_split1(argv[1], ' ');
		len = circular_struct_build(argv, &a, &tail_a);
		if(len == -1)
		{
			if (tail_a != NULL && *tail_a != NULL) {
			(*tail_a)->next = NULL;
			}
			freelist(&a);
			printf("Error\n");
			free(*tail_b);
			free(tail_a);
			free(tail_b);
			return(0);
		}
		main_sort(&a, &b, tail_a, tail_b, len);
		// if (a != NULL)
		// {
		// 	printf("List A: \n");
		// 	curr_a = a; // Start from the first element
		// 	do
		// 	{
		// 		printf("A: %d -> %d \n", curr_a->indice, curr_a->valore);
		// 		curr_a = curr_a->next; // Move to the next element
		// 	} while (curr_a != a); // Stop when we have circled back to the start
		// 	printf("\n");
		// }
		// if (b != NULL)
		// {
		// 	printf("List B:\n");
		// 	curr_b = b; // Start from the first element
		// 	do
		// 	{
		// 		printf("B: %d -> %d\n", curr_b->indice, curr_b->valore);
		// 		curr_b = curr_b->next; // Move to the next element
		// 	} while (curr_b != b); // Stop when we have circled back to the start
		// 	printf("\n");
		// }
	}
	if (tail_a != NULL && *tail_a != NULL) {
		(*tail_a)->next = NULL;
	}
	freelist(&a);
	free(tail_a);
	free(tail_b);
	return (0);
}




//gcc -g push_swap.c implement.c command.c functions.c main_functions.c -o push_swap -Werror -Wextra -Wall

//./push_swap $(seq 1 100 | shuf | tr '\n' ' ')