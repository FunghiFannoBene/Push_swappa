/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:49:00 by marvin            #+#    #+#             */
/*   Updated: 2023/03/23 19:49:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
typedef struct t_push_swappa
{
	int valore;
	int indice;
	struct t_push_swappa *next;
} t_push_swappa;

void pushing(t_push_swappa **push, t_push_swappa **pull,t_push_swappa ***t_head_push, t_push_swappa ***t_head_pull);

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#endif 