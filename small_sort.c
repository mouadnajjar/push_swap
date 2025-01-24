/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monajjar <monajjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:32:53 by monajjar          #+#    #+#             */
/*   Updated: 2025/01/17 17:54:10 by monajjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort2(t_stack **stack)
{
	if ((*stack)->top->data > (*stack)->top->next->data)
	{
		swap(stack, "sa\n");
		return (1);
	}
	return (0);
}

int	sort3(t_stack **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->top->data;
	b = (*stack)->top->next->data;
	c = (*stack)->top->next->next->data;
	if (a > b && b < c && a < c)
		swap(stack, "sa\n");
	else if (a > b && b < c && a > c)
		rotate(stack, "ra\n");
	else if (a > b && b > c)
	{
		swap(stack, "sa\n");
		rev_rot(stack, "rra\n");
	}
	else if (a < b && a < c && b > c)
	{
		swap(stack, "sa\n");
		rotate(stack, "ra\n");
	}
	else if (a < b && b > c)
		rev_rot(stack, "rra\n");
	return (1);
}

int	sort4(t_stack **stack_a, t_stack **stack_b)
{
	bring_top(stack_a);
	push_to_stack(stack_a, stack_b, "pb\n");
	if (check_sort(stack_a) == 0)
		sort3(stack_a);
	push_to_stack(stack_b, stack_a, "pa\n");
	return (1);
}

int	sort5(t_stack **stack_a, t_stack **stack_b)
{
	bring_top(stack_a);
	push_to_stack(stack_a, stack_b, "pb\n");
	bring_top(stack_a);
	push_to_stack(stack_a, stack_b, "pb\n");
	if (check_sort(stack_a) == 0)
		sort3(stack_a);
	push_to_stack(stack_b, stack_a, "pa\n");
	push_to_stack(stack_b, stack_a, "pa\n");
	return (1);
}
