/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monajjar <monajjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 15:17:10 by monajjar          #+#    #+#             */
/*   Updated: 2025/01/25 18:52:43 by monajjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**split_arguments(int ac, char **av, t_stack **stack)
{
	char	*numbers;
	char	**split;

	numbers = get_args(ac, av);
	if (!numbers)
	{
		free_stack(stack);
		write(2, "Error\n", ft_strlen("Error\n"));
		exit(EXIT_FAILURE);
	}
	split = ft_split(numbers, ' ');
	free(numbers);
	if (!split || *split == NULL)
	{
		free_split(split);
		free_stack(stack);
		write(2, "Error\n", ft_strlen("Error\n"));
		exit (EXIT_FAILURE);
	}
	return (split);
}

static void	valid_push(t_stack **stack_a, char **split)
{
	int	i;
	int	value;

	i = 0;
	while (split[i])
	{
		if (!is_valid_number(split[i])
			|| check_max(ft_atoi(split[i], stack_a, split)))
			ft_error(stack_a, split);
		value = ft_atoi(split[i], stack_a, split);
		if (is_duplicate(stack_a, value))
			ft_error(stack_a, split);
		push(stack_a, value);
		i++;
	}
}

void	parse_args(int ac, char **av, t_stack **stack_a)
{
	char	**split;

	split = split_arguments(ac, av, stack_a);
	valid_push(stack_a, split);
	free_split(split);
}
