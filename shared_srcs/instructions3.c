/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 19:36:22 by tmatis            #+#    #+#             */
/*   Updated: 2021/03/16 13:15:06 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

void	ft_rra(t_stack *stack_a, t_stack *stack_b)
{
	int		tmp;
	int		i;

	(void)stack_b;
	if (stack_a->len >= 2)
	{
		tmp = stack_a->table[stack_a->len - 1];
		i = stack_a->len - 1;
		while (i--)
			stack_a->table[i + 1] = stack_a->table[i];
		stack_a->table[0] = tmp;
	}
}

void	ft_rrb(t_stack *stack_a, t_stack *stack_b)
{
	int		tmp;
	int		i;

	(void)stack_a;
	if (stack_b->len >= 2)
	{
		tmp = stack_b->table[stack_b->len - 1];
		i = stack_b->len - 1;
		while (i--)
			stack_b->table[i + 1] = stack_b->table[i];
		stack_b->table[0] = tmp;
	}
}

void	ft_rrr(t_stack *stack_a, t_stack *stack_b)
{
	ft_rra(stack_a, stack_b);
	ft_rrb(stack_a, stack_b);
}
