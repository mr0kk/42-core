/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmrok <rmrok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 21:58:54 by rmrok             #+#    #+#             */
/*   Updated: 2025/08/19 22:48:49 by rmrok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node **stack)
{
	t_node *first;
    t_node *second;

	if (!stack || !(*stack )|| !(*stack)->next)
		return ;
	first = *stack;
    second = first->next;
    first->next = second->next;
    second->next = first;
    second->prev = first->prev;
    first->prev = second;
    if (first->next)
        first->next->prev = first;
    *stack = second;
	(*stack)->prev = NULL;
}

void sa(t_node **stack_a)
{
	swap(stack_a);
	ft_putstr("sa\n");
}

void sb(t_node **stack_b)
{
	swap(stack_b);
	ft_putstr("sb\n");
}

void ss(t_node **stack_a, t_node **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putstr("ss\n");
}
