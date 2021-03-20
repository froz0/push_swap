/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 14:11:22 by tmatis            #+#    #+#             */
/*   Updated: 2021/03/20 17:36:21 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

void			display_stack(t_stack *stack, int index_a, int index_b,
		int log_level)
{
	int		i;

	if (log_level >= 2)
	{
		ft_putstr("|");
		i = 0;
		while (i < stack->len)
		{
			if ((i == index_a || i == index_b) && log_level >= 3)
				ft_putstr("\033[1;31m");
			ft_putnbr_fd(stack->table[i++], STDOUT_FILENO);
			ft_putstr("\033[0m");
			ft_putstr("|");
		}
		ft_putstr(" len: ");
		ft_putnbr_fd(stack->len, STDOUT_FILENO);
		ft_putstr("\n");
	}
}

t_bool			is_sorted(t_stack stack)
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

void			ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

t_stack			create_stack(int len)
{
	t_stack stack;

	stack.len = 0;
	stack.table = ft_calloc(len, sizeof(int));
	return (stack);
}
