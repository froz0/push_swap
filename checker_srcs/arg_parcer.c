/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parcer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 12:43:43 by tmatis            #+#    #+#             */
/*   Updated: 2021/03/09 22:50:30 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static t_bool	is_atoiable(char *str)
{
	while (*str)
	{
		if (!ft_isnum(*str) && *str != '-')
			return (false);
		str++;
	}
	return (true);
}

static int		check_args(int ac, char **av)
{
	int		i;
	int		j;
	char	**nums;
	int		len;

	i = 1;
	len = 0;
	while (i < ac)
	{
		nums = ft_split(av[i], ' ');
		j = 0;
		while (nums[j])
		{
			if (is_atoiable(nums[j]))
				len++;
			else
				return (-1);
			free(nums[j]);
			j++;
		}
		free(nums);
		i++;
	}
	return (len);
}

static int		*create_table(int ac, char **av, int len)
{
	int		i;
	int		j;
	char	**nums;
	int		*dst;
	int		index;

	dst = malloc(len * sizeof(int));
	if (!dst)
		return (NULL);
	i = 1;
	index = 0;
	while (i < ac)
	{
		j = 0;
		nums = ft_split(av[i], ' ');
		while (nums[j])
		{
			dst[index++] = ft_atoi(nums[j]);
			free(nums[j++]);
		}
		free(nums);
		i++;
	}
	return (dst);
}

t_stack			parse_args(int ac, char **av, int *error)
{
	t_stack		stack;

	stack.len = 0;
	if (ac >= 2)
	{
		stack.len = check_args(ac, av);
		if (stack.len == -1)
			*error = 2;
		else
			stack.table = create_table(ac, av, stack.len);
	}
	else
	{
		ft_putstr("Usage : ./checker 0 1 2 3 4 5 6\n");
		*error = 1;
	}
	return (stack);
}
