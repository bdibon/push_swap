/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   insertion_sb_01.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/25 11:44:56 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/25 11:46:10 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

t_insert		*insert_clone(t_insert *in, t_stack *stack)
{
	t_insert	*in_clone;

	if (!(in_clone = ft_memalloc(sizeof(t_insert))))
		return (NULL);
	if (stack == in->stack_a)
	{
		in_clone->stack_a = stack_clone(in->stack_a);
		in_clone->queue_a = queue_create();
		in_clone->op = queue_create();
	}
	else
	{
		in_clone->stack_b = stack_clone(in->stack_b);
		in_clone->queue_b = queue_create();
		in_clone->op = queue_create();
	}
	return (in_clone);
}

void			insert_flush(t_insert *in)
{
	if (in->stack_a)
		stack_destroy(in->stack_a);
	if (in->stack_b)
		stack_destroy(in->stack_b);
	if (in->queue_a)
		queue_destroy(in->queue_a);
	if (in->queue_b)
		queue_destroy(in->queue_b);
	if (in->op)
		queue_clear_destroy(in->op);
	free(in);
}

void			insert_flush2(t_insert *in)
{
	if (in->stack_a)
		stack_destroy(in->stack_a);
	if (in->stack_b)
		stack_destroy(in->stack_b);
	if (in->queue_a)
		queue_destroy(in->queue_a);
	if (in->queue_b)
		queue_destroy(in->queue_b);
	free(in);
}

void			insertion_sandbox_try(t_insert *in, t_stack *stack, size_t key)
{
	t_stack_node	*snode;

	snode = stack->top;
	while (snode->key != key)
		snode = snode->next;
	isort_master(in, stack, snode);
	isort_smoothen(in, stack);
}
