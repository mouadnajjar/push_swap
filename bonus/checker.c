/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monajjar <monajjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:26:44 by monajjar          #+#    #+#             */
/*   Updated: 2025/01/23 17:48:18 by monajjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "gnl/get_next_line.h"

void	error_check(char *op)
{
	write(1, "Error\n", 6);
	free(op);
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*operation;

	if (ac < 2)
		exit (0);
	init_stack(&stack_a);
	parse_args(ac, av, &stack_a);
	init_stack(&stack_b);
	operation = get_next_line(0);
	while (operation != NULL)
	{
		if ((valid_operations(operation, &stack_a, &stack_b)) == 0)
			error_check(operation);
		free(operation);
		operation = get_next_line(0);
	}
	if (check_sort(&stack_a) && is_empty(&stack_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&stack_a);
	free_stack(&stack_b);
}
