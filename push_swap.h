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

typedef struct push_swappa
{
	int valore;
	int indice;
	struct push_swappa *next;
} push_swappa;

struct push_swappa *tail;
struct push_swappa *head;

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>