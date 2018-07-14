/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 19:49:00 by vliubko           #+#    #+#             */
/*   Updated: 2018/07/14 15:03:56 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_21sh.h"

#define OK 0

/*
** Based on brackets task from 42 exam.
** Checking for next quote recursively.
** If all recursive functions return 0, all quotes have pair.
*/

int		check_quotes(char **str, char search_for)
{
    char	search_for_next;

    while (**str != '\0' && **str != search_for)
    {
        if (**str == '\"')
        {
            search_for_next = '\"';
            (*str)++;
            if (check_quotes(str, search_for_next) == -1)
                return (-1);
        }
        else if ((**str == '"' && **str != search_for))
            return (-1);
        (*str)++;
    }
    if (**str == search_for)
        return (OK);
    return (-1);
}


/*
** Internal loop as shell loop.
*/

void    wait_quote(void)
{
    char	key[8];
    char    *tmp;
    char    *head;

    tmp = ft_strdup(g_data.cmd_line);
    ft_putstr("\nq> ");
    clear_cmd_line();
    g_data.pos = PROMPT_LEN;
    while (42)
    {
        get_winsize();
        ft_bzero(key, 8);
        read(0, &key, 8);
        if (key[0] == ENTER)
        {
            tmp = ft_strjoin_free(tmp, g_data.cmd_line, 0);
            clear_cmd_line();
            g_data.pos = PROMPT_LEN;
            head = tmp;
            if (check_quotes(&tmp, '\0') == OK)
            {
                tmp = head;
                break ;
            }
            else
            {
                ft_putstr("\nq> ");
                tmp = head;
                continue ;
            }
        }
        move_cursor_choose(key);
    }
    clear_cmd_line();
    ft_strcat(g_data.cmd_line, tmp);
	ft_strdel(&tmp);
}

/*
** If no quotes found, return immediately.
** Else, go to quote loop, waiting for quote closure.
*/

 void    quotes_start(void)
{
    char    *cmd;
    char    *head;

	cmd = ft_strdup(g_data.cmd_line);
    head = cmd;
    if (ft_strchr(g_data.cmd_line, '"') == NULL)
	{
		ft_strdel(&cmd);
		return;
	}
    else if (check_quotes(&cmd, '\0') != OK)
        wait_quote();
    ft_strdel(&head);
}