/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   push_swap.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bodibon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/12 17:28:56 by bodibon      #+#   ##    ##    #+#       */
/*   Updated: 2018/08/27 11:04:22 by bodibon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#	ifndef PUSH_SWAP_H
#	define PUSH_SWAP_H

#include "stack.h"
#include "queue.h"
#include "limits.h"

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

t_stack						*get_input(int argc, char *argv[]);
int							ft_strisnum(char *str);
intmax_t					ft_atoi2(const char *str);
int							check_duplicates(t_stack *stack_a, int data);
void						print_error(void);

t_queue						*solve_12(t_stack *stack_a, t_stack *stack_b);
t_queue						*solve_30(t_stack *stack_a, t_stack *stack_b);
t_queue						*solve(t_stack *stack_a, t_stack *stack_b);
t_queue						*solve_ps(t_stack *stack_a, t_stack *stack_b);
t_queue						*solve_ins(t_stack *stack_a, t_stack *stack_b);
t_queue						*solve_half(t_stack *stack_a, t_stack *stack_b);
t_queue						*solve_split(t_stack *stack_a, t_stack *stack_b);

typedef struct				s_insert
{
	t_stack					*stack_a;
	t_stack					*stack_b;
	t_queue					*queue_a;
	t_queue					*queue_b;
	t_queue					*op;
	int						ndata;
}							t_insert;

t_insert					*insertion_sort(t_insert *in, t_stack *stack);
t_insert					*init_insert(t_stack *stack_a, t_stack *stack_b,
		t_queue *op);
void						isort_smoothen(t_insert *in, t_stack *stack);
void						isort_master(t_insert *in, t_stack *stack,
	t_stack_node *snode);
void						isort_master_a(t_insert *in, t_stack_node *snode);
void						isort_master_b(t_insert *in, t_stack_node *snode);
int							find_path_to_qnode(t_insert *in, t_stack *stack,
		t_stack_node *snode);
void						q_swap_maj(t_queue *queue, t_stack_node *snode);
void						isort_down_a(t_insert *in, t_stack_node *snode);
void						isort_down_b(t_insert *in, t_stack_node *snode);
void						isort_up_a(t_insert *in, t_queue_node *qnode);
void						isort_up_b(t_insert *in, t_queue_node *qnode);

t_stack_node				*insertion_sandbox(t_insert *in, t_stack *stack);
t_insert					*insert_clone(t_insert *in, t_stack *stack);
void						insert_flush(t_insert *in);
void						insert_flush2(t_insert *in);
void						insertion_sandbox_try(t_insert *in, t_stack *stack,
	size_t key);
t_stack_node				*get_snode_by_key(t_stack *stack, size_t key);
t_stack_node				*insertion_sandbox_a(t_insert *in, t_stack *stack);
t_stack_node				*insertion_sandbox_b(t_insert *in, t_stack *stack);

typedef struct				s_psort
{
	t_stack					*stack_a;
	t_stack					*stack_b;
	t_stack					*stack_c;
	t_queue					*op;
}							t_psort;

void						push_sort(t_psort *ps, t_stack *stack);
t_stack_node				*get_stack_min(t_stack *stack);
void						psa(t_psort *ps, t_stack *stack);
t_stack_node				*get_stack_max(t_stack *stack);
void						psb(t_psort *ps, t_stack *stack_b);
t_psort						*psort_init(t_stack *stack_a, t_stack *stack_b,
	t_queue *op);
void						ps_smooth(t_psort *ps);

typedef struct				s_med
{
	int						median;
	int						inf;
	int						sup;
	t_dlist					*list;
	size_t					len;
	struct s_med			*left;
	struct s_med			*right;
	struct s_med			*parent;
}							t_med;

t_med						*med_init(t_stack *stack_a, size_t n);
void						med_split(t_med *med, size_t n);
t_med						*med_split_left(t_med *med, size_t n);
t_med						*med_split_right(t_med *med, size_t n);
t_med						*med_create(void);
void						med_flush(t_med **med);

typedef struct				s_nstack
{
	struct s_stack_node		*top;
	struct s_stack_node		*bot;
	size_t					size;
	int						med;
	size_t					nb_supmed;
	size_t					nb_infmed;
	size_t					nb_inb;
}							t_nstack;

typedef struct				s_split
{
	t_nstack				*stack_a;
	t_nstack				*stack_b;
	t_queue					*op;
	t_psort					*ps;
}							t_split;

t_dlist						*stack_to_dlist(t_stack *stack_a);
void						*get_list_median(t_dlist *list);
int							cmp_stack_nodes(t_stack_node *node_1,
	t_stack_node *node_2);
t_stack_node				*get_stack_median(t_stack *stack);

t_nstack					*nstack_create(t_stack *stack);
t_split						*split_set(t_stack *stack_a, t_stack *stack_b);

size_t						count_stack_supmed(t_nstack *nstack);
void						set_stack_split(t_med *med, t_nstack *stack);
size_t						count_stack_inb(t_med *med, t_nstack *stack);
size_t						set_stack_inb(t_med *med, t_nstack *stack);

int							check_inb_stack_a(t_med *med, t_nstack *stack);
void						push_inb_stack_a(t_split *split, t_med *med,
	t_nstack *stack);
t_stack_node				*get_stack_min_inb(t_med *med, t_stack *stack);
void						split_stack_inb(t_split *split, t_med *med,
	t_nstack *stack);
void						push_sort_inb(t_split *split, t_med *med,
	t_nstack *stack);

size_t						check_split_path_ra(t_nstack *stack);
size_t						check_split_path_rra(t_nstack *stack);
size_t						check_split_path_rb(t_nstack *stack);
size_t						check_split_path_rrb(t_nstack *stack);
size_t						check_split_path_ra_2(t_nstack *stack);
size_t						check_split_path_rra_2(t_nstack *stack);

void						balance_stack_b(t_nstack *stack_a,
	t_nstack *stack_b, t_med *med, t_queue *op);
void						split_stack_1_a(t_split *split, t_med *med,
	t_nstack *stack);
void						split_stack_1_b(t_split *split, t_med *med,
	t_nstack *stack);
void						split_stack_1(t_split *split, t_med *med,
	t_nstack *stack);
void						split_stack_2(t_split *split, t_med *med,
	t_nstack *stack);
void						split_stack_3(t_split *split, t_med *med,
	t_nstack *stack);
size_t						compute_sub_size(size_t n);
void						split_sort(t_split *split, t_med *med);
void						split_sort_half(t_split *split, t_med *med);
void						split_flush(t_split *split);

char						*stream_to_string(t_stack *stack_a,
		t_stack *stack_b);
char						**get_operations(t_stack *stack_a,
		t_stack *stack_b);
void						check_op(char *op);
void						do_op(char *op, t_stack *stack_a,
		t_stack *stack_b);
void						try_op(char **op_list, t_stack *stack_a,
		t_stack *stack_b);
void						print_ok(void);
void						print_ko(void);
void						check_result(t_stack *stack_a, t_stack *stack_b);
int							check_result2(t_stack *stack_a, t_stack *stack_b);

#	endif
