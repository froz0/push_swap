/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:04:19 by tmatis            #+#    #+#             */
/*   Updated: 2021/03/12 12:29:53 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H

# define CHECKER_H

# include "../libft/libft.h"
# include "../shared_srcs/shared.h"

t_bool			do_instruction(char *inst, t_stack *stack_a, t_stack *stack_b);

#endif
