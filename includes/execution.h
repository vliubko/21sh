/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <vliubko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 14:42:06 by vliubko           #+#    #+#             */
/*   Updated: 2018/06/08 19:01:06 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

int		exe_command(char ***command);
int		pipe_fork_run(char ***cmd);
int		execve_cmd(char ***cmd);
int		fork_run_cmd(char *path, char ***d3_tab);
void	start_replace(char ***commands);

#endif
