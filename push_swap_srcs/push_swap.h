/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 17:11:33 by tmatis            #+#    #+#             */
/*   Updated: 2021/03/19 15:45:29 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../shared_srcs/shared.h"

void	insertion_rot(t_stack *stack, t_stack *stack_b, int n);
void	sort_100(t_stack *a, t_stack *b);
void	sort_500(t_stack *a, t_stack *b);
int		get_min(t_stack *a);
int		get_max(t_stack *a);
int		get_upper(t_stack *a, int n);
int		get_rot_up(t_stack *stack, int n);
int		get_rot_down(t_stack *stack, int n);
void	rot_to_a(t_stack *a, int n);
void	rot_to_b(t_stack *a, int n);
void	sort_under_6(t_stack *a, t_stack *b);
void	insersion_sort(t_stack *a, t_stack *b);
int		get_wanted_index(t_stack *a, t_stack *b, int n);
#endif
