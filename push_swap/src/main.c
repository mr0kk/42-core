/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmrok <rmrok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 00:05:37 by rmrok             #+#    #+#             */
/*   Updated: 2025/07/26 00:05:38 by rmrok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// t_node	*read_input(int argc, char *argv[])
// {

// }

void	exit_with_error(t_node **head_a, t_node **head_b)
{
	
	write(2, "Error\n", 6);
	exit(1);
}

int	main(int argc, char *argv[])
{

	t_node	*head_a;
	t_node	*head_b;
	int		i;
	unsigned int	words;

	if (argc < 2)
		return (0);
	if (!valid_input(argc, argv))
		exit_with_error(NULL, NULL);
		ft_printf("git\n");
	i = 1;
	head_b = NULL;
	// head_a = read_input(argc, argv);

}