#include "push_swap.h"

static char	**free_array(char **ptr, int i)
{
	while (i > 0)
	{
		i--;
		free(ptr[i]);
	}
	free(ptr);
	return (0);
}

int	main(int argc, char **argv)
{
	char			**inputs;
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	inputs = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
	{
		inputs = ft_split(argv[1], ' ');
		init_a_stack(&a, inputs);
		free_array(inputs, stack_len(a));
	}
	else
		init_a_stack(&a, argv + 1);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	free_stack(&a);
	return (0);
}
