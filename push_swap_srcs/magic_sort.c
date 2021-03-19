/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 23:05:17 by tmatis            #+#    #+#             */
/*   Updated: 2021/03/19 15:45:15 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_best_number(t_stack *a, int n0, int n1)
{
	int	n0_champ;
	int	rot_down_n0;
	int	n1_champ;
	int	rot_down_n1;

	n0_champ = get_rot_up(a, n0);
	n1_champ = get_rot_up(a, n1);
	rot_down_n0 = get_rot_down(a, n0);
	rot_down_n1 = get_rot_down(a, n1);
	if (n0_champ > rot_down_n0)
		n0_champ = rot_down_n0;
	if (n1_champ > rot_down_n1)
		n1_champ = rot_down_n1;
	if (n0_champ > n1_champ)
		return (n1);
	else
		return (n0);
}

int get_chunk_hold(t_stack *a, t_stack *b, int index_max)
{
	int	i;
	int	hold_first;
	int	hold_last;

	hold_first = 0;
	hold_last = 0;
	i = -1;
	while (++i < a->len)
	{
		if (get_wanted_index(a, b, a->table[i]) < index_max)
		{
			hold_first = a->table[i];
			break;
		}
	}
	i = a->len;
	while (i--)
	{
		if (get_wanted_index(a, b, a->table[i]) < index_max)
		{
			hold_last = a->table[i];
			break;
		}
	}
	return (get_best_number(a, hold_first, hold_last));
}

void		sort_chunk(t_stack *a, t_stack *b, int index_max)
{
	while (b->len != index_max)
	{
		rot_to_a(a, get_chunk_hold(a, b, index_max));
		if (a->table[0] < get_min(b) || a->table[0] > get_max(b))
			rot_to_b(b, get_min(b));
		else
			rot_to_b(b, get_upper(b, a->table[0]));
		do_instruction("pb", a, b, false);
	}
}

void		sort_100(t_stack *a, t_stack *b)
{
	sort_chunk(a, b, 20);
	sort_chunk(a, b, 40);
	sort_chunk(a, b, 60);
	sort_chunk(a, b, 80);
	sort_chunk(a, b, 100);
	while (b->len)
	{
		rot_to_b(b, get_max(b));
		do_instruction("pa", a, b, false);
	}
}

void	sort_500(t_stack *a, t_stack *b)
{
	sort_chunk(a, b, 45);
	sort_chunk(a, b, 90);
	sort_chunk(a, b, 135);
	sort_chunk(a, b, 180);
	sort_chunk(a, b, 225);
	sort_chunk(a, b, 270);
	sort_chunk(a, b, 315);
	sort_chunk(a, b, 360);
	sort_chunk(a, b, 405);
	sort_chunk(a, b, 450);
	sort_chunk(a, b, 500);
	while (b->len)
	{
		rot_to_b(b, get_max(b));
		do_instruction("pa", a, b, false);
	}
}
