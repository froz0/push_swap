/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:10:31 by tmatis            #+#    #+#             */
/*   Updated: 2021/03/11 13:53:52 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static	t_stack	create_stack(int len)
{
	t_stack stack;

	stack.len = 0;
	stack.table = ft_calloc(len, sizeof(int));
	return (stack);
}

static	void	display_stack(t_stack stack)
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

static	int		wait_instruction(t_stack *stack_a, t_stack *stack_b)
{
	char	*inst;
	while (ft_gnl(STDIN_FILENO, &inst))
	{
		if (do_instruction(inst, stack_a, stack_b))
			ft_putstr("Error: unknow instruction\n");
		else
		{
			ft_putstr("Stack A: ");
			display_stack(*stack_a);
			ft_putstr("Stack B: ");
			display_stack(*stack_b);

		}
		free(inst);
	}
	return (0);
}

static	t_bool	is_sorted(t_stack stack)
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

int				main(int ac, char **av)
{
	int		error;
	t_stack stack_a;
	t_stack	stack_b;

	error = 0;
	stack_a = parse_args(ac, av, &error);
	if (!error)
	{
		stack_b = create_stack(stack_a.len);
		wait_instruction(&stack_a, &stack_b);
		if (is_sorted(stack_a) && !stack_b.len)
			ft_putstr("OK\n");
		else
			ft_putstr("KO\n");
		free(stack_a.table);
		free(stack_b.table);
	}
	else
	{
		ft_putstr("Error: ");
		ft_putnbr_fd(error, STDOUT_FILENO);
		ft_putstr(" :(\n");
		return (1);
	}
}
