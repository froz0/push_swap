/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 17:11:33 by tmatis            #+#    #+#             */
/*   Updated: 2021/03/15 16:07:34 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../shared_srcs/shared.h"

void	insert_sorted(t_stack *stack, t_stack *stack_b, int n);
int		get_min(t_stack *a);
void	rot_to_a(t_stack *a, int n);
#endif
