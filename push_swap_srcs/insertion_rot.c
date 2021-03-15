/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_rot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 19:00:29 by tmatis            #+#    #+#             */
/*   Updated: 2021/03/15 20:44:13 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insertion_rot(t_stack *stack, t_stack *stack_b, int n)
{
	int	result_up;
	int	result_down;
	int	result;

	result_up = get_rot_up(*stack, n);
	result_down = get_rot_down(*stack, n);
	if (result_up == stack->len || result_down == stack->len)
		result = 0;
	else if (result_up < result_down)
		result = result_up;
	else
		result = result_down;
	while (result--)
	{
		if (result_up < result_down)
			do_instruction("ra", stack, stack_b, false);
		else
			do_instruction("rra", stack, stack_b, false);
	}
	do_instruction("pa", stack, stack_b, false);
}

