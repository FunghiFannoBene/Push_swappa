/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 18:15:49 by marvin            #+#    #+#             */
/*   Updated: 2023/06/23 18:15:49 by marvin           ###   ########.fr       */
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
	return(i+1);
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
	return(len);
}

int addfastpathb(t_push_swappa **a, int lentmp)
{
	t_push_swappa *next = (*a)->next;
	t_push_swappa *prev = (*a)->prev;
	int i = 0;
	int x = 0;
	while(prev && prev->prev->indice != (*a)->indice)
	{
		if(prev->indice == lentmp)
			break;
		prev = prev->prev;
		x++;
		if(x>lentmp)
			break;
	}
	while(next && next->next->indice != (*a)->indice)
	{
		if(next->indice == lentmp)
			break;
		next = next->next;
		i++;
		if(i>lentmp)
			break;
	}
	return(i-x);
}
