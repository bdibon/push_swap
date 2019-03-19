/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main_push_swap.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/25 16:15:27 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/25 19:54:12 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

int			main(int argc, char *argv[])
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_queue		*op;

	if (argc == 1)
		exit(0);
	stack_a = (argc == 2) ? stack_init2(argv) : stack_init(argc, argv);
	stack_b = stack_create();
	op = solve(stack_a, stack_b);
	print_op(op);
	queue_clear_destroy(op);
	stack_destroy(stack_a);
	stack_destroy(stack_b);
	return (0);
}
