/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 18:49:21 by tmatis            #+#    #+#             */
/*   Updated: 2021/03/20 15:42:39 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

static t_bool	is_atoiable(char *str)
{
	while (*str)
	{
		if (!ft_isnum(*str) && *str != '-')
			return (false);
		str++;
	}
	return (true);
}

t_bool			is_integer(char *str)
{
	long	long	n;
	int				sign;

	if (!is_atoiable(str))
		return (false);
	n = 0;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && ft_isdigit(*str))
		n = n * 10 + ((*str++) - 48);
	n = n * sign;
	if (n > 2147483647 || n < -2147483648)
		return (false);
	return (true);
}

static	int		hash_index(char *str, char **str_table)
{
	int	i;

	i = 0;
	while (str_table[i])
	{
		if (ft_strcmp(str, str_table[i]) == 0)
			return (i);
		i++;
	}
	return (-1);
}

static	void	do_operation(int id, t_stack *stack_a, t_stack *stack_b)
{
	void	((*operation[11])(t_stack *stack_a, t_stack *stack_b));

	operation[0] = ft_sa;
	operation[1] = ft_sb;
	operation[2] = ft_ss;
	operation[3] = ft_pa;
	operation[4] = ft_pb;
	operation[5] = ft_ra;
	operation[6] = ft_rb;
	operation[7] = ft_rra;
	operation[8] = ft_rrb;
	operation[9] = ft_rrr;
	operation[10] = ft_rr;
	operation[id](stack_a, stack_b);
}

t_bool			do_instruction(char *inst, t_stack *stack_a, t_stack *stack_b,
		t_bool mute)
{
	char	*inst_set[12];
	int		index;

	inst_set[0] = "sa";
	inst_set[1] = "sb";
	inst_set[2] = "ss";
	inst_set[3] = "pa";
	inst_set[4] = "pb";
	inst_set[5] = "ra";
	inst_set[6] = "rb";
	inst_set[7] = "rra";
	inst_set[8] = "rrb";
	inst_set[9] = "rrr";
	inst_set[10] = "rr";
	inst_set[11] = NULL;
	index = hash_index(inst, inst_set);
	if (index != -1)
	{
		if (!mute)
			printf("%s\n", inst);
		do_operation(index, stack_a, stack_b);
		return (true);
	}
	else
		return (false);
}
