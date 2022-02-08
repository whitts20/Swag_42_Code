#include "push_swap.h"

int	main(void)
{
	t_stack		*head;
	int			**array;
	int			i;

	head = NULL;
	array = (int **) malloc(sizeof(int *) * 20);
	i = 0;
	while (i < 20)
	{
		array[i] = (int *) malloc(sizeof(int) * 4);
		array[i][0] = i + 1;
		i++;
	}
	head = (t_stack *) malloc(sizeof(t_stack));
	head->value = array[i][0];
	head->next = NULL;
	head->prev = NULL;
}
