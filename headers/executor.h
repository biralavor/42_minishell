/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:56:37 by tmalheir          #+#    #+#             */
/*   Updated: 2024/08/07 15:48:17 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

/**
 * @brief Environment entry
 * @param *key -> The NAME of the environment variable.
 * @param *value -> The VALUE of the environment variable.
 * @param *next -> The next environment entry.
 */
typedef struct s_env_entry
{
	char				*key;
	char				*value;
	struct s_env_entry	*next;
}						t_env_entry;

/**
 * @brief Environment table - holds the environment size and entries.
 */
typedef struct s_env_table
{
	t_env_entry			**head;
	int					size;
}						t_env_table;

/**
 * @brief Tree structure.
 * @param *left_tree.
 * @param *right_tree.
 * @param *token_list.
*/
typedef struct s_tree
{
	int				type;
	t_token_list	*command;
	struct s_tree	*left;
	struct s_tree	*right;

}				t_tree;

/* ENVIRONMENT FUNCTIONS */
void			environment_init(char **envp);
t_env_table		*create_table(int init_size);
void			addto_env_table(t_env_table *table, const char *key,
					const char *value);
char			*lookup_table(t_env_table *table, char *key);
void			resize_table(t_env_table *table);
unsigned long	hash_maker(const char *key, int size);
void			ft_env_printer(t_env_table	*env_table);

/*TREE BUILDING FUNCTIONS*/

t_token_list	*go_to_last_node(t_token_list *lst);

t_token_list	*go_to_first_node(t_token_list *lst);

/**
 * @brief Builds the tree structure.
 * @param *lst -> The token list.
*/
t_tree			*initiate_tree(t_token_list *lst);

t_tree			*build_tree_recursive(t_token_list **lst);

t_token_list	*fetch_token(t_token_list *lst);

t_tree			*text(t_token_list *lst, t_token_list *split, t_tree *tree);

bool			is_text(t_token_list *split_token);

void			free_token_tree(t_tree *token_tree);

void			ft_tree_printer(t_tree *root);

#endif