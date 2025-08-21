

#include "push_swap.h"

int find_max(t_node *stack)
{
	int max;

	max = INT_MIN;
	while (stack)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

int find_min(t_node *stack)
{
	int min;

	min = INT_MAX;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);	
}

int max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}