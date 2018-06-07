/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 14:00:51 by vliubko           #+#    #+#             */
/*   Updated: 2018/06/07 22:23:33 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_21sh.h"


void    var_dump(char **arr)
{
    int i = 0;
    for (i = 0; arr[i]; ++i)
        printf("\narr[%i] = \"%s\"", i, arr[i]);
}

void    var_dump_arr(char ***arr)
{
    for (int i = 0; arr[i]; i++)
    {
        printf("\nARRAY[%i]:", i);
        var_dump(arr[i]);
        printf("\n");
    }
}

int     exe_cmd(char ***cmd)
{
    char    **envp = list_to_array();

    //printf("Execve %s\n", (*cmd)[0]);
    execve((*cmd)[0], *cmd, envp);

    return (1);
}

int		fork_run_cmd(char *path, char ***d3_tab)
{
    pid_t	process;
    //int     status;
    char	**envp;

    //var_dump_arr(d3_tab);

    process = fork();
    envp = list_to_array();
    if (process == 0)
    {
        if (*(d3_tab + 1) != NULL)
        {
            pipe_fork_run(d3_tab);
        } // check for pipes
        exe_cmd(d3_tab);
        exit(0);
    }
    else
    {
        wait(&process);
//        if (WIFEXITED(status))
//        {
//            if (WEXITSTATUS(status) != 0)
//                return (-1);
//        }
    }
    ft_free_2d_array(envp);
    (path) ? ft_strdel(&path) : 0;
    return (1);
}

int		access_check(char *path, struct stat f, char ***command)
{
    if (f.st_mode & S_IFREG)
    {
        if (f.st_mode & S_IXUSR)
            return (fork_run_cmd(path, command));
        else
        {
            ft_putstr_fd("21sh: permission denied: ", 2);
            ft_putendl(path);
        }
        ft_strdel(&path);
        return (1);
    }
    ft_strdel(&path);
    return (0);
}

int		check_builtins(char ***command)
{
    if (ft_strequ((*command)[0], "exit"))
        return (-1);
    if (ft_strequ((*command)[0], "echo"))
        return (bi_echo((*command) + 1));
    if (ft_strequ((*command)[0], "cd"))
        return (bi_cd((*command) + 1));
    if (ft_strequ((*command)[0], "clear"))
        return (bi_clear());
    if (ft_strequ((*command)[0], "env"))
        return (bi_env());
    if (ft_strequ((*command)[0], "setenv"))
        return (bi_setenv((*command) + 1));
    if (ft_strequ((*command)[0], "unsetenv"))
        return (bi_unsetenv((*command) + 1));
    return (0);
}

int		check_bins(char ***command)
{
    char			**path;
    int				i;
    char			*full_path;
    struct stat		f;


    full_path = get_env_value_by_name("PATH");
    path = ft_strsplit(full_path, ':');
    ft_strdel(&full_path);
    i = -1;

    while (path && path[++i])
    {
        if ((**command)[0] == '/')
            full_path = ft_strdup((*command)[0]);
        else
            full_path = ft_pathjoin(path[i], (*command)[0]);
        if (lstat(full_path, &f) == -1)
            ft_strdel(&full_path);
        else
        {
            ft_strdel((&*command)[0]);
            (*command)[0] = ft_strdup(full_path);
            ft_free_2d_array(path);
            return (access_check(full_path, f, command));
        }
    }
    ft_free_2d_array(path);
    return (0);
}

//int		run_binary_from_line(char *path, char ***command)
//{
//    struct stat		f;
//
//    if (lstat(path, &f) != -1)
//    {
//        if (f.st_mode & S_IFDIR)
//            return (cd_standart(ft_strdup(path)));
//        else if (f.st_mode & S_IXUSR)
//            return (fork_run_cmd(ft_strdup(path), command));
//        else
//        {
//            ft_putstr_fd("21sh: permission denied: ", 2);
//            ft_putendl(path);
//            return (1);
//        }
//    }
//    return (0);
//}

int		exe_command(char ***command)
{
    int				bi;

    if (!(**command))
        return (0);
    if ((bi = check_builtins(command)) == 1 || check_bins(command))
        return (1);
    if (bi == -1)
        return (-1);
//    if (run_binary_from_line((*command)[0], command) == 1)
//        return (1);
    ft_putstr_fd("21sh: command not found: ", 2);
    ft_putendl((*command)[0]);
    return (0);
}