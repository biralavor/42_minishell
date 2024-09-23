/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:32:19 by tmalheir          #+#    #+#             */
/*   Updated: 2024/09/23 13:04:51 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

/**
 * @brief Token structure.
 * @param type      = token type.
 * @param lexeme    = actual string saved in token WORD.
 * @param next_char = to check for spaces.
 * @param idx       = node index.
 * @param prev      = previous node in token list.
 * @param next      = next node in token list.
*/
typedef struct s_token_list
{
	int					type;
	int					idx;
	char				*lexeme;
	char				next_char;
	struct s_token_list	*prev;
	struct s_token_list	*next;
}						t_token_list;

enum e_token
{
	WORD,
	PIPE,
	REDIR_IN,
	REDIR_HDOC,
	REDIR_OUT,
	REDIR_OUTAPP,
	OR,
	AND,
	SUBSHELL,
	ARCHIVE,
	DOUBLE_QUOTES,
	SINGLE_QUOTES
};

/*TOKEN LIST CREATION FUNCTIONS*/

/**
 * @brief Creates token list by calling the get_state function.
 * @param str -> User input in command line.
*/
bool	create_token_list(char *str, t_token_list **lst);

/**
 * @brief Creates each token according to the present state.
 * @param root  -> The token list.
 * @param token -> Each of the tokens to be created.
*/
void	create_new_node(t_token_list **root, t_token_list *token);

/*STATE FUNCTIONS*/

/**
 * @brief Finds out the state of each token.
 * @param str  -> User input in command line.
 * @param root -> The token list.
*/
void	get_state(int idx, char *str, t_token_list **lst);

int		state_10(t_token_list **lst, int idx);
int		state_20(t_token_list **lst, char *str, int idx);
int		state_30(t_token_list **lst, char curr, char next, int idx);
int		state_31(t_token_list **lst, int idx, char next);
int		state_32(t_token_list **lst, int idx, char next);
int		state_40(t_token_list **lst, int idx, char next);
int		state_50(t_token_list **lst, char curr, char next, int idx);
int		state_51(t_token_list **lst, int idx, char next);
int		state_52(t_token_list **lst, int idx, char next);
int		state_60(t_token_list **lst, char curr, char next, int idx);
int		state_61(t_token_list **lst, int idx, char next);
int		state_62(t_token_list **lst, int idx, char next);
int		state_70(t_token_list **lst, char *str, int idx);
int		state_80(t_token_list **lst, char *str, int idx);
int		state_90(t_token_list **lst, char *str, int idx);

/*LEXER ERROR CHECKING FUNCTIONS*/

/**
 * @brief Checks for double or single quoting errors.
 * @param str -> User input in command line.
*/
bool	check_closed_quotes(char *str);

bool	inside_quotes_detector(char *str);

/**
 * @brief Checks for open parenthesis.
 * @param str -> User input in command line.
*/
bool	check_closed_parenthesis(char *str);

/**
 * @brief Checks for empty parenthesis.
 * @param str -> User input in command line.
*/
bool	is_empty(char *str);

/**
 * @brief Checks if there are parenthesis between quotes.
 * @param str -> User input in command line.
*/
int		between_quotes(int idx, char *str);

/**
 * @brief Checks if the number of open and close parenthesis token is equal.
 * @param str -> User input in command line.
 * @param open -> the number of open parenthesis token.
 * @param close -> the number of close parenthesis token.
*/
bool	match_parenthesis(int open, int close);

int		between_parenthesis(int idx, char *str);

/*UTILS*/

/**
 * @brief Compares the current character to the next.
*/
int		check_next_char(char curr, char next);

/**
 * @brief Verifies if the character is blank according to Bash definition.
 * See manual (Definitions -> blank).
*/
int		is_blank(char c);

/**
 * @brief Frees the used memory to create the token list.
*/
void	free_token_list(t_token_list **lst);

/**
 * @brief Gets the size of the token list.
*/
int		ft_lst_size(t_token_list *lst);

/**
 * @brief Assigns indexes for each node.
*/
void	assign_lst_idx(t_token_list *lst);

char	*inside_closed_quotes_remover(char *str);

char	*update_str_if_inside_quotes(char *str);

/**
 * @todo APAGAR ESTA FUNÇÃO NO FINAL DO PROJETO.
*/
void	ft_lst_printer(t_token_list *lst);

/**
 * @todo APAGAR ESTA FUNÇÃO NO FINAL DO PROJETO.
*/
char	*get_token_string(enum e_token token);

#endif
