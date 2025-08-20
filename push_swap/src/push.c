/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmrok <rmrok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 22:14:54 by rmrok             #+#    #+#             */
/*   Updated: 2025/08/20 18:01:26 by rmrok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	push(t_node **src, t_node **dest)
{
	// printf("|-----\n in push\n");
	t_node	*tmp;

	if (!(*src))
		return ;

	tmp = (*src)->next;
	// printf("tmp: %d\n", tmp->value);
	(*src)->next = *dest;
	// printf("src: %d\n", (*src)->value);
	// printf("src next: %p\n", (*src)->next);
	if (*dest)
		(*dest)->prev = *src;
	*dest = *src;
	*src = tmp;
	(*src)->prev = NULL;
	// printf("en of push\n-----|\n");
}

void	pa(t_node **stack_a, t_node	**stack_b)
{
	push(stack_b, stack_a);
	ft_putstr("pa\n");
}

void	pb(t_node **stack_a, t_node	**stack_b)
{
	push(stack_a, stack_b);
	ft_putstr("pb\n");
}