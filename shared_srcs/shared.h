/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:27:00 by tmatis            #+#    #+#             */
/*   Updated: 2021/03/15 18:51:45 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARED_H

# define SHARED_H

# include "../libft/libft.h"
typedef	struct	s_stack
{
	int			*table;
	int			len;
}				t_stack;

t_bool			do_instruction(char *inst, t_stack *stack_a, t_stack *stack_b,
		t_bool mute);
void			display_stacks(t_stack a, t_stack b);
t_stack			parse_args(int ac, char **av, int *error);
void			ft_sa(t_stack *stack_a, t_stack *stack_b);
void			ft_sb(t_stack *stack_a, t_stack *stack_b);
void			ft_ss(t_stack *stack_a, t_stack *stack_b);
void			ft_pa(t_stack *stack_a, t_stack *stack_b);
void			ft_pb(t_stack *stack_a, t_stack *stack_b);
void			ft_ra(t_stack *stack_a, t_stack *stack_b);
void			ft_rb(t_stack *stack_a, t_stack *stack_b);
void			ft_rra(t_stack *stack_a, t_stack *stack_b);
void			ft_rrb(t_stack *stack_a, t_stack *stack_b);
void			ft_rrr(t_stack *stack_a, t_stack *stack_b);
void			ft_swap(int *a, int *b);
t_stack			create_stack(int len);
t_bool			is_sorted(t_stack stack);
#endif
