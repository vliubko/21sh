/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 12:06:16 by vliubko           #+#    #+#             */
/*   Updated: 2018/06/07 22:42:29 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_21sh.h"

#define READ_END 0
#define WRITE_END 1

int    pipe_fork_run(char ***cmd)
{
    int     pipefd[2];
    pid_t   childpid;
    //char	**envp;
    int     fd_in = 0;

    //envp = list_to_array();

    while (*cmd != NULL)
    {
        pipe(pipefd);
        if ((childpid = fork()) == -1)
        {
            exit(EXIT_FAILURE);
        }
        else if (childpid == 0)
        {
            printf("Executing %s , fd_in: %d, pipefd[0]: %d, pipefd[1]: %d\n", (*cmd)[0], fd_in, pipefd[0], pipefd[1]);
            dup2(fd_in, 0); //change the input according to the old one
            if (*(cmd + 1) != NULL)
                dup2(pipefd[WRITE_END], 1);
            close(pipefd[READ_END]);
            execvp((*cmd)[0], *cmd);
            exit(0);
        }
        else
        {
            wait(&childpid);
            close(pipefd[WRITE_END]);
            fd_in = pipefd[READ_END]; //save the input for the next command
            cmd++;
        }
    }
    printf("Pipe returning now...\n");
    return (exe_cmd(cmd));
}