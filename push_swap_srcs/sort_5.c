/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 18:41:46 by tmatis            #+#    #+#             */
/*   Updated: 2021/03/15 20:38:58 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_stack_3(t_stack *a, t_stack *b)
{
	if (a->len == 3 && a->table[0] < a->table[1] && a->table[0] < a->table[2]
			&& a->table[1] > a->table[2])
		do_instruction("sa", a, b, false);
	if (a->len == 3 && a->table[0] < a->table[1] && a->table[0] > a->table[2])
		do_instruction("rra", a, b, false);
	if (a->len == 3 && a->table[0] > a->table[2])
		do_instruction("ra", a, b, false);
	if (a->table[0] > a->table[1])
		do_instruction("sa", a, b, false);
}

void	sort_under_6(t_stack *a, t_stack *b)
{
	if (a->len > 3)
	{
		if (a->len == 5)
			do_instruction("pb", a, b, false);
		do_instruction("pb", a, b, false);
	}
	sort_stack_3(a, b);
	while (b->len)
	{
		printf("min over |%i|: %i\n", b->table[0], get_min_over(a, b->table[0]));
		insertion_rot(a, b, get_min_over(a, b->table[0]));
	}
	rot_to_a(a, get_min(a));
}
