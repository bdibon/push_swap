/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main_checker.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/25 12:58:46 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/25 19:42:27 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char *argv[])
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	char		**op_list;

	if (argc == 1)
		return (0);
	stack_a = (argc == 2) ? stack_init2(argv) : stack_init(argc, argv);
	stack_b = stack_create();
	op_list = get_operations(stack_a, stack_b);
	try_op(op_list, stack_a, stack_b);
	check_result(stack_a, stack_b);
	return (0);
}
