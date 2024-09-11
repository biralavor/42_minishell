/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:57:00 by umeneses          #+#    #+#             */
/*   Updated: 2024/09/11 16:44:59 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# define MAX_LEN_CODE 19
# define MIN_LEN_CODE 20
# define LONG_MAX_CODE "9223372036854775807"
# define LONG_MIN_CODE "-9223372036854775807"

/**
 * @brief: Calls the respective builtin function.
*/
void		builtins_manager(t_token_list *cmd);

/**
 * @brief: Builtins manager for EXPORT and UNSET.
*/
void		builtins_with_possible_args_manager(t_token_list *cmd);

/**
 * @brief: Builtins detector for EXPORT and UNSET,
 * which could handle possible arguments.
 */
bool		builtins_detector_with_possible_args(t_token_list *cmd);

/**
 * @brief: Checks if there are any builtins in the token list.
*/
bool		builtins_detector(t_token_list *cmd);

/**
 * @brief: Runs the echo - imitate words - builtin command.
*/
void		builtins_runner_echo(t_token_list *lst, bool arg_option);

/**
 * @brief: Runs the pwd - print work directory - builtin command.
*/
void		builtins_runner_pwd(t_token_list *lst);

/**
 * @brief: Runs the cd - change directory - builtin command.
 * TODO: Implement update_envs() after calling chdir().
*/
void		builtins_runner_cd(t_token_list *lst);

/**
 * @brief: Switches to the new directory.
 * @param destiny_path the path to be switched.
*/
void		builtins_cd_switch_new_dir(char *destiny_path);

/**
 * @brief: Switches to the home directory, if user input is `cd ~`.
 */
void		builtins_cd_switch_home_dir(void);

/**
 * @brief: Switches to the old directory, if user input is `cd ..`.
*/
void		builtins_cd_switch_parent_dir(void);

bool		is_path_a_directory(char *path);

/**
 * @brief: Prints an error message when the cd command fails.
*/
void		cd_error_msg(int destiny_len, char *destiny_path,
				int chdir_status);

/**
 * @brief: Checks if the builtin command has an argument.
*/
bool		checking_cmd_arg_options(char *lexeme, char *arg);

/**
 * @brief:
 * @param var_key the name of the variable to export.
 * @param var_value the value to be setted in the var_key.
*/
void		builtins_runner_export(char *arg);

/**
 * @brief: Handles the arguments of the export command.
 * @param env_vars the environment variables.
 * @param arg the argument to be handled, a lexeme from t_token_list.
*/
t_env_entry	*arg_handle_runner(t_env_entry *env_vars, char *arg);

/**
 * @brief: Handles the state of the argument to be exported.
 * @param arg the argument to be handled, a lexeme from t_token_list.
 * @param state the handler state of the argument.
 */
int			arg_handle_state_detector(int state, char *arg);

/**
 * @brief: Runs the unset - remove an environment variable - builtin command.
 * @param env_vars the environment variables.
 * @param arg the argument to be searched and later, removed.
 */
void		builtins_runner_unset(char *arg);

/**
 * @brief: Removes an environment variable from the environment table.
 * @param env_vars the environment variables.
 * @param arg the argument to be removed.
 */
t_env_entry	*removefrom_env_table(t_env_entry *toremove);

/**
 * @brief: Runs the env, which prints environment variables - builtin command.
 */
void		builtins_runner_env(void);

/**
 * @brief: Prints the environment variables in the classic bash format.
*/
void		ft_env_printer_classic(t_env_entry *env_vars);

/**
 * @brief: Sorts the environment variables.
 */
t_env_entry	*builtins_env_sort_manager(t_env_entry *env_vars);

/**
 * @brief: Checks if the environment variables are sorted.
 */
bool		builtins_is_env_sorted(t_env_entry *env_vars);

/**
 * @brief: Sort the environment variables list.
 */
t_env_entry	*sorted_env_insert(t_env_entry **head, t_env_entry *new);

/**
 * @brief: Runs the exit - exit the shell - builtin command.
 * @return the exit code, with an expected behaviour code from 0 to 255.
 */
void		builtins_runner_exit(t_token_list *lst);

/**
 * @brief: Manages the exit error messages.
 * @param cmd the command to be checked.
 * @param exit_code the exit code to be saved, if error.
 * @return the error exit code, with an expected behaviour code from 1 to 2.
 */
int			exit_error_manager(t_token_list *cmd, int exit_code);

int			exit_valid_code_manager(char *lexeme);

bool		long_long_min_detected(bool update, bool status);

/**
 * @brief: Manages the exit code, with a long long modulo operation.
 * @param lexeme the lexeme to be converted to a long long, if necessary.
 * @return the exit code, with an expected behaviour code from 0 to 255.
 */
int			long_long_overflow_validation(const char *lexeme);

/**
 * @brief: Checks if the exit code is not numeric, in the string.
 * @param lexeme the string to be checked.
 */
bool		exit_code_not_numeric(const char *lexeme);

/**
 * @brief: Holds the exit status of the shell.
 * @param exit_status Exit status number.
 */
int			exit_status_holder(int exit_status, bool update);

/**
 * @brief: Calls the exit status of the subprocess - fork.
 */
void		pid_exit_status_caller(pid_t pid);

/**
 * @brief: Clears all the memory allocated to exit the minishell smoothly.
 */
void		clear_all_to_exit_smoothly(void);

/**
 * @brief: Holds the argument option status.
 * @param update the update the statict arg status variable.
 * @param call_status the call the statict arg status variable.
 */
bool		arg_option_holder(bool update, bool call_status);

#endif