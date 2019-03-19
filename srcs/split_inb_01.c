/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   split_inb_01.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/25 13:55:52 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/25 13:57:38 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

size_t			count_stack_inb(t_med *med, t_nstack *stack)
{
	int				inf;
	int				sup;
	size_t			nb;
	t_stack_node	*node;

	if (!stack || stack->size == 0)
		return (0);
	inf = med->inf;
	sup = med->sup;
	nb = 0;
	node = stack->top;
	while (node != stack->bot)
	{
		if (node->data >= inf && node->data <= sup)
			nb++;
		node = node->next;
	}
	if (node->data >= inf && node->data <= sup)
		nb++;
	stack->nb_inb = nb;
	return (nb);
}

size_t			set_stack_inb(t_med *med, t_nstack *stack)
{
	stack->med = med->median;
	return (count_stack_inb(med, stack));
}

void			push_inb_stack_a(t_split *split, t_med *med, t_nstack *stack)
{
	t_stack_node *snode;

	if (stack->nb_inb == 0)
		return ;
	snode = stack->top;
	if (snode->data >= med->inf && snode->data <= med->sup)
	{
		push((t_stack*)stack, (t_stack*)split->stack_b);
		stack->nb_inb--;
		enqueue(split->op, ft_strdup("pb"));
		balance_stack_b(stack, split->stack_b, med, split->op);
	}
	push_inb_stack_a(split, med, stack);
}

t_dlist			*stack_to_dlist_inb(t_med *med, t_stack *stack_a)
{
	t_dlist			*list;
	t_stack_node	*snode;

	list = list_create();
	if (!list || !stack_a)
		return (NULL);
	snode = stack_a->top;
	while (snode != stack_a->bot)
	{
		if (snode->data >= med->inf && snode->data <= med->sup)
			list_push(list, snode);
		snode = snode->next;
	}
	if (snode->data >= med->inf && snode->data <= med->sup)
		list_push(list, snode);
	return (list);
}

t_stack_node	*get_stack_min_inb(t_med *med, t_stack *stack)
{
	t_dlist			*list;
	t_dlist			*tmp;
	t_stack_node	*snode;

	if (stack->size == 0)
		return (NULL);
	if (!(list = stack_to_dlist_inb(med, stack)))
		return (NULL);
	tmp = list;
	list = list_merge_sort(list, &cmp_stack_nodes);
	if (tmp != list)
		list_destroy(tmp);
	snode = (list->size) ? list->head->value : NULL;
	list_destroy(list);
	return (snode);
}
