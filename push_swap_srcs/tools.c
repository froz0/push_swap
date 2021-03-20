/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 15:56:33 by tmatis            #+#    #+#             */
/*   Updated: 2021/03/20 14:11:11 by tmatis           ###   ########.fr       */
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

int				get_max(t_stack *a)
{
	int i;
	int	tmp;

	i = 0;
	tmp = a->table[0];
	while (i < a->len)
	{
		if (a->table[i] > tmp)
			tmp = a->table[i];
		i++;
	}
	return (tmp);
}

int				get_upper(t_stack *a, int n)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	while (i < a->len)
	{
		if (a->table[i] > n)
		{
			tmp = a->table[i];
			break ;
		}
		i++;
	}
	while (i < a->len)
	{
		if (a->table[i] < tmp && a->table[i] > n)
			tmp = a->table[i];
		i++;
	}
	return (tmp);
}

int				get_lower(t_stack *a, int n)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	while (i < a->len)
	{
		if (a->table[i] < n)
		{
			tmp = a->table[i];
			break ;
		}
		i++;
	}
	while (i < a->len)
	{
		if (a->table[i] > tmp && a->table[i] < n)
			tmp = a->table[i];
		i++;
	}
	return (tmp);
}

int				get_wanted_index(t_stack *a, t_stack *b, int n)
{
	int	i;
	int	counter;

	counter = 0;
	i = -1;
	while (++i < a->len)
	{
		if (a->table[i] < n)
			counter++;
	}
	i = -1;
	while (++i < b->len)
	{
		if (b->table[i] < n)
			counter++;
	}
	return (counter);
}
