/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 14:42:06 by vliubko           #+#    #+#             */
/*   Updated: 2018/07/14 19:22:32 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

int		exe_command(char ***command);
int		pipe_fork_run(char ***cmd);
int		execve_cmd(char ***cmd);
int		fork_run_cmd(char *path, char ***d3_tab);
void	start_replace(char ***commands);
int 	ft_has_redirect(char *cmd_line);
void	ft_redirection(char **cmd);

#endif
