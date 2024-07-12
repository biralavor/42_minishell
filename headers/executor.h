/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:56:37 by tmalheir          #+#    #+#             */
/*   Updated: 2024/07/10 14:54:02 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTER_H
# define EXECUTER_H

/**
 * @brief Tree structure.
 * @param *left_tree.
 * @param *right_tree.
 * @param *token_list.
*/
typedef struct s_tree
{
	int				type;
	struct s_tree	*tree_left;
	struct s_tree	*tree_right;
	t_token_list	*token;

}				t_tree;

/*TREE BUILDING FUNCTIONS*/

/**
 * @brief Builds the tree structure.
 * @param *lst -> The token list.
*/
void	initiate_tree(t_token_list *lst);
t_tree	*build_tree_recursive(t_token_list **lst);
void	search_logical_operator(t_tree *exec_tree, t_token_list *lst);

#endif