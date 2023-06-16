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

int	check(int *index, int len, int val)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (index[i] == val)
			return (i + 1);
		i++;
	}
}

int	circular_struct_build(char **argv, t_push_swappa **a,
		t_push_swappa ***tail_a)
{
	int				i;
	int				*index;
	int				len;
	t_push_swappa	*element_i;
	t_push_swappa	*tmp;

	i = 1;
	element_i = malloc(sizeof(t_push_swappa));
	while (argv[i])
		i++;
	index = malloc(sizeof(int) * i - 1);
	i = 1;
	while (argv[i])
	{
		index[i - 1] = atoi(argv[i]);
		i++;
	}
	len = i - 1;
	quicks(index, 0, len - 1);
	i=0;
	while(i<len)
	{
		i++;
		if(index[i] == index[i-1])
			return(-1);
	}
	i = 1;
	element_i->valore = atoi(argv[i]);
	element_i->indice = check(index, len, element_i->valore);
	element_i->next = NULL;
	i++;
	*a = element_i;
	while (argv[i])
	{
		tmp = element_i;
		element_i = malloc(sizeof(t_push_swappa));
		element_i->valore = atoi(argv[i]);
		element_i->indice = check(index, len, element_i->valore);
		element_i->next = NULL;
		element_i->prev = tmp;
		tmp->next = element_i;
		i++;
	}
	(*a)->prev = element_i;
	**tail_a = element_i;
	(**tail_a)->next = *a;
	free(index);
	return(0);
}

int addfastpath(t_push_swappa **a, int lentmp)
{
	t_push_swappa *next = (*a)->next;
	t_push_swappa *prev = (*a)->prev;
	int i = 0;
	int x = 0;
	while(prev)
	{
		if(prev->indice <= lentmp)
			break;
		prev = prev->prev;
		x++;
	}
	while(next)
	{
		if(next->indice <= lentmp)
			break;
		next = next->next;
		i++;
	}
	return(i-x);
}

int addfastpathb(t_push_swappa **a, int lentmp)
{
	t_push_swappa *next = (*a)->next;
	t_push_swappa *prev = (*a)->prev;
	int i = 0;
	int x = 0;
	while(prev)
	{
		if(prev->indice == lentmp)
			break;
		prev = prev->prev;
		x++;
	}
	while(next)
	{
		if(next->indice == lentmp)
			break;
		next = next->next;
		i++;
	}
	return(i-x);
}

void	main_sort(t_push_swappa **a, t_push_swappa **b, t_push_swappa **tail_a,
		t_push_swappa **tail_b)
{
	t_push_swappa	*curr;
	int				len;
	int				lentmp;
	int				z;
	int				m;
	int				prev;
	int				i;
	curr = *a;
	len = 0;
	z = 0;
	prev = 0;
	m = 0;
	i = 2;
	while (curr)
	{
		curr = curr->next;
		len++;
		if (curr == (*tail_a)->next)
			break ;
	}
	lentmp = len / 2;
	while (m < len - 1)
	{
		if ((*a)->indice <= lentmp)
		{
			m++;
			pushx(a, b, tail_a, tail_b, 'a');
			z++;
		}
		else if ((*a)->next->indice <= lentmp)
		{
			if ((*b)->indice < (*b)->next->indice)
			{
				double_swap(&((*a)->valore), &((*a)->next->valore),
						&((*b)->valore), &((*b)->next->valore), &((*a)->indice),
						&((*a)->next->indice), &((*b)->indice),
						&((*b)->next->indice));
				z++;
			}
			else
			{
				swap(&((*a)->valore), &((*a)->next->valore), &((*a)->indice),
						&((*a)->next->indice), 'a');
				z++;
			}
			pushx(a, b, tail_a, tail_b, 'a');
			z++;
			m++;
		}
		else
		{
			if(addfastpath(a, lentmp) <= 0)
			{
				while((*a)->indice > lentmp)
				{
					if((*b)->indice < (*b)->next->indice)
						double_updownrotate(a, tail_a, b, tail_b, "rr"); 
					else
						updownrotate(a, tail_a, "ra");
					z++;
				}
			}
			else
			{
				while((*a)->indice > lentmp)
				{
					if((*b)->indice < (*b)->prev->indice)
						double_updownrotate(a, tail_a, b, tail_b, "rrr"); 
					else
						updownrotate(a, tail_a, "rra");
					z++;
				}
			}
		}
		if (m == lentmp)
		{
			prev = lentmp;
			lentmp = lentmp + ((len - lentmp + i - 1) / i);
		}
	}
	len = len - 1;
	while(len)
	{
		if((*b)->indice == len)
		{
			pushx(b, a, tail_b, tail_a, 'b');
			len--;
			z++;
		}
		else if(addfastpathb(b, len) <= 0)
		{
			while (*b && (*b)->indice < len)
			{
				updownrotate(b, tail_b, "rb");
				z++;
			}
		}
		else
		{
			while (*b && (*b)->indice < len)
			{
				updownrotate(b, tail_b, "rrb"); 
				z++;
			}
		}
	}

	printf("\n\nMosse: %d\n\n", z);
	// swap(&((*a)->valore), &((*a)->next->valore),&((*a)->indice) ,&((*a)->next->indice), 'a'); // sa
	// swap(&((*b)->valore), &((*b)->next->valore),&((*b)->indice) ,&((*b)->next->indice), 'b');
	// pushx(a, b, tail_a, tail_b, 'a');
	// double_updownrotate(a, tail_a, b, tail_b, "rr"); // entrambi UP di 1;
	// double_updownrotate(a, tail_a, b, tail_b, "rrr"); // entrambi DOWN di 1;
	// swap(&((*a)->valore), &((*a)->next->valore), 'a');
	// pushx(b, a, tail_b, tail_a, 'b');
	// double_swap(&((*a)->valore), &((*a)->next->valore), &((*b)->valore),&((*b)->next->valore),&((*a)->indice) ,&((*a)->next->indice,&((*b)->indice) ,&((*b)->next->indice));
	// updownrotate(a, tail_a, "ra"); // a UP di 1;
	// updownrotate(b, tail_b, "rb"); // b UP di 1;
	// updownrotate(a, tail_a, "rra"); // a DOWN di 1;
	// updownrotate(b, tail_b, "rrb"); // b DOWN di 1;
	// pushx(a, b, tail_a, tail_b, 'a'); // pusha a in b "pb"
	// pushx(b, a, tail_b, tail_a, 'b'); // pusha b in a "pa"
}

int	main(int argc, char **argv)
{
	t_push_swappa	*a;
	t_push_swappa	*b;
	t_push_swappa	**tail_a;
	t_push_swappa	**tail_b;
	t_push_swappa	*curr_a;
	t_push_swappa	*curr_b;

	b = NULL;
	a = NULL;
	tail_a = malloc(sizeof(t_push_swappa *));
	tail_b = malloc(sizeof(t_push_swappa *));
	*tail_b = malloc(sizeof(t_push_swappa));
	if (argc > 1)
	{
		if (argc == 2)
			argv = ft_split1(argv[1], ' '); //split addattato con +1 per argv settato a NULL;
		if(circular_struct_build(argv, &a, &tail_a) == -1)
		{
			printf("Ci sono doppioni");
			return(0);
		}
		main_sort(&a, &b, tail_a, tail_b);
		if (a != NULL)
		{
			printf("List A: \n");
			curr_a = a; // Start from the first element
			do
			{
				printf("A: %d -> %d \n", curr_a->indice, curr_a->valore);
				curr_a = curr_a->next; // Move to the next element
			} while (curr_a != a); // Stop when we have circled back to the start
			printf("\n");
		}
		if (b != NULL)
		{
			printf("List B:\n");
			curr_b = b; // Start from the first element
			do
			{
				printf("B: %d -> %d\n", curr_b->indice, curr_b->valore);
				curr_b = curr_b->next; // Move to the next element
			} while (curr_b != b); // Stop when we have circled back to the start
			printf("\n");
		}
		else
			printf("Non ci sono abbastanza argomenti.");
		return (0);
	}
}
