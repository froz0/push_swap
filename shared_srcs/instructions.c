/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 19:17:58 by tmatis            #+#    #+#             */
/*   Updated: 2021/03/12 12:32:32 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

void	ft_sa(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_b;
	if (stack_a->len >= 2)
		ft_swap(&stack_a->table[0], &stack_a->table[1]);
}

void	ft_sb(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_a;
	if (stack_b->len >= 2)
		ft_swap(&stack_b->table[0], &stack_b->table[1]);
}

void	ft_ss(t_stack *stack_a, t_stack *stack_b)
{
	ft_sa(stack_a, stack_b);
	ft_sb(stack_a, stack_b);
}

void	ft_pa(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	if (stack_b->len > 0)
	{
		i = stack_a->len;
		while (i--)
			stack_a->table[i + 1] = stack_a->table[i];
		stack_a->table[0] = stack_b->table[0];
		stack_a->len++;
		i = 1;
		while (i < stack_b->len)
		{
			stack_b->table[i - 1] = stack_b->table[i];
			i++;
		}
		stack_b->len--;
	}
}

void	ft_pb(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	if (stack_a->len > 0)
	{
		i = stack_b->len;
		while (i--)
			stack_b->table[i + 1] = stack_b->table[i];
		stack_b->table[0] = stack_a->table[0];
		stack_b->len++;
		i = 1;
		while (i < stack_a->len)
		{
			stack_a->table[i - 1] = stack_a->table[i];
			i++;
		}
		stack_a->len--;
	}
}
