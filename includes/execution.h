/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 14:42:06 by vliubko           #+#    #+#             */
/*   Updated: 2018/07/20 10:58:34 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

int		exe_command(char ***command);
int		pipe_fork_run(char ***cmd);
int		execve_cmd(char ***cmd);
int		fork_run_cmd(char *path, char ***d3_tab);
void	start_replace(char ***commands);
int 	ft_has_redirect(char ***d3_tab);
int		ft_redirection(char ***d3_tab);

#endif
