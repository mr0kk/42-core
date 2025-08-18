/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmrok <rmrok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 13:51:13 by rmrok             #+#    #+#             */
/*   Updated: 2025/08/18 13:51:16 by rmrok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrotate(t_node **stack)
{
	t_node	*old_head;
	t_node	*new_head;

	if (!(*stack))
		return ;
	new_head = *stack;
	old_head = *stack;
	while (new_head->next)
		new_head = new_head->next;
	new_head->next = old_head;
	new_head->prev->next = NULL;
	new_head->prev = NULL;
	old_head->prev = new_head;
	*stack = new_head;	
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