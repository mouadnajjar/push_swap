/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monajjar <monajjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:45:47 by monajjar          #+#    #+#             */
/*   Updated: 2025/01/17 17:35:20 by monajjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort(t_stack **a, t_stack **b)
{
	if (stack_size(a) == 2)
	{
		return (sort2(a));
	}
	else if (stack_size(a) == 3)
	{
		return (sort3(a));
	}
	else if (stack_size(a) == 4)
	{
		return (sort4(a, b));
	}
	else if (stack_size(a) == 5)
	{
		return (sort5(a, b));
	}
	else
		big_sort(a, b);
	return (1);
}
