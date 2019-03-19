/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   stack_02.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/12 16:21:58 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/25 19:56:56 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "stack.h"
#include "push_swap.h"

int				stack_size(t_stack *stack)
{
	return (stack->size);
}

t_stack			*stack_init(int argc, char *argv[])
{
	t_stack		*stack_a;
	int			i;
	intmax_t	data;

	stack_a = stack_create();
	i = argc - 1;
	while (i > 0)
	{
		if (!ft_strisnum(argv[i]))
			print_error();
		if ((data = ft_atoi2(argv[i])) < INT_MIN
			|| data > INT_MAX)
			print_error();
		if (!check_duplicates(stack_a, (int)data))
			print_error();
		stack_push(stack_a, (int)data);
		i--;
	}
	return (stack_a);
}

static t_stack	*stack_init2_sub(int argc, char *argv[])
{
	t_stack		*stack_a;
	int			i;
	intmax_t	data;

	stack_a = stack_create();
	i = argc - 1;
	while (i >= 0)
	{
		if (!ft_strisnum(argv[i]))
			print_error();
		if ((data = ft_atoi2(argv[i])) < INT_MIN
			|| data > INT_MAX)
			print_error();
		if (!check_duplicates(stack_a, (int)data))
			print_error();
		stack_push(stack_a, (int)data);
		i--;
	}
	return (stack_a);
}

t_stack			*stack_init2(char *argv[])
{
	char	**arg;
	char	*s;
	size_t	count;
	t_stack	*stack_a;

	arg = ft_strsplit(argv[1], ' ');
	count = 0;
	s = arg[count];
	while (s)
		s = arg[++count];
	stack_a = stack_init2_sub(count, arg);
	count = 0;
	s = arg[count];
	while (s)
	{
		free(s);
		s = arg[++count];
	}
	free(arg);
	return (stack_a);
}

t_stack			*stack_clone(t_stack *stack)
{
	t_stack			*clone;
	t_stack_node	*snode;

	if (!(clone = stack_create()))
		return (NULL);
	if (stack->size == 0)
		return (clone);
	snode = stack->bot;
	while (snode != stack->top)
	{
		stack_push(clone, snode->data);
		snode = snode->prev;
	}
	stack_push(clone, snode->data);
	return (clone);
}
