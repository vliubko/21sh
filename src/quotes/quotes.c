/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 19:49:00 by vliubko           #+#    #+#             */
/*   Updated: 2018/07/02 20:28:18 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_21sh.h"

/*
** If quotes are OK, return 1. If not finished quote, return 0.
** First, check if any quote in line. Return 1, if not.
** Then check if any unfinished quote in line. Return 0, if any.
*/

 int    quotes_check(void)
{
    char    *head;
    char    *cmd;
    int     ret;

    head = ft_strdup(g_data.cmd_line);
    if (ft_strchr(head, '"') == NULL)
        ret = 1;
    else
    {
        cmd = ft_strchr(head, '"') + 1;
        ret = 0;
        while (*cmd)
        {
            cmd = ft_strchr(cmd, '"') + 1;
            if (!cmd)
                ret = 0;
            else
                ret = 1;
        }
    }
    ft_strdel(&head);
    return (ret);
}
