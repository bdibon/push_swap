/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   split_inb_02.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/25 13:54:56 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/25 13:55:14 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

void	split_stack_a_inb(t_split *split, t_med *med, t_nstack *stack)
{
	t_stack_node *snode;

	snode = stack->top;
	if (snode->data <= med->sup && snode->data >= med->inf)
	{
		push((t_stack*)stack, (t_stack*)split->stack_b);
		stack->nb_inb--;
		enqueue(split->op, ft_strdup("pb"));
		split_stack_a_inb(split, med, stack);
	}
}

void	split_stack_inb(t_split *split, t_med *med, t_nstack *stack)
{
	if (stack->nb_inb == 0)
		return ;
	if (stack == split->stack_a)
		split_stack_a_inb(split, med, stack);
}

void	psa_inb(t_split *split, t_nstack *stack, t_stack_node *snode,
	t_med *med)
{
	if (stack->nb_inb == 0)
		return ;
	if (snode == stack->top)
	{
		stack->nb_inb--;
		push((t_stack*)stack, (t_stack*)split->stack_b);
		enqueue(split->op, ft_strdup("pb"));
		psa_inb(split, stack, (get_stack_min_inb(med, (t_stack*)stack)), med);
		return ;
	}
	if (snode->key < stack->size / 2)
	{
		rotate_reverse((t_stack*)stack);
		enqueue(split->op, ft_strdup("rra"));
	}
	else
	{
		rotate((t_stack*)stack);
		enqueue(split->op, ft_strdup("ra"));
	}
	psa_inb(split, stack, snode, med);
}

void	push_sort_inb(t_split *split, t_med *med, t_nstack *stack)
{
	psa_inb(split, stack, get_stack_min_inb(med, (t_stack*)stack)
		, med);
}
