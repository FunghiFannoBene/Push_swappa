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

# include <string.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	t_push_swappa
{
	int				valore;
	int				indice;
	struct t_push_swappa	*next;
	struct t_push_swappa	*prev;
}				t_push_swappa;

void freelist(t_push_swappa	**a);
void	swap(int *val1, int *val2, int *ind1, int *ind2, char flag);
void	double_swap(int *val1, int *val2, int *val3, int *val4, int *ind1, int *ind2, int *ind3, int *ind4);
void	push(t_push_swappa **push, t_push_swappa **take, t_push_swappa **t_push, t_push_swappa **t_take);
void	rotate(t_push_swappa **head, t_push_swappa **tail, int up_down);
void	quicks(int *a, int first, int last);
void	pushx(t_push_swappa **pushr, t_push_swappa **take, t_push_swappa **t_push, t_push_swappa **t_take, char d);
void	main_sort(t_push_swappa **a, t_push_swappa **b, t_push_swappa **tail_a, t_push_swappa **tail_b, int len);
void	double_updownrotate(t_push_swappa **head, t_push_swappa **tail, t_push_swappa **head1, t_push_swappa **tail1, char *d);
void	updownrotate(t_push_swappa **head, t_push_swappa **tail, char *d);
int		nstr(const char *s, char c);
int		checksizesub(const char *s, char c);
char	**ft_split1(char const *s, char c);
int		addfastpathb(t_push_swappa **a, int lentmp);
void	swapq(int *a, int *b);
int		ft_strlen(const char *s);
int		check(int *index, int len, int val);
int		lastn(t_push_swappa **a, t_push_swappa **tail_a, int m);
int addfastpathb(t_push_swappa **a, int lentmp);
int	circular_struct_build(char **argv, t_push_swappa **a,
		t_push_swappa ***tail_a);
int	check(int *index, int len, int val);
void process_remaining(t_push_swappa **a, t_push_swappa **b, t_push_swappa **tail_a, t_push_swappa **tail_b, int *len, int *count);
void check_mid_length(t_push_swappa **a, t_push_swappa **b, t_push_swappa **tail_a, t_push_swappa **tail_b, int *m, int *lentmp, int *wait, int *count, int len, int i);
void move_elements(t_push_swappa **a, t_push_swappa **b, t_push_swappa **tail_a, t_push_swappa **tail_b, int lentmp, int *wait, int first);
void rotate_a_if_needed(t_push_swappa **a, t_push_swappa **tail_a, int lentmp);
#endif
