/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmrok <rmrok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 22:00:48 by rmrok             #+#    #+#             */
/*   Updated: 2025/08/21 22:28:16 by rmrok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_with_error(t_node **head_a, t_node **head_b)
{
	if (head_a && *head_a)
		free_stack(head_a);
	if (head_b && *head_b)
		free_stack(head_b);
	write(2, "Error\n", 6);
	exit(1);
}

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_sign(char c)
{
	return (c == '-' || c == '+');
}
