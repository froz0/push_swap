/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:10:31 by tmatis            #+#    #+#             */
/*   Updated: 2021/03/09 19:21:09 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		main(int ac, char **av)
{
	int		error;
	int		i;
	t_stack stack;

	error = 0;
	stack = parse_args(ac, av, &error);
	if (!error)
	{
		i = 0;
		while (i < stack.len)
		{
			printf("%i: %i\n",i , stack.table[i]);
			i++;
		}
		free(stack.table);
	}
	else
		printf("error no: %i\n", error);
}
