#include "push_swap.h"

void push(t_push_swappa **push, t_push_swappa **take, t_push_swappa **t_push, t_push_swappa **t_take)
{
	t_push_swappa	*curr;

	if (*push == NULL)
		return ;

	curr = *push;
	if ((*push)->next != *push) 
	{
		*push = (*push)->next;
		(*t_push)->next = *push;
		(*push)->prev = *t_push; 
	}
	else
	{
		*push = NULL;
		*t_push = NULL;
	}

	if (*take != NULL)
	{
		curr->next = *take;
		curr->prev = (*take)->prev;
		(*take)->prev->next = curr;
		(*take)->prev = curr;
		*take = curr;
	}
	else
	{
		curr->next = curr;
		curr->prev = curr;
		*t_take = curr;
		*take = curr;
	}
	
	if (*t_take == NULL)
		*t_take = *take;

	(*t_take)->next = *take;
	(*take)->prev = *t_take;
}


void	rotate(t_push_swappa **head, t_push_swappa **tail, int up_down)
{
	if (*head == NULL)
		return ;
	if (up_down == 1)
	{
		*tail = *head;
		*head = (*head)->next;
	}
	else if (up_down == -1)
	{
		*head = *tail;
		*tail = (*head)->prev;
	}
}
