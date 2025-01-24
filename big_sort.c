/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monajjar <monajjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:50:37 by monajjar          #+#    #+#             */
/*   Updated: 2025/01/17 16:56:44 by monajjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	range;

	range = 0;
	if (stack_size(stack_a) >= 6
		&& stack_size(stack_a) <= 20)
		range = 4;
	else if (stack_size(stack_a) <= 100)
		range = 15;
	else if (stack_size(stack_a) <= 500)
		range = 40;
	pre_sort(stack_a, stack_b, range);
	while ((*stack_b)->top)
	{
		big_to_top(stack_b);
		push_to_stack(stack_b, stack_a, "pa\n");
	}
}
