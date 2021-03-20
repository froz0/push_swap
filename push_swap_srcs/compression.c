/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compression.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 23:28:00 by tmatis            #+#    #+#             */
/*   Updated: 2021/03/20 11:43:39 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	clear_buff(int *count_ra, int *count_rb, t_bool dir)
{
	while (*count_ra && *count_rb)
	{
		if (dir)
			ft_putstr("rr\n");
		else
			ft_putstr("rrr\n");
		(*count_ra)--;
		(*count_rb)--;
	}
	while (*count_ra)
	{
		if (dir)
			ft_putstr("ra\n");
		else
			ft_putstr("rra\n");
		(*count_ra)--;
	}
	while (*count_rb)
	{
		if (dir)
			ft_putstr("rb\n");
		else
			ft_putstr("rrb\n");
		(*count_rb)--;
	}
}
static	t_bool	get_direction(char *inst)
{
	return (inst[1] != 'r');
}

void	process_instruction(char *inst, t_stack *a, t_stack *b)
{
	static	t_bool	dir = true;
	static	int		count_ra = 0;
	static	int		count_rb = 0;

	if (inst[0] == 'r')
	{
		if (get_direction(inst) != dir)
		{
			clear_buff(&count_ra, &count_rb, dir);
			dir = get_direction(inst);
		}
		if (inst[1] == 'a' || inst[2] == 'a')
			count_ra++;
		else
			count_rb++;
		do_instruction(inst, a, b, true);
	}
	else
	{
		clear_buff(&count_ra, &count_rb, dir);
		do_instruction(inst, a, b, false);
	}
}
