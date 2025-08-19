/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmrok <rmrok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 17:46:55 by rmrok             #+#    #+#             */
/*   Updated: 2025/08/19 17:55:08 by rmrok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three(t_node **stack)
{
	int top;
	int mid;
	int bot;

	top = (*stack)->value;
	mid = (*stack)->next->value;
	bot = (*stack)->next->next->value;
	if (top < mid && mid > bot)
		if (top < bot)
		{
			sa(stack);
			ra(stack);
		}
		else
			rra(stack);
	else if (top > mid)
		if (mid > bot)
		{
			ra(stack);
			sa(stack);
		}
		else if (top < bot)
			sa(stack);
		else
			ra(stack);
}

void turk_algorithm(t_node **head_a, t_node **head_b)
{
	while (get_stack_size(*head_a) > 3)
		pb(head_a, head_b);
	sort_three(head_a);
}