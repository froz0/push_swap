/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 17:07:47 by tmatis            #+#    #+#             */
/*   Updated: 2021/03/15 18:55:33 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	sort_stack(t_stack *a, t_stack *b)
{
	if (a->len <= 5)
		sort_under_6(a, b);
}

int main(int ac, char **av)
{
	int		error;
	t_stack a;
	t_stack	b;

	error = 0;
	a = parse_args(ac, av, &error);
	if (!error)
	{
		b = create_stack(a.len);
		if (a.len > 1 && !is_sorted(a))
			sort_stack(&a, &b);
		free(a.table);
		free(b.table);
	}
	else
	{
		ft_putstr("Error: ");
		ft_putnbr_fd(error, STDOUT_FILENO);
		ft_putstr(" :(\n");
		return (1);
	}
}
