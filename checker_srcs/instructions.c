/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 13:22:24 by tmatis            #+#    #+#             */
/*   Updated: 2021/03/10 13:34:16 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static	int	hash_index(char *str, char **str_table)
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

t_bool	do_instruction(char *inst, t_stack stack_a, t_stack stack_b)
{
	char	*inst_set[2];

	(void) stack_a;
	(void) stack_b;
	inst_set[0] = "sa";
	inst_set[1] = NULL;
	if (hash_index(inst, inst_set) != -1)
	{
	}
	else
		return (true);
	return (false);
}
