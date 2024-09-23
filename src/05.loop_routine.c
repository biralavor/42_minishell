/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05.loop_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 09:20:45 by tmalheir          #+#    #+#             */
/*   Updated: 2024/09/20 19:10:59 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
static void	check_heredoc(t_token_list *lst);
/*
void	check_userinput(char *str)
{
	t_token_list	*lst;
	t_tree			*token_tree;

	lst = NULL;
	token_tree = NULL;
	if (!check_initial_errors(str))
		error_manager_lexer(INITIAL_ERROR);
	if (!create_token_list(str, &lst))
		error_manager_lexer(LIST_NOT_CREATED);
	syntax_analysis(lst);
	// builtins_manager(lst);
	token_tree = initiate_tree(lst);
	// ft_tree_printer(token_tree);
	tree_execution(token_tree);
	free_token_tree(token_tree);
}
*/

/*
t_tree	*test_tree(void)
{
	t_tree	*tree;

	tree = calloc(sizeof(t_tree), 1);
	tree->type = REDIR_OUT;

	tree->right = calloc(sizeof(t_tree), 1);
	tree->right->type = ARCHIVE;
	create_token_list("tudo", &tree->right->command);

	tree->left = calloc(sizeof(t_tree), 1);
	tree->left->type = REDIR_OUT;

	tree->left->right = calloc(sizeof(t_tree), 1);
	tree->left->right->type = ARCHIVE;
	create_token_list("bem", &tree->left->right->command);

	tree->left->left = calloc(sizeof(t_tree), 1);
	tree->left->left->type = REDIR_OUT;

	tree->left->left->right = calloc(sizeof(t_tree), 1);
	tree->left->left->right->type = ARCHIVE;
	create_token_list("com", &tree->left->left->right->command);

	tree->left->left->left = calloc(sizeof(t_tree), 1);
	tree->left->left->left->type = REDIR_IN;

	tree->left->left->left->right = calloc(sizeof(t_tree), 1);
	tree->left->left->left->right->type = ARCHIVE;
	create_token_list("voce", &tree->left->left->left->right->command);

	tree->left->left->left->left = calloc(sizeof(t_tree), 1);
	tree->left->left->left->left->type = WORD;
	create_token_list("ls", &tree->left->left->left->left->command);

	return (tree);
}
*/

void	loop_routine(char *str)
{
	t_token_list	*lst;
	t_tree			*token_tree;

	lst = NULL;
	token_tree = NULL;
	if (!check_initial_errors(str))
		error_manager_lexer(INITIAL_ERROR);
	if (!create_token_list(str, &lst))
		error_manager_lexer(LIST_NOT_CREATED);
	if (ft_strncmp(lst->lexeme, "", ft_strlen(lst->lexeme)) == 0)
	{
		free_token_list(&lst);
		return ;
	}
	if (syntax_analysis(lst))
	{
		check_heredoc(lst);
		token_tree = initiate_tree(lst);
		tree_holder(token_tree, false);
		tree_execution(token_tree, 0);
		free_token_tree(token_tree);
	}
}

static int	check_delimiter(char *delimiter, int fd, char *input)
{
	while (input && ft_strncmp(input, delimiter, (ft_strlen(delimiter) - 1)))
	{
		if (input)
		{
			write(fd, input, ft_strlen(input));
			write(fd, "\n", 1);
		}
		input = readline(">");
	}
	if (input)
		free(input);
	return (0);
}

/*
static char	*path_file(void)
{
	static int	file_nbr;
	char		*nbr;
	char		*heredoc_path;

	nbr = ft_itoa(file_nbr);
	heredoc_path = ft_strjoin("/tmp/heredoc_", nbr);
	free(nbr);
	return (heredoc_path);
}
*/

void	path_file(t_token_list *lst)
{
	static int		file_nbr;
	char			*nbr;
	char			*pathname;
	t_token_list	*tmp;

	nbr = ft_itoa(file_nbr);
	pathname = ft_strjoin("/tmp/heredoc_", nbr);
	tmp = lst;
	while (tmp)
	{
		if (tmp->type == REDIR_HDOC)
		{
			tmp->next->type = ARCHIVE;
			tmp->next->lexeme = ft_strdup(pathname);
		}
		tmp = tmp->next;
	}
	free(nbr);
	free(pathname);
}

static void	check_heredoc(t_token_list *lst)
{
	int				heredoc_fd;
	char			*heredoc_input;
	char			*delimiter;
	t_token_list	*tmp;

	heredoc_fd = 0;
	heredoc_input = NULL;
	delimiter = NULL;
	tmp = lst;
	while (tmp->next)
	{
		if (tmp->type == REDIR_HDOC)
		{
			delimiter = ft_strdup(tmp->next->lexeme);
			path_file(lst);
//			tmp->next->lexeme = ft_strdup(path_file());
			heredoc_fd = open(tmp->next->lexeme, O_CREAT | O_RDWR | O_TRUNC, 0644);
			heredoc_input = readline(">");
			if (!check_delimiter(delimiter, heredoc_fd, heredoc_input))
				break ;
		}
		tmp = tmp->next;
	}
	close(heredoc_fd);
	free(delimiter);
	free(heredoc_input);
}
