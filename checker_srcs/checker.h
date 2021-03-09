/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:04:19 by tmatis            #+#    #+#             */
/*   Updated: 2021/03/09 18:34:50 by tmatis           ###   ########.fr       */
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

#endif
