/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   push_sort_02.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/29 18:12:54 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/25 13:28:28 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

t_psort			*psort_init(t_stack *stack_a, t_stack *stack_b,
	t_queue *op)
{
	t_psort	*ps;

	if (!(ps = ft_memalloc(sizeof(t_psort))))
		return (NULL);
	ps->stack_a = stack_a;
	ps->stack_b = stack_b;
	ps->op = (op) ? op : queue_create();
	return (ps);
}

t_stack_node	*get_psa_node(int data, int ndata, t_stack *stack_a)
{
	t_stack_node	*snode;
	t_stack_node	*first;
	t_stack_node	*second;
	size_t			pfirst;
	size_t			psecond;

	snode = stack_a->top;
	first = NULL;
	second = NULL;
	while (snode != stack_a->bot)
	{
		first = (snode->data == data) ? snode : first;
		second = (snode->data == ndata) ? snode : second;
		snode = snode->next;
	}
	first = (snode->data == data) ? snode : first;
	second = (snode->data == ndata) ? snode : second;
	if (first == NULL || second == NULL)
		return ((first) ? first : second);
	pfirst = (first->key >= stack_a->size / 2) ?
		stack_a->top->key - first->key : first->key + 1;
	psecond = (second->key >= stack_a->size / 2) ?
		stack_a->top->key - second->key : second->key + 1;
	return ((pfirst <= psecond) ? first : second);
}

void			psa_snode(t_stack_node *snext, t_psort *ps, t_stack *stack)
{
	push(stack, ps->stack_b);
	enqueue(ps->op, ft_strdup("pb"));
	stack_pop(ps->stack_c);
	if (snext && ps->stack_b->size > 1 &&
			ps->stack_b->top->next->data == snext->data)
	{
		if (stack->size > 1 && stack->top->data > stack->top->next->data)
		{
			swap_double(ps->stack_a, ps->stack_b);
			enqueue(ps->op, ft_strdup("ss"));
		}
		else
		{
			swap(ps->stack_b);
			enqueue(ps->op, ft_strdup("sb"));
		}
		stack_pop(ps->stack_c);
	}
	psa(ps, stack);
}

void			psa(t_psort *ps, t_stack *stack)
{
	t_stack_node	*snode;
	t_stack_node	*snext;

	if (stack->size == 0)
		return ;
	snode = ps->stack_c->top;
	snext = snode->next;
	if (snode->data == stack->top->data)
		psa_snode(snext, ps, stack);
	else if (snext->data == stack->top->data)
	{
		push(stack, ps->stack_b);
		enqueue(ps->op, ft_strdup("pb"));
		psa(ps, stack);
	}
	else if (get_psa_node(snode->data, snext->data, stack)->key
			< stack->size / 2 && enqueue(ps->op, ft_strdup("rra")))
		rotate_reverse(stack);
	else
	{
		rotate(stack);
		enqueue(ps->op, ft_strdup("ra"));
	}
	psa(ps, stack);
}

void			ps_smooth(t_psort *ps)
{
	if (ps->stack_a->size > 0)
		while (ps->stack_a->size > 0)
		{
			push(ps->stack_a, ps->stack_b);
			enqueue(ps->op, ft_strdup("pb"));
		}
	else
		while (ps->stack_b->size > 0)
		{
			push(ps->stack_b, ps->stack_a);
			enqueue(ps->op, ft_strdup("pa"));
		}
}
