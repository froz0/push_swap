/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 17:07:47 by tmatis            #+#    #+#             */
/*   Updated: 2021/03/13 15:08:14 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	sort_stack(t_stack *a, t_stack *b)//changer pour un algo recurcif
{
	if (a->len == 3 && a->table[0] < a->table[1] && a->table[0] < a->table[2]
			&& a->table[1] > a->table[2])
	{
		ft_sa(a, b);
		ft_putstr("sa\n");
		ft_ra(a, b);
		ft_putstr("ra\n");
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
		if (a.len > 1)
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
