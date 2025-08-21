/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmrok <rmrok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 13:51:13 by rmrok             #+#    #+#             */
/*   Updated: 2025/08/21 21:53:23 by rmrok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrotate(t_node **stack)
{
	t_node	*last;
	t_node	*second_last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = *stack;
	while (last->next)
		last = last->next;
	second_last = last->prev;
	second_last->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
}

void	rra(t_node **stack)
{
	rrotate(stack);
	ft_putstr("rra\n");
}

void	rrb(t_node **stack)
{
	rrotate(stack);
	ft_putstr("rrb\n");
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	rrotate(stack_a);
	rrotate(stack_b);
	ft_putstr("rrr\n");
}
