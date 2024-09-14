/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:56:37 by tmalheir          #+#    #+#             */
/*   Updated: 2024/09/14 15:31:11 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "environment.h"

/**
 * @brief Tree structure.
 * @param left_tree.
 * @param right_tree.
 * @param token_list.
*/
typedef struct s_tree
{
	int				type;
	t_token_list	*command;
	struct s_tree	*left;
	struct s_tree	*right;

}				t_tree;

/*TREE BUILDING FUNCTIONS*/
/**
 * @brief Builds the tree structure.
 * @param lst -> The token list.
*/
t_tree			*initiate_tree(t_token_list *lst);

t_tree			*tree_holder(t_tree *tree, bool clear_tree);

t_tree			*build_tree_recursive(t_token_list **lst);

t_token_list	*fetch_token(t_token_list *lst);

t_tree			*get_text(t_token_list *lst, t_token_list *splited,
					t_tree *tree);

t_tree			*get_splited(t_token_list *splited, t_tree *tree);

/*TREE BUILDING UTILS FUNCTIONS*/

bool			is_text(t_token_list *split_token);

void			free_token_tree(t_tree *token_tree);

t_token_list	*go_to_last_node(t_token_list *lst);

t_token_list	*go_to_first_node(t_token_list *lst);

/*EXECUTION FUNCTIONS*/

int				tree_execution(t_tree *tree, int flag);

int				manage_single_command(t_tree *tree);

char			*lookup_cmd_path(char *cmd_name);

void			fork_and_execve(char **cmd, char *path);

void			execve_error_manager(char **cmd, char **all_envs, char *path);

char			**convert_tokens_to_array(t_token_list *lst);

char			**convert_envs_to_array(t_env_entry *env_vars);

bool			is_cmd_with_valid_path(char *cmd_name);

char			*testing_all_paths_with_cmd(char **path, char *cmd_name);

int				command_runner(char **cmd);

int				manage_or(t_tree *tree);

int				manage_and(t_tree *tree);

int				manage_pipe(t_tree *tree);

void			exec_1st_child(t_tree *left, int *new_pipe);

void			exec_2nd_child(t_tree *right, int *new_pipe);

bool			child_process_is_running(bool update, bool caller);

int				pipe_execution(char **cmd, char *path);

/*MANAGE REDIRECTS FUNCTIONS*/

int				manage_redirect(t_tree *tree, int flag);

/*PRINTING FUNCTIONS (TO DELETE)*/

void			ft_tree_printer(t_tree *root);

void			ft_array_printer(char **array);

/*UTILS FUNCTIONS*/

int				fork_error(void);

bool			is_redirect(int lst_type);

bool			is_redir_out(int type);

void			change_redir_flag(int *first_redir);

#endif
