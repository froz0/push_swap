/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 19:17:58 by tmatis            #+#    #+#             */
/*   Updated: 2021/03/10 19:39:09 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_sa(t_stack stack_a, t_stack stack_b)
{
	(void)stack_b;
	if (stack_a.len >= 2)
		ft_swap(&stack_a.table[0], &stack_a.table[1]);
}
