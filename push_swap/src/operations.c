#include "push_swap.h"


void	swap(t_node *head)
{
	int	tmp;

	tmp = head->value;
	head->value = head->next->value;
	head->next->value = tmp;
}

void	ss(t_node *head_a, t_node *head_b)
{
	swap(head_a);
	swap(head_b);
}



