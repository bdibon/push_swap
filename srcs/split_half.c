/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   split_half.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/25 13:52:04 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/25 13:52:06 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

t_med		*split_sort_left_half(t_split *split, t_med *med)
{
	size_t	n;
	t_med	*ret;

	n = split->stack_b->size;
	push_sort(split->ps, split->ps->stack_b);
	if (med->parent == NULL)
		return (med);
	set_stack_inb(med->right, split->stack_a);
	push_inb_stack_a(split, med->right, split->stack_a);
	ret = split_sort_left_half(split, med->parent);
	return (ret);
}

void		split_sort_half(t_split *split, t_med *med)
{
	t_med *tmp;

	tmp = med;
	if (med->left->left)
		med_flush(&med->left->left);
	if (med->left->right)
		med_flush(&med->left->right);
	if (med->right->left)
		med_flush(&med->right->left);
	if (med->right->right)
		med_flush(&med->right->right);
	set_stack_split(med, split->stack_a);
	split_stack_3(split, med->right, split->stack_a);
	med = split_sort_left_half(split, med);
	set_stack_split(med, split->stack_a);
	split_stack_1(split, med->left, split->stack_a);
	med = split_sort_left_half(split, med);
	med = tmp;
}
