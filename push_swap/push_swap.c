#include "push_swap.h"

int		atoicheck(char **argv, int j)
{
	int			i;
	int			coefficient;
	long long	output;

	i = 0;
	output = 0;
	if (argv[j][i] == '-')
	{
		coefficient = -1;
		i++;
	}
	while (argv[j][i] == 48)
		i++;
	while (argv[j][i] >= 48 && argv[j][i] <= 57)
	{
		output = output * 10 + (argv[j][i] - '0');
		i++;
	}
	if (coefficient == -1)
		output = -output;
	if (output > 2147483647 || output < -2147483648)
		return (0);
	return (1);
}

int		valid(int argc, char **argv)
{
	int	i;
	int	j;
	int a;

	i = 0;
	j = 0;
	a = 0;
	while (j < argc)
	{
		while(argv[j][i] != '\0')
		{
			if (i == 0)
			{
				while(argv[j][i] == 48)
				{
					i++;
					a++;
				}
			}
			if (argv[j][i] <= 47 || argv[j][i] >= 58 || (i - a) > 10)
				return (0);
			if ((i - a) == 10 && atoicheck(argv, j) == 0)
				return (0);
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}

int		*atoi(int j, char **argv)
{
	int	i;
	int	coefficient;
	int	output;

	i = 0;
	output = 0;
	if (argv[j][i] == '-')
	{
		coefficient = -1;
		i++;
	}
	while (argv[j][i] == 48)
		i++;
	while (argv[j][i] >= 48 && argv[j][i] <= 57)
	{
		output = output * 10 + (argv[j][i] - '0');
		i++;
	}
	if (coefficient == -1)
		output = -output;
	return (output);
}

int		main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_stack		*new;
	int			*array;
	int			i;
	int			j;
	int			max;
	int			min;

	if (argc < 1)
		return (0);
	if (valid(argc, argv) == 0)
		return (0);
	j = 0;
	max = 0;
	min = 0;
	while (j < argc)
	{
		array[j] = atoi(j, argv);
		if (array[j] > max)
			max = array[j];
		if (array[j] < min)
			min = array[j];
		j++;
	}
	i = 0;
	a = NULL;
	a = (t_stack *) malloc(sizeof(t_stack));
	a->value = array[i];
	a->next = NULL;
	a->prev = NULL;
	b = (t_stack *) malloc(sizeof(t_stack));
	while (i < argc)
	{
		new = a;
		while (new->next != NULL)
		{
			new = new->next;
			if (new->prev == NULL)
			{
				new->prev = (t_stack *) malloc(sizeof(t_stack));
				new->prev = array[i - 1];
			}
		}
		new->next = (t_stack *) malloc(sizeof(t_stack));
		new->next->value = array[i];
		new->next->next = NULL;
		i++;
	}
	if (argc < 20)
	{
		func1();
	}
	else if (argc < 100)
	{
		func2();
	}
	else
	{
		func3();
	}
}
