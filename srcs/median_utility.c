/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   median_utility.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/25 13:04:54 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/25 13:04:56 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

t_dlist				*stack_to_dlist(t_stack *stack_a)
{
	t_dlist			*list;
	t_stack_node	*snode;

	list = list_create();
	if (!list || !stack_a)
		return (NULL);
	snode = stack_a->top;
	while (snode != stack_a->bot)
	{
		list_push(list, snode);
		snode = snode->next;
	}
	list_push(list, snode);
	return (list);
}

void				*get_list_median(t_dlist *list)
{
	t_dlist_node	*cur;
	size_t			middle;
	size_t			index;

	middle = (list->size % 2 == 0) ? list->size / 2 - 1 : list->size / 2;
	cur = list->head;
	index = 0;
	while (cur && index < middle)
	{
		index++;
		cur = cur->next;
	}
	return (cur->value);
}

int					cmp_stack_nodes(t_stack_node *node_1, t_stack_node *node_2)
{
	return (node_1->data > node_2->data);
}

t_stack_node		*get_stack_median(t_stack *stack)
{
	t_dlist			*list;
	t_dlist			*tmp;
	t_stack_node	*snode;

	if (stack->size == 0)
		return (NULL);
	if (!(list = stack_to_dlist(stack)))
		return (NULL);
	tmp = list;
	list = list_merge_sort(list, &cmp_stack_nodes);
	if (tmp != list)
		list_destroy(tmp);
	snode = (t_stack_node*)get_list_median(list);
	list_destroy(list);
	return (snode);
}
