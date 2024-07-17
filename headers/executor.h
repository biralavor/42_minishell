/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:56:37 by tmalheir          #+#    #+#             */
/*   Updated: 2024/07/15 15:20:47 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

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

#endif