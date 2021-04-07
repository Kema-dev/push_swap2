/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 11:28:31 by jjourdan          #+#    #+#             */
/*   Updated: 2021/04/07 17:45:03 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../../libs/libkema/includes/libkema.h"

typedef struct s_dish {
	int				value;
	struct s_dish	*next;
}	t_dish;

typedef struct s_stack {
	struct s_dish	*a;
	struct s_dish	*b;
}	t_stack;

typedef struct s_commands {
	char				*value;
	struct s_commands	*next;
}	t_commands;

typedef struct s_group {
	int					min;
	int					max;
	int					size;
	struct s_group		*next;
}	t_group;

typedef struct s_info {
	int		min;
	int		max;
	int		nb;
	int		group_1_low;
	int		group_1_high;
	bool	group_1_dir;
	size_t	group_1_size;
	int		group_2_low;
	int		group_2_high;
	bool	group_2_dir;
	size_t	group_2_size;
	int		group_3_low;
	int		group_3_high;
	bool	group_3_dir;
	size_t	group_3_size;
	int		nb_grps;
	int		grp_size;
}	t_info;

// ? main.c
int			ft_push_check_arg(char **argv);
int			main(int argc, char **argv);

// ? ft_push_list_manip.c
void		ft_push_print_stack(t_dish *dish);
t_dish		*ft_push_lstnew(t_list *mem, int content);
t_commands	*ft_push_command_lstnew(t_list *mem, char *text);
void		ft_push_lstadd_back(t_dish **alst, t_dish *new);
void		ft_push_command_lstadd_back(t_commands **alst, t_commands *new);

// ? ft_push_operation_s.c
void		ft_push_sa(t_stack *stack);
void		ft_push_sb(t_stack *stack);
void		ft_push_ss(t_stack *stack);

// ? ft_push_operation_p.c
void		ft_push_pa(t_stack *stack);
void		ft_push_pb(t_stack *stack);

// ? ft_push_operation_r.c
void		ft_push_ra(t_stack *stack);
void		ft_push_rb(t_stack *stack);
void		ft_push_rr(t_stack *stack);

// ? ft_push_operation_rr.c
void		ft_push_rra(t_stack *stack);
void		ft_push_rrb(t_stack *stack);
void		ft_push_rrr(t_stack *stack);

// ? ft_push_get_commands.c
t_commands	*ft_push_get_commands(t_list *mem, t_commands *command);

// ? ft_push_get_stack_size.c
void		ft_push_get_stack_size(t_list *mem, t_stack *stack);

// ? ft_push_sort_values.c
void		ft_push_finish_rotate(t_info *info, t_stack *stack);
void		ft_push_g2(t_info *info, t_stack *stack);
int			ft_push_lstsize(t_dish *dish);
int			*ft_push_list_to_tab(t_list *mem, t_dish *dish, size_t size);
void		ft_push_chose_algo(t_list *mem, t_stack *stack);

// ? ft_push_3_val.c
int			ft_push_check_sort(t_dish *val);
void		ft_push_3_val(t_stack *stack, int *tab);

// ? ft_push_get_infos.c
void		ft_push_sort_tab(int *tab, int size);
t_info		*ft_push_get_infos(int *tab, t_info *info);

// ? ft_push_to_b.c
void		ft_push_0_x1_to_b(t_info *info, t_stack *stack);
int			ft_push_find_idx(t_dish *dish, int value);
void		ft_push_b_to_a(t_list *mem, t_stack *stack);
void		ft_push_x2_max_to_b(t_info *info, t_stack *stack);

// ? ft_push_maths.c
int			ft_push_get_sqrt(int nb);
void		ft_push_50_250(t_list *mem, t_info *info, t_stack *stack);
void		ft_push_250_max(int *tab, t_list *mem, t_info *info, t_stack *stack);

// ? ft_push_grp_manip.c
t_group		*ft_push_group_lstnew(t_list *mem, int min, int max, int group_size);
void		ft_push_group_lstadd_back(t_group **alst, t_group *new);

#endif