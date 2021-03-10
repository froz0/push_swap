/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:04:19 by tmatis            #+#    #+#             */
/*   Updated: 2021/03/10 13:27:33 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H

# define CHECKER_H

# include "../libft/libft.h"


typedef	struct	s_stack
{
	int		*table;
	int		len;
}				t_stack;

t_stack			parse_args(int ac, char **av, int *error);
t_bool			do_instruction(char *inst, t_stack stack_a, t_stack stack_b);
#endif
