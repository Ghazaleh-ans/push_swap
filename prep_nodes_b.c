#include "push_swap.h"

static void	set_target_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*a_node;
	t_stack_node	*target_node;
	long			best_index;

	while (b)
	{
		best_index = LONG_MAX; 
		a_node = a;
		while (a_node)
		{
			if (a_node->nbr > b->nbr && a_node->nbr < best_index)
			{
				best_index = a_node->nbr;
				target_node = a_node;
			}
			a_node = a_node->next;
		}
		if (best_index == LONG_MAX)
			b->target_node = find_min(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	prep_nodes_b(t_stack_node *a, t_stack_node *b)
{
	set_index_median(a);
	set_index_median(b);
	set_target_b(a, b);
}