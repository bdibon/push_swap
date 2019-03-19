/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   push_sort_01.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/29 18:12:54 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/25 13:26:27 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

t_stack			*ps_stack_set(t_psort *ps, t_stack *stack)
{
	t_stack		*stack_c;
	t_dlist		*list;
	t_dlist		*tmp;

	if (!(stack_c = stack_create()))
		return (NULL);
	if (!(list = stack_to_dlist(stack)))
		return (NULL);
	tmp = list;
	list = list_merge_sort(list, &cmp_stack_nodes);
	if (tmp != list)
		list_destroy(tmp);
	while (list->size)
	{
		if (stack == ps->stack_b)
			stack_push(stack_c, ((t_stack_node*)list_shift(list))->data);
		else
			stack_push(stack_c, ((t_stack_node*)list_pop(list))->data);
	}
	list_destroy(list);
	return (stack_c);
}

t_stack_node	*get_psb_node(int data, int ndata, t_stack *stack_b)
{
	t_stack_node	*snode;
	t_stack_node	*first;
	t_stack_node	*second;
	size_t			pfirst;
	size_t			psecond;

	snode = stack_b->top;
	first = NULL;
	second = NULL;
	while (snode != stack_b->bot)
	{
		first = (snode->data == data) ? snode : first;
		second = (snode->data == ndata) ? snode : second;
		snode = snode->next;
	}
	first = (snode->data == data) ? snode : first;
	second = (snode->data == ndata) ? snode : second;
	if (first == NULL || second == NULL)
		return ((first) ? first : second);
	pfirst = (first->key >= stack_b->size / 2) ?
		stack_b->top->key - first->key : first->key + 1;
	psecond = (second->key >= stack_b->size / 2) ?
		stack_b->top->key - second->key : second->key + 1;
	return ((pfirst <= psecond) ? first : second);
}

void			psb_snode(t_stack_node *snext, t_psort *ps, t_stack *stack)
{
	push(stack, ps->stack_a);
	enqueue(ps->op, ft_strdup("pa"));
	stack_pop(ps->stack_c);
	if (snext && ps->stack_a->size > 1
			&& ps->stack_a->top->next->data == snext->data)
	{
		if (stack->size > 1 && stack->top->data < stack->top->next->data)
		{
			swap_double(ps->stack_a, ps->stack_b);
			enqueue(ps->op, ft_strdup("ss"));
		}
		else
		{
			swap(ps->stack_a);
			enqueue(ps->op, ft_strdup("sa"));
		}
		stack_pop(ps->stack_c);
	}
	psb(ps, stack);
}

void			psb(t_psort *ps, t_stack *stack)
{
	t_stack_node	*snode;
	t_stack_node	*snext;

	if (stack->size == 0)
		return ;
	snode = ps->stack_c->top;
	snext = snode->next;
	if (snode->data == stack->top->data)
		psb_snode(snext, ps, stack);
	else if (snext->data == stack->top->data)
	{
		push(stack, ps->stack_a);
		enqueue(ps->op, ft_strdup("pa"));
		psb(ps, stack);
	}
	else if (get_psb_node(snode->data, snext->data, stack)->key
			< stack->size / 2 && enqueue(ps->op, ft_strdup("rrb")))
		rotate_reverse(stack);
	else
	{
		rotate(stack);
		enqueue(ps->op, ft_strdup("rb"));
	}
	psb(ps, stack);
}

void			push_sort(t_psort *ps, t_stack *stack)
{
	if (stack->size < 2)
		return ;
	ps->stack_c = ps_stack_set(ps, stack);
	if (stack == ps->stack_b)
		psb(ps, stack);
	else
		psa(ps, stack);
	stack_destroy(ps->stack_c);
}
