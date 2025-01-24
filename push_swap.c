/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monajjar <monajjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 11:39:18 by monajjar          #+#    #+#             */
/*   Updated: 2025/01/23 10:29:37 by monajjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack **stack)
{
	t_node	*current;

	current = (*stack)->top;
	printf("stack A: \n");
	while (current)
	{
		printf("---> %d\n", current->data);
		current = current->next;
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		exit (0);
	init_stack(&stack_a);
	parse_args(ac, av, &stack_a);
	init_stack(&stack_b);
	if (check_sort(&stack_a) == 0)
	{
		sort(&stack_a, &stack_b);
	}
	free_stack(&stack_a);
	free_stack(&stack_b);
}
