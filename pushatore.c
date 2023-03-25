/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusher.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 03:34:37 by marvin            #+#    #+#             */
/*   Updated: 2023/03/25 03:34:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pushing(t_push_swappa **push, t_push_swappa **pull,t_push_swappa ***t_head_push, t_push_swappa ***t_head_pull)
{
	  if (*push == NULL) {
        return;
    }
    //pseudo elemento per muoverlo
	t_push_swappa *new_top = *push;
    *push = new_top->next;




	**t_head_push = (*push)->next;
	(*push)->next = *pull;
	*t_head_pull = push;
}