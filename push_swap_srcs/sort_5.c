/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 18:41:46 by tmatis            #+#    #+#             */
/*   Updated: 2021/03/20 11:36:47 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_stack_3(t_stack *a, t_stack *b)
{
	if (a->len == 3 && a->table[0] < a->table[1] && a->table[0] < a->table[2]
			&& a->table[1] > a->table[2])
		process_instruction("sa", a, b);
	if (a->len == 3 && a->table[0] < a->table[1] && a->table[0] > a->table[2])
		process_instruction("rra", a, b);
	if (a->len == 3 && a->table[0] > a->table[2])
		process_instruction("ra", a, b);
	if (a->table[0] > a->table[1])
		process_instruction("sa", a, b);
}

void	sort_under_6(t_stack *a, t_stack *b)
{
	if (a->len > 3)
	{
		if (a->len == 5)
			process_instruction("pb", a, b);
		process_instruction("pb", a, b);
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
		process_instruction("pa", a, b);
	}
	rot_to_a(a, get_min(a));
}
