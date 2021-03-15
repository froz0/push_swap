/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 18:41:46 by tmatis            #+#    #+#             */
/*   Updated: 2021/03/15 23:49:45 by tmatis           ###   ########.fr       */
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
		if (b->table[0] < get_min(a))
			rot_to_a(a, get_min(a));
		else if (b->table[0] > get_max(a))
			rot_to_a(a, get_min(a));
		else
			rot_to_a(a, get_upper(a, b->table[0]));
		do_instruction("pa", a, b, false);
	}
	rot_to_a(a, get_min(a));
}
