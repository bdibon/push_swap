/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   solve_02.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/25 13:53:21 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/25 19:48:02 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

t_queue		*solve_ps(t_stack *stack_a, t_stack *stack_b)
{
	t_psort	*ps;
	t_queue	*op;
	t_stack	*clone_a;
	t_stack	*clone_b;

	clone_a = stack_clone(stack_a);
	clone_b = stack_clone(stack_b);
	ps = psort_init(clone_a, clone_b, NULL);
	op = ps->op;
	push_sort(ps, clone_a);
	ps_smooth(ps);
	stack_destroy(clone_a);
	stack_destroy(clone_b);
	free(ps);
	return (op);
}

t_queue		*solve_ins(t_stack *stack_a, t_stack *stack_b)
{
	t_insert		*in;
	t_queue			*op;
	t_stack			*clone_a;
	t_stack			*clone_b;

	clone_a = stack_clone(stack_a);
	clone_b = stack_clone(stack_b);
	in = init_insert(clone_a, clone_b, NULL);
	op = in->op;
	insertion_sort(in, clone_a);
	insert_flush2(in);
	return (op);
}

t_queue		*solve_half(t_stack *stack_a, t_stack *stack_b)
{
	t_med	*med;
	t_queue	*op;
	t_stack	*clone_a;
	t_stack	*clone_b;
	t_split	*split;

	clone_a = stack_clone(stack_a);
	clone_b = stack_clone(stack_b);
	split = split_set(clone_a, clone_b);
	med = med_init(clone_a, clone_a->size / 2);
	split->ps = psort_init((t_stack*)split->stack_a,
		(t_stack*)split->stack_b, split->op);
	op = split->op;
	split_sort_half(split, med);
	med_flush(&med);
	free(clone_a);
	free(clone_b);
	split_flush(split);
	return (op);
}

t_queue		*solve_split(t_stack *stack_a, t_stack *stack_b)
{
	t_med	*med;
	t_queue	*op;
	t_stack	*clone_a;
	t_stack	*clone_b;
	t_split	*split;

	clone_a = stack_clone(stack_a);
	clone_b = stack_clone(stack_b);
	split = split_set(clone_a, clone_b);
	med = med_init(clone_a, compute_sub_size(clone_a->size));
	split->ps = psort_init((t_stack*)split->stack_a,
		(t_stack*)split->stack_b, split->op);
	op = split->op;
	split_sort(split, med);
	med_flush(&med);
	free(clone_a);
	free(clone_b);
	split_flush(split);
	return (op);
}
