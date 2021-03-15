/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 15:56:33 by tmatis            #+#    #+#             */
/*   Updated: 2021/03/15 16:10:32 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int		get_insertion_up(t_stack stack, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack.len)
	{
		if (stack.table[0] > n)
			break ;
		ft_ra(&stack, &stack);
		i++;
	}
	j = 0;
	while (j < i)
	{
		ft_rra(&stack, &stack);
		j++;
	}
	return (i);
}

static	int		get_insertion_down(t_stack stack, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack.len)
	{
		if (stack.table[0] > n)
			break ;
		ft_rra(&stack, &stack);
		i++;
	}
	j = 0;
	while (j < i)
	{
		ft_ra(&stack, &stack);
		j++;
	}
	return (i);
}

void	insert_sorted(t_stack *stack, t_stack *stack_b, int n)
{
	int	result_up;
	int	result_down;
	int	result;

	result_up = get_insertion_up(*stack, n);
	result_down = get_insertion_down(*stack, n);

	//printf("up: %i\ndown: %i\n", result_up, result_down);
	if (result_up == stack->len || result_down == stack->len)
		result = 0;
	else if (result_up <= result_down)
		result = result_up;
	else
		result = result_down;
	while (result--)
	{
		if (result_up <= result_down)
		{
			ft_ra(stack, stack);
			ft_putstr("ra\n");
		}
		else
		{
			ft_rra(stack, stack);
			ft_putstr("rra\n");
		}
	}
	ft_pa(stack, stack_b);
	ft_putstr("pa\n");
}

int				get_min(t_stack *a)
{
	int i;
	int	tmp;

	i = 0;
	tmp = a->table[0];
	while (i < a->len)
	{
		if (a->table[i] < tmp)
			tmp = a->table[i];
		i++;
	}
	return (tmp);
}

