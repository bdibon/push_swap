/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   med_01.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/19 11:26:44 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/24 19:22:26 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

t_med			*med_split_left(t_med *med, size_t n)
{
	t_dlist_node	*node;
	t_med			*left;

	if (med->list->size <= n)
		return (NULL);
	node = med->list->head;
	if (!(left = med_create()))
		return (NULL);
	if (!(left->list = list_create()))
		return (NULL);
	while (((t_stack_node*)(node->value))->data <= med->median)
	{
		list_push(left->list, node->value);
		node = node->next;
	}
	left->parent = med;
	left->inf = ((t_stack_node*)(left->list->head->value))->data;
	left->sup = ((t_stack_node*)(left->list->tail->value))->data;
	left->len = left->list->size;
	med_split(left, n);
	list_destroy(left->list);
	return (left);
}

t_med			*med_split_right(t_med *med, size_t n)
{
	t_dlist_node	*node;
	t_med			*right;

	if (med->list->size <= n)
		return (NULL);
	node = med->list->tail;
	if (!(right = med_create()))
		return (NULL);
	if (!(right->list = list_create()))
		return (NULL);
	while (((t_stack_node*)(node->value))->data > med->median)
	{
		list_unshift(right->list, node->value);
		node = node->prev;
	}
	right->parent = med;
	right->inf = ((t_stack_node*)(right->list->head->value))->data;
	right->sup = ((t_stack_node*)(right->list->tail->value))->data;
	right->len = right->list->size;
	med_split(right, n);
	list_destroy(right->list);
	return (right);
}

void			med_split(t_med *med, size_t n)
{
	med->median = ((t_stack_node*)get_list_median(med->list))->data;
	med->left = med_split_left(med, n);
	med->right = med_split_right(med, n);
}

t_med			*med_create(void)
{
	t_med	*med;

	if (!(med = ft_memalloc(sizeof(t_med))))
		return (NULL);
	return (med);
}

t_med			*med_init(t_stack *stack_a, size_t n)
{
	t_dlist		*list;
	t_dlist		*tmp;
	t_med		*med;

	if (!(list = stack_to_dlist(stack_a)))
		return (NULL);
	tmp = list;
	list = list_merge_sort(list, &cmp_stack_nodes);
	if (tmp && tmp != list)
		list_destroy(tmp);
	if (!(med = med_create()))
		return (NULL);
	med->list = list;
	med->inf = ((t_stack_node*)(list->head->value))->data;
	med->sup = ((t_stack_node*)(list->tail->value))->data;
	med_split(med, n);
	med->len = list->size;
	list_destroy(list);
	return (med);
}
