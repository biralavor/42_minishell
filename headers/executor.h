/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:56:37 by tmalheir          #+#    #+#             */
/*   Updated: 2024/07/05 14:29:41 by tmalheir         ###   ########.fr       */
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
	struct s_tree	*left_tree;
	struct s_tree	*right_tree;
	t_token_list	*token_list;

}				t_tree;

/*TREE BUILDING FUNCTIONS*/

/**
 * @brief Builds the tree structure.
 * @param *lst -> The token list.
*/
void	build_tree(t_token_list *lst);

#endif