/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:56:37 by tmalheir          #+#    #+#             */
/*   Updated: 2024/08/19 11:12:55 by umeneses         ###   ########.fr       */
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

t_token_list	*go_to_last_node(t_token_list *lst);

t_token_list	*go_to_first_node(t_token_list *lst);

void			tree_execution(t_tree *tree);

void			execute(t_tree *tree);

char			*lookup_cmd_path(char *cmd_name);

void			fork_and_execve(char **cmd, char *path);

char			**convert_tokens_to_array(t_token_list *lst);

char			**convert_envs_to_array(t_env_entry *env_vars);

/**
 * @brief Builds the tree structure.
 * @param lst -> The token list.
*/
t_tree			*initiate_tree(t_token_list *lst);

t_tree			*build_tree_recursive(t_token_list **lst);

t_token_list	*fetch_token(t_token_list *lst);

t_tree			*text(t_token_list *lst, t_token_list *split, t_tree *tree);

bool			is_text(t_token_list *split_token);

void			free_token_tree(t_tree *token_tree);

void			ft_tree_printer(t_tree *root);

void			ft_array_printer(char **array);

#endif