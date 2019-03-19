/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   solve_01.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/25 13:07:40 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/25 19:44:13 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

t_queue		*solve_12(t_stack *stack_a, t_stack *stack_b)
{
	t_queue *op_ins;
	t_queue *op_half;
	t_queue	*op_ps;
	t_queue	*op;

	op_ins = solve_ins(stack_a, stack_b);
	op_half = solve_half(stack_a, stack_b);
	op_ps = solve_ps(stack_a, stack_b);
	if (op_ins->size > op_half->size && (op = op_half))
		queue_clear_destroy(op_ins);
	else
	{
		op = op_ins;
		queue_clear_destroy(op_half);
	}
	if (op_ps->size < op->size)
	{
		queue_clear_destroy(op);
		op = op_ps;
	}
	else
		queue_clear_destroy(op_ps);
	return (op);
}

t_queue		*solve_30(t_stack *stack_a, t_stack *stack_b)
{
	t_queue *op_half;
	t_queue	*op_ps;
	t_queue	*op;

	op_half = solve_half(stack_a, stack_b);
	op_ps = solve_ps(stack_a, stack_b);
	if (op_half->size > op_ps->size)
	{
		queue_clear_destroy(op_half);
		op = op_ps;
	}
	else
	{
		queue_clear_destroy(op_ps);
		op = op_half;
	}
	return (op);
}

t_queue		*solve(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size <= 5)
		return (solve_ins(stack_a, stack_b));
	else if (stack_a->size < 12)
		return (solve_12(stack_a, stack_b));
	else if (stack_a->size < 30)
		return (solve_30(stack_a, stack_b));
	else if (stack_a->size <= 100)
		return (solve_half(stack_a, stack_b));
	else
		return (solve_split(stack_a, stack_b));
}
