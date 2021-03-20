/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_to.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:02:19 by tmatis            #+#    #+#             */
/*   Updated: 2021/03/20 16:26:54 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			get_rot_up(t_stack *stack, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->len)
	{
		if (stack->table[0] == n)
			break ;
		ft_ra(stack, stack, 0);
		i++;
	}
	j = 0;
	while (j < i)
	{
		ft_rra(stack, stack, 0);
		j++;
	}
	return (i);
}

int			get_rot_down(t_stack *stack, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->len)
	{
		if (stack->table[0] == n)
			break ;
		ft_rra(stack, stack, 0);
		i++;
	}
	j = 0;
	while (j < i)
	{
		ft_ra(stack, stack, 0);
		j++;
	}
	return (i);
}

void		rot_to_a(t_stack *a, int n)
{
	int	result_up;
	int	result_down;
	int	result;

	result_up = get_rot_up(a, n);
	result_down = get_rot_down(a, n);
	if (result_up == a->len || result_down == a->len)
		result = 0;
	else if (result_up <= result_down)
		result = result_up;
	else
		result = result_down;
	while (result--)
	{
		if (result_up <= result_down)
			process_instruction("ra", a, a, false);
		else
			process_instruction("rra", a, a, false);
	}
}

void		rot_to_b(t_stack *a, int n)
{
	int	result_up;
	int	result_down;
	int	result;

	result_up = get_rot_up(a, n);
	result_down = get_rot_down(a, n);
	if (result_up == a->len || result_down == a->len)
		result = 0;
	else if (result_up <= result_down)
		result = result_up;
	else
		result = result_down;
	while (result--)
	{
		if (result_up <= result_down)
			process_instruction("rb", a, a, false);
		else
			process_instruction("rrb", a, a, false);
	}
}
