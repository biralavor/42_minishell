/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:56:37 by tmalheir          #+#    #+#             */
/*   Updated: 2024/08/15 14:36:58 by umeneses         ###   ########.fr       */
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
	int					size;
	struct s_env_entry	*next;
	struct s_env_entry	*prev;
}						t_env_entry;

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
/**
 * @brief Initializes the environment table.
 * @param envp -> a system array of strings that define the
 * current environment variables.
 * While envp is not NULL, it will iterate through the environment
 * variables and add them to the table. When ft_strchr finds the first '=',
 * it copies the string before the '=' to KEY (at position equal_sign - *envp)
 * and the string after the '=' to VALUE.
 */
void			environment_init(char **envp);

/**
 * @brief Allocates memory for the environment table, by a size.
 */
t_env_entry		*alloc_table(int init_size);

/**
 * @brief Adds a new entry to the environment table. If the table is NULL,
 * then it returns the new_entry. Otherwise, it will iterate through the table.
 */
t_env_entry		*addto_env_table(t_env_entry *table, const char *key,
					const char *value);

/**
 * @brief Removes an entry from the environment table.
 * @param table -> the environment variables.
 * @param update -> if true, updates the static environment table.
 * @param clear_table -> if true, clears the static environment table.
 */
t_env_entry		*env_holder(t_env_entry *table, bool update, bool clear_table);

/**
 * @brief: Goes to the head of the environment table.
 */
t_env_entry		*goto_head_env_table(t_env_entry *table);

/**
 * @brief: Goes to the end of the environment table.
 */
t_env_entry		*goto_end_env_table(t_env_entry *table);

/* ENVIRONMENT UTILS FUNCTIONS */
/**
 * @brief: Looks up for a key in the environment table.
 * @param table -> the environment variables.
 * @param key -> the key to be searched.
 */
t_env_entry		*lookup_table(t_env_entry *table, char *key);

/**
 * @brief: This function uses the djb2 algorithm, which is widely
 * regarded as one of the best general-purpose hash functions.
 * It starts with a magic number (5381) and processes each character
 * of the key by shifting the current hash value left by 5 bits
 * and adding the ASCII value of the current character.
 * Finally,  * it applies the modulus operation with the table size
 * to ensure the hash value fits within the bounds of the table.
 */
unsigned long	hash_maker(const char *key, int size);

void			ft_env_printer(t_env_entry	*env_table);

void			free_env_table(t_env_entry *env_vars);

void			free_env_array(char **envp);

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