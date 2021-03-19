/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compression.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 23:28:00 by tmatis            #+#    #+#             */
/*   Updated: 2021/03/19 23:51:47 by tmatis           ###   ########.fr       */
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
	while ((*count_ra)--)
	{
		if (dir)
			ft_putstr("ra\n");
		else
			ft_putstr("rra\n");
	}
	while ((*count_rb)--)
	{
		if (dir)
			ft_putstr("rb\n");
		else
			ft_putstr("rrb\n");
	}
}

void	process_instruction(char *inst, t_stack *a, t_stack *b)
{
	static	t_bool	dir = true;
	static	int		count_ra = 0;
	static	int		count_rb = 0;

	if (inst[0] == 'r')
	{

	}
	else
	{
		clear_buff(&count_ra, &count_rb, dir);
		do_instruction(inst, a, b, false);
	}
}
