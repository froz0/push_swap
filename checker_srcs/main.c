/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:10:31 by tmatis            #+#    #+#             */
/*   Updated: 2021/03/10 13:36:03 by tmatis           ###   ########.fr       */
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

static	 int	wait_instruction(t_stack stack_a, t_stack stack_b)
{
	char	*inst;
	while (ft_gnl(STDIN_FILENO, &inst))
	{
		if (do_instruction(inst, stack_a, stack_b))
			ft_putstr("Error: unknow instruction\n");
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
		wait_instruction(stack_a, stack_b);
		free(stack_a.table);
		free(stack_b.table);
	}
	else
		return (1);
}
