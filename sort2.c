/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 18:16:26 by marvin            #+#    #+#             */
/*   Updated: 2023/06/23 18:16:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	main_sort(t_push_swappa **a, t_push_swappa **b, t_push_swappa **tail_a,
		t_push_swappa **tail_b, int len)
{
	int i;
	i=0;
	int chunk = len/6;
	int lentmp=len;
	int count = 0;
	int move = 0;
	while(lentmp)
	{
	if(((*a)->indice <= chunk))
	{
		if((*a)->indice % 2 == 0)
			pushx(a, b, tail_a, tail_b, 'a');
		else
		{
			pushx(a, b, tail_a, tail_b, 'a');
			updownrotate(b, tail_b, "rb");
			move++;
		}
		count++;
		move++;
	}
	else
	{move++;
		pushx(a, b, tail_a, tail_b, 'a');
	}
	if(count == chunk)
		chunk+=chunk;
	lentmp--;
	}
	while(len)
	{
		if(len % 2 == 0)
		{
			while(((*b)->indice != len)
			{
				
			}
		}
	}
	printf("\n\n%d\n\n", move);
}
