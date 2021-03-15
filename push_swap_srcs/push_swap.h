/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 17:11:33 by tmatis            #+#    #+#             */
/*   Updated: 2021/03/15 23:32:07 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../shared_srcs/shared.h"

void	insertion_rot(t_stack *stack, t_stack *stack_b, int n);
int		get_rot_down(t_stack stack, int n);
int		get_rot_up(t_stack stack, int n);
int		get_min(t_stack *a);
int		get_max(t_stack *a);
int		get_upper(t_stack *a, int n);
t_bool	rot_to_a(t_stack *a, int n);
void	sort_under_6(t_stack *a, t_stack *b);

#endif
