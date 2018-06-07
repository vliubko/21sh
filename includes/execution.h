/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 14:42:06 by vliubko           #+#    #+#             */
/*   Updated: 2018/06/07 20:16:24 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
#define EXECUTION_H

int		exe_command(char ***command);
int     pipe_fork_run(char ***cmd);
int     exe_cmd(char ***cmd);

#endif