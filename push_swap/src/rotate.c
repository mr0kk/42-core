/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmrok <rmrok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 22:14:49 by rmrok             #+#    #+#             */
/*   Updated: 2025/08/20 15:33:09 by rmrok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_node **stack)
{
	t_node	*tmp;
	t_node	*new_head;
	t_node	*new_tail;

	if (!(*stack) || get_stack_size(*stack) < 2)
		return ;
	new_head = (*stack)->next;
	new_tail = *stack;
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	new_tail->prev = tmp;
	new_tail->next = NULL;
	tmp->next = new_tail;
	new_head->prev = NULL;
	*stack = new_head;
}

void	ra(t_node **stack)
{
	rotate(stack);
	ft_putstr("ra\n");
}

void	rb(t_node **stack)
{
	rotate(stack);
	ft_putstr("rb\n");
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr("rr\n");
}

