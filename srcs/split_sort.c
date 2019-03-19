/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   split_sort.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/25 13:55:32 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/25 13:55:33 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

size_t		compute_sub_size(size_t n)
{
	if (n <= 10)
		return (n * 2);
	if (n % 2)
		return (compute_sub_size(n / 2 + 1));
	else
		return (compute_sub_size(n / 2));
}

t_med		*split_left(t_split *split, t_med *med)
{
	t_med *ret;

	if (med->left == NULL)
		return (med->parent);
	set_stack_split(med, split->stack_b);
	split_stack_1(split, med, split->stack_b);
	ret = split_left(split, med->left);
	return (ret);
}

void		split_rotate_n(t_split *split, t_nstack *stack_a, size_t n)
{
	while (n)
	{
		rotate((t_stack*)stack_a);
		enqueue(split->op, ft_strdup("ra"));
		n--;
	}
}

t_med		*split_sort_left(t_split *split, t_med *med)
{
	size_t	n;
	t_med	*ret;

	n = split->stack_b->size;
	push_sort(split->ps, split->ps->stack_b);
	split_rotate_n(split, split->stack_a, n);
	if (med->parent == NULL)
		return (med);
	set_stack_inb(med->right, split->stack_a);
	push_inb_stack_a(split, med->right, split->stack_a);
	ret = split_sort_left(split, med->parent);
	return (ret);
}

void		split_sort(t_split *split, t_med *med)
{
	set_stack_split(med, split->stack_a);
	split_stack_1(split, med->left, split->stack_a);
	med = split_left(split, med->left);
	med = split_sort_left(split, med);
	set_stack_split(med, split->stack_a);
	split_stack_2(split, med->right, split->stack_a);
	med = split_left(split, med->right);
	med = split_sort_left(split, med);
}
