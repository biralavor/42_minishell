/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:56:37 by tmalheir          #+#    #+#             */
/*   Updated: 2024/09/10 13:30:44 by tmalheir         ###   ########.fr       */
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

t_tree			*tree_holder(t_tree *tree, bool clear);

t_tree			*build_tree_recursive(t_token_list **lst);

t_token_list	*fetch_token(t_token_list *lst);

t_tree			*text(t_token_list *lst, t_token_list *split, t_tree *tree);

t_tree			*tree_with_redir(t_token_list *split, t_token_list *lst, t_tree *node);

/*TREE BUILDING UTILS FUNCTIONS*/

bool			is_text(t_token_list *split_token);

void			free_token_tree(t_tree *token_tree);

t_token_list	*go_to_last_node(t_token_list *lst);

t_token_list	*go_to_first_node(t_token_list *lst);

/*EXECUTION FUNCTIONS*/

int				tree_execution(t_tree *tree, int flag);

int				execute(t_tree *tree);

char			*lookup_cmd_path(char *cmd_name);

int				fork_and_execve(char **cmd, char *path);

char			**convert_tokens_to_array(t_token_list *lst);

char			**convert_envs_to_array(t_env_entry *env_vars);

bool			is_cmd_with_valid_path(char *cmd_name);

char			*testing_all_paths_with_cmd(char **path, char *cmd_name);

int				command_manager(char **cmd);

int				manage_or(t_tree *tree);

int				manage_and(t_tree *tree);

int				manage_pipe(t_tree *tree);

void			exec_1st_child(t_tree *left, int *new_pipe);

void			exec_2nd_child(t_tree *right, int *new_pipe);

int				pipe_execution(char **cmd, char *path);

/*MANAGE REDIRECTS FUNCTIONS*/

bool			is_redirect(int lst_type);

int				manage_redirect(t_tree *tree, int flag);

/*PRINTING FUNCTIONS (TO DELETE)*/

void			ft_tree_printer(t_tree *root);

void			ft_array_printer(char **array);

/*UTILS FUNCTIONS*/

int				fork_error(void);

#endif
