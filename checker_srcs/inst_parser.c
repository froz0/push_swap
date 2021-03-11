/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 13:22:24 by tmatis            #+#    #+#             */
/*   Updated: 2021/03/11 13:37:31 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void			ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static	void	do_operation(int id, t_stack *stack_a, t_stack *stack_b)
{
	void	((*operation[11])(t_stack *stack_a, t_stack *stack_b));

	operation[0] = ft_sa;
	operation[1] = ft_sb;
	operation[2] = ft_ss;
	operation[3] = ft_pa;
	operation[4] = ft_pb;
	operation[id](stack_a, stack_b);
}

t_bool			do_instruction(char *inst, t_stack *stack_a, t_stack *stack_b)
{
	char	*inst_set[11];
	int		index;

	inst_set[0] = "sa";
	inst_set[1] = "sb";
	inst_set[2] = "ss";
	inst_set[3] = "pa";
	inst_set[4] = "pb";
	inst_set[5] = NULL;
	index = hash_index(inst, inst_set);
	if (index != -1)
		do_operation(index, stack_a, stack_b);
	else
		return (true);
	return (false);
}
