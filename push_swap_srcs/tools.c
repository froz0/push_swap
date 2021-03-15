/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 15:56:33 by tmatis            #+#    #+#             */
/*   Updated: 2021/03/15 20:26:06 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				get_min(t_stack *a)
{
	int i;
	int	tmp;

	i = 0;
	tmp = a->table[0];
	while (i < a->len)
	{
		if (a->table[i] < tmp)
			tmp = a->table[i];
		i++;
	}
	return (tmp);
}

int				get_min_over(t_stack *a, int n)
{
	int i;
	int	tmp;

	i = 0;
	tmp = a->table[0];
	while (i < a->len)
	{
		if (a->table[i] > tmp && tmp < n)
			tmp = a->table[i];
		i++;
	}
	return (tmp);
}
