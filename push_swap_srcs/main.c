/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 17:07:47 by tmatis            #+#    #+#             */
/*   Updated: 2021/03/15 16:07:41 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_3(t_stack *a, t_stack *b)
{
	if (a->len == 3 && a->table[0] < a->table[1] && a->table[0] < a->table[2]
			&& a->table[1] > a->table[2])
	{
		ft_sa(a, b);
		ft_putstr("sa\n");
	}
	if (a->len == 3 && a->table[0] < a->table[1] && a->table[0] > a->table[2])
	{
		ft_rra(a, b);
		ft_putstr("rra\n");
	}
	if (a->len == 3 && a->table[0] > a->table[2])
	{
		ft_ra(a, b);
		ft_putstr("ra\n");
	}
	if (a->table[0] > a->table[1])
	{
		ft_sa(a, b);
		ft_putstr("sa\n");
	}
}

static	void	sort_stack(t_stack *a, t_stack *b)
{
	if (a->len <= 5)
	{
		if (a->len > 3)
		{
			if (a->len == 5)
			{
				ft_pb(a, b);
				ft_putstr("pb\n");
			}
			ft_pb(a, b);
			ft_putstr("pb\n");
		}
		sort_stack_3(a, b);
		while (b->len)
			insert_sorted(a, b, b->table[0]);
		rot_to_a(a, get_min(a));
	}
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
