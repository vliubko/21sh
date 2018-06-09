/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <vliubko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 12:06:16 by vliubko           #+#    #+#             */
/*   Updated: 2018/06/08 19:29:23 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_21sh.h"

#define READ_END 0
#define WRITE_END 1

void	child_pipe_run(int fd_in, int pipefd[], char ***cmd)
{
	dup2(fd_in, 0);
	if (*(cmd + 1) != NULL)
		dup2(pipefd[WRITE_END], 1);
	close(pipefd[READ_END]);
	execvp((*cmd)[0], *cmd);
	exit(0);
}

int		pipe_fork_run(char ***cmd)
{
	int		pipefd[2];
	pid_t	childpid;
	int		fd_in;

	fd_in = 0;
	while (*cmd != NULL)
	{
		pipe(pipefd);
		childpid = fork();
		if (childpid == 0)
			child_pipe_run(fd_in, pipefd, cmd);
		else
		{
			waitpid(childpid, NULL, 0);
			close(pipefd[WRITE_END]);
			fd_in = pipefd[READ_END];
			cmd++;
		}
	}
	return (execve_cmd(cmd));
}
