/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:28:15 by tmatis            #+#    #+#             */
/*   Updated: 2021/03/15 12:19:31 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

void	ft_ra(t_stack *stack_a, t_stack *stack_b)
{
	int		tmp;
	int		i;

	(void)stack_b;
	if (stack_a->len >= 2)
	{
		tmp = stack_a->table[0];
		i = 1;
		while (i < stack_a->len)
		{
			stack_a->table[i - 1] = stack_a->table[i];
			i++;
		}
		stack_a->table[i - 1] = tmp;
	}
}

void	ft_rb(t_stack *stack_a, t_stack *stack_b)
{
	int		tmp;
	int		i;

	(void)stack_a;
	if (stack_b->len >= 2)
	{
		tmp = stack_b->table[0];
		i = 1;
		while (i < stack_b->len)
		{
			stack_b->table[i - 1] = stack_b->table[i];
			i++;
		}
		stack_b->table[i - 1] = tmp;
	}
}

void	ft_rr(t_stack *stack_a, t_stack *stack_b)
{
	ft_ra(stack_a, stack_b);
	ft_rb(stack_a, stack_b);
}

void		display_stack(t_stack stack)
{
	int		i;

	ft_putstr("|");
	i = 0;
	while (i < stack.len)
	{
		ft_putnbr_fd(stack.table[i++], STDOUT_FILENO);
		ft_putstr("|");
	}
	ft_putstr(" len: ");
	ft_putnbr_fd(stack.len, STDOUT_FILENO);
	ft_putstr("\n");
}

t_bool		is_sorted(t_stack stack)
{
	int	i;

	i = 1;
	while (i < stack.len)
	{
		if (stack.table[i - 1] > stack.table[i])
			return (false);
		i++;
	}
	return (true);
}

