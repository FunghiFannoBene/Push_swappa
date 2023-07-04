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

void sort_3(t_push_swappa **a, t_push_swappa **tail_a) 
{
    if ((*a)->indice > (*a)->next->indice && (*a)->next->indice < (*a)->next->next->indice && (*a)->indice < (*a)->next->next->indice)
        swap(&((*a)->valore), &((*a)->next->valore),&((*a)->indice) ,&((*a)->next->indice), 'a');
    else if ((*a)->indice > (*a)->next->indice && (*a)->next->indice > (*a)->next->next->indice)
    {
        swap(&((*a)->valore), &((*a)->next->valore),&((*a)->indice) ,&((*a)->next->indice), 'a');
        updownrotate(a, tail_a, "rra");
    }
    else if ((*a)->indice > (*a)->next->indice && (*a)->next->indice < (*a)->next->next->indice && (*a)->indice > (*a)->next->next->indice)
        updownrotate(a, tail_a, "ra");
    else if ((*a)->indice < (*a)->next->indice && (*a)->next->indice > (*a)->next->next->indice && (*a)->indice > (*a)->next->next->indice)
    {
        swap(&((*a)->valore), &((*a)->next->valore),&((*a)->indice) ,&((*a)->next->indice), 'a');
        updownrotate(a, tail_a, "ra");
    }
    else if ((*a)->indice < (*a)->next->indice && (*a)->next->indice > (*a)->next->next->indice)
        updownrotate(a, tail_a, "rra");
}


int fastestpath(t_push_swappa **b, int len)
{
    int forward_steps = 0;
    int backward_steps = 0;
    t_push_swappa *forward;
    t_push_swappa *backward;
	
	if(*b == NULL)
		return -1;

	forward = *b;
	backward = (*b)->prev;
    
    while (forward_steps < len && backward_steps < len) 
    {
        if (forward->indice == len) 
        {
            return forward_steps;
        }

        if (backward->indice == len) 
        {
            return -backward_steps; 
        }
        
        forward = forward->next;
        backward = backward->prev;
        
        forward_steps++;
        backward_steps++;
    }

    return -1; 
}


int round_up(double number) {
    int integer_part = (int)number;
    double decimal_part = number - integer_part;

    if (decimal_part > 0) {
        return integer_part + 1;
    } else {
        return integer_part;
    }
}

int calculate_chunk_size(int length) {
    double chunk_size = 0.046 * length + 1.54;
    return round_up(chunk_size);
}

void createascending(t_push_swappa **a, t_push_swappa **b, t_push_swappa **tail_a, t_push_swappa **tail_b)
{
	int i;
	int prevlen = (*a)->indice;
	updownrotate(a, tail_a, "ra");
	updownrotate(a, tail_a, "ra");
	i=0;
	while((*a)->indice != prevlen)
	{
		if((*a)->indice != prevlen  && (*a)->indice > (*tail_a)->indice)
		{
			if((*a)->next->indice > (*a)->indice)
			{
				if((*b)->indice < (*b)->next->indice)
					double_swap(&((*a)->valore), &((*a)->next->valore), &((*b)->valore),&((*b)->next->valore),&((*a)->indice) ,&((*a)->next->indice),&((*b)->indice) ,&((*b)->next->indice));
				else
					swap(&((*a)->valore), &((*a)->next->valore),&((*a)->indice) ,&((*a)->next->indice), 'a');
			}
			if((*b)->indice > (*a)->indice)
				pushx(b, a, tail_b, tail_a, 'b');
			if((*b)->indice < (*tail_b)->indice)
				double_updownrotate(a, tail_a, b, tail_b, "rr");
			else
				updownrotate(a, tail_a, "ra");
		}
		else
			pushx(a, b, tail_a, tail_b, 'a');
		if((*a)->indice == prevlen)
			break;
	}
}

void chunkVShape(t_push_swappa **a, t_push_swappa **b, t_push_swappa **tail_a,
		t_push_swappa **tail_b, int len)
{
	int	chunk;
	int	lentmp;
	int waitlist;
	int startchunk;
	int doubletime;
	int count;

	count = 0;
	waitlist = 0;
	chunk =  46; //calculate_chunk_size(len); //ottimale 70 per 500;  //46 per 100
	lentmp = len;
	doubletime = chunk;
	startchunk = chunk/2;
	

	while (*a && lentmp)
	{
		if((*a)->indice == len && chunk > (len/15 * 14))
		{
			createascending(a, b, tail_a, tail_b);
			break;
		}
		if (((*a)->indice <= chunk))
		{
			if ((*a)->indice <= chunk && (*a)->indice >= chunk - startchunk+1)
			{
				pushx(a, b, tail_a, tail_b, 'a');
			}
			else
			{
				pushx(a, b, tail_a, tail_b, 'a');
				if((*a) && (*a)->indice <= chunk)
					updownrotate(b, tail_b, "rb");
				else
					double_updownrotate(a, tail_a, b, tail_b, "rr");
			}
			count++;
			lentmp--;
		}
		else
		{
				updownrotate(a, tail_a, "ra");
		}
		if(count == chunk)
		{
			chunk=chunk+startchunk+(startchunk/2);
		}
	}
}
void rotate_sort(t_push_swappa **a, t_push_swappa **b, t_push_swappa **tail_a,
		t_push_swappa **tail_b, int len)
{
	int pushed_swap;
	pushed_swap = 0;
	int max = len;
	int count = 0;
	char rb[3] = "rb";
	char rrb[4] = "rrb";
	char* verse;
	len--;
	while (len >= 0)
	{
		while((*a) && (*b) && len != 0 && (((*tail_a)->indice < (*b)->indice) || (*tail_a)->indice == max) && (*b)->indice != len)
			{
				pushx(b, a, tail_b, tail_a, 'b');
				if((*b)->indice != len && fastestpath(b, len) > 0)
					double_updownrotate(a, tail_a, b, tail_b, "rr");
				else
					updownrotate(a, tail_a, "ra");
			}
			while((*a) && (*tail_a)->indice == len)
			{
				updownrotate(a, tail_a, "rra");
				len--;
			}	
			if(fastestpath(b, len) > 0)
					verse = rb;
				else
					verse = rrb;
			while ((*b) && (*b)->indice != len)
			{
				if((*b)->indice < len && (*b)->indice > len-1)
				{
					pushx(b, a, tail_b, tail_a, 'b');
					pushed_swap++;
				}
				else
				{
					if((*b)->indice > (*tail_a)->indice && (*b)->indice != len)
					{
						while((*b)->indice > (*tail_a)->indice && (*b)->indice != len)
						{
							pushx(b, a, tail_b, tail_a, 'b');
							if((*b)->indice != len && strcmp(verse, "rb") == 0)
								double_updownrotate(a, tail_a, b, tail_b, "rr");
							else
								updownrotate(a, tail_a, "ra");
						}
					}
					else
						updownrotate(b, tail_b, verse);
				}
			}
			pushx(b, a, tail_b, tail_a, 'b');
			if(pushed_swap)
			{
				swap(&((*a)->valore), &((*a)->next->valore),&((*a)->indice) ,&((*a)->next->indice), 'a');
				pushed_swap--;
				len--;
			}
			len--;
	}
}

void	main_sort(t_push_swappa **a, t_push_swappa **b, t_push_swappa **tail_a,
		t_push_swappa **tail_b, int len)
{
	chunkVShape(a, b, tail_a, tail_b, len);
	rotate_sort(a, b, tail_a, tail_b,len);
}
