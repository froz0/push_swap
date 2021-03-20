/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:10:31 by tmatis            #+#    #+#             */
/*   Updated: 2021/03/20 14:28:49 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static	int		wait_instruction(t_stack *stack_a, t_stack *stack_b)
{
	char	*inst;

	while (ft_gnl(STDIN_FILENO, &inst))
	{
		if (!do_instruction(inst, stack_a, stack_b, true))
			ft_putstr_fd("Error\n", 2);
		free(inst);
	}
	return (0);
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
		ft_putstr_fd("Error\n", 2);
}
