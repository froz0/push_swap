/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 17:07:47 by tmatis            #+#    #+#             */
/*   Updated: 2021/03/12 18:49:38 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	int		error;
	t_stack stack_a;
	t_stack	stack_b;

	error = 0;
	stack_a = parse_args(ac, av, &error);
	if (!error)
	{
		stack_b = create_stack(stack_a.len);
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
