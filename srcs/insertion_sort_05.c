/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   insertion_sort_05.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/21 15:02:35 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/25 13:04:20 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

static void			isort_smoothen_a(t_insert *in)
{
	size_t key;

	if (in->queue_a->size == 0)
		return ;
	key = ((t_stack_node*)(in->queue_a->head->value))->key;
	if (key == in->stack_a->size - 1)
		return ;
	else if (key >= in->stack_a->size / 2)
	{
		rotate(in->stack_a);
		enqueue(in->op, ft_strdup("ra"));
		isort_smoothen_a(in);
	}
	else
	{
		rotate_reverse(in->stack_a);
		enqueue(in->op, ft_strdup("rra"));
		isort_smoothen_a(in);
	}
}

static void			isort_smoothen_b(t_insert *in)
{
	size_t key;

	if (in->queue_b->size == 0)
		return ;
	key = ((t_stack_node*)(in->queue_b->head->value))->key;
	if (key == in->stack_b->size - 1)
		return ;
	else if (key >= in->stack_b->size / 2)
	{
		rotate(in->stack_b);
		enqueue(in->op, ft_strdup("rb"));
		isort_smoothen_b(in);
	}
	else
	{
		rotate_reverse(in->stack_b);
		enqueue(in->op, ft_strdup("rrb"));
		isort_smoothen_b(in);
	}
}

void				isort_smoothen(t_insert *in, t_stack *stack)
{
	if (stack == in->stack_a)
		isort_smoothen_a(in);
	else
		isort_smoothen_b(in);
}

t_insert			*init_insert(t_stack *stack_a, t_stack *stack_b,
		t_queue *op)
{
	t_insert		*in;

	if (!(in = ft_memalloc(sizeof(t_insert))))
		return (NULL);
	in->stack_a = (stack_a) ? stack_a : NULL;
	in->stack_b = (stack_b) ? stack_b : NULL;
	in->queue_a = (stack_a) ? queue_create() : NULL;
	in->queue_b = (stack_b) ? queue_create() : NULL;
	in->op = (op) ? op : queue_create();
	if (!in->op || (!in->stack_a && !in->stack_b)
		|| (!in->queue_a && !in->queue_b))
	{
		insert_flush(in);
		return (NULL);
	}
	return (in);
}

t_insert			*insertion_sort(t_insert *in, t_stack *stack)
{
	t_stack_node	*snode;

	snode = insertion_sandbox(in, stack);
	isort_master(in, stack, snode);
	isort_smoothen(in, stack);
	return (in);
}
