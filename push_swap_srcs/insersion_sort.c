/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insersion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 12:41:15 by tmatis            #+#    #+#             */
/*   Updated: 2021/03/20 11:37:01 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insersion_sort(t_stack *a, t_stack *b)
{
	while (a->len)
	{
		rot_to_a(a, get_min(a));
		process_instruction("pb", a, b);
	}
	while (b->len)
		process_instruction("pa", a, b);
}
