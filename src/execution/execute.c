/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 12:48:33 by vliubko           #+#    #+#             */
/*   Updated: 2018/06/08 12:48:33 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_21sh.h"

int		execve_cmd(char ***cmd)
{
	char	**envp;

	envp = list_to_array();
	execve((*cmd)[0], *cmd, envp);
	return (1);
}

int		fork_run_cmd(char *path, char ***d3_tab)
{
	pid_t	process;
	char	**envp;

	process = fork();
	envp = list_to_array();
	if (process == 0)
	{
		if (*(d3_tab + 1) != NULL)
			pipe_fork_run(d3_tab);
		execve_cmd(d3_tab);
		exit(0);
	}
	else
	{
		waitpid(process, NULL, 0);
	}
	ft_free_2d_array(envp);
	(path) ? ft_strdel(&path) : 0;
	return (1);
}
