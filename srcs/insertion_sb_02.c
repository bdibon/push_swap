/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   insertion_sb_02.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/25 11:46:26 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/25 11:46:27 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*get_snode_by_key(t_stack *stack, size_t key)
{
	t_stack_node	*snode;

	snode = stack->top;
	while (snode->key != key)
		snode = snode->next;
	return (snode);
}

t_stack_node	*insertion_sandbox_a(t_insert *in, t_stack *stack)
{
	t_insert		*clone;
	size_t			tmp;
	ssize_t			key;
	size_t			nb_op;

	clone = insert_clone(in, stack);
	key = stack->top->key - 1;
	tmp = stack->top->key;
	insertion_sandbox_try(clone, clone->stack_a, stack->top->key);
	nb_op = clone->op->size;
	insert_flush(clone);
	while (key >= 0)
	{
		clone = insert_clone(in, stack);
		insertion_sandbox_try(clone, clone->stack_a, key);
		if (nb_op > clone->op->size)
		{
			nb_op = clone->op->size;
			tmp = key;
		}
		insert_flush(clone);
		key--;
	}
	return (get_snode_by_key(stack, tmp));
}

t_stack_node	*insertion_sandbox_b(t_insert *in, t_stack *stack)
{
	t_insert		*clone;
	size_t			tmp;
	ssize_t			key;
	size_t			nb_op;

	clone = insert_clone(in, stack);
	key = stack->top->key - 1;
	tmp = stack->top->key;
	insertion_sandbox_try(clone, clone->stack_b, stack->top->key);
	nb_op = clone->op->size;
	insert_flush(clone);
	while (key >= 0)
	{
		clone = insert_clone(in, stack);
		insertion_sandbox_try(clone, clone->stack_b, key);
		if (nb_op > clone->op->size)
		{
			nb_op = clone->op->size;
			tmp = key;
		}
		insert_flush(clone);
		key--;
	}
	return (get_snode_by_key(stack, tmp));
}

t_stack_node	*insertion_sandbox(t_insert *in, t_stack *stack)
{
	if (stack->size < 2)
		return (stack->top);
	if (stack == in->stack_a)
		return (insertion_sandbox_a(in, stack));
	else
		return (insertion_sandbox_b(in, stack));
}
