/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 19:49:00 by vliubko           #+#    #+#             */
/*   Updated: 2018/07/07 15:27:38 by vliubko          ###   ########.fr       */
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
        if (**str == search_for)
        {
            search_for_next = search_for;
            (*str)++;
            if (check_quotes(str, search_for_next) == -1)
                return (-1);
        }
        else if ((**str == '"' && **str != search_for))
            return (-1);
        (*str)++;
    }
    if (**str == search_for)
        return (0);
    return (-1);
}


/*
** Internal loop as shell loop.
*/

void    wait_quote(void)
{
    char	key[8];
    char    *tmp;

    tmp = ft_strdup(g_data.cmd_line);
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
            if (check_quotes(&tmp, '\"') == OK)
                break ;
            else
            {
                ft_putstr("\nq> ");
                continue ;
            }


        }
        move_cursor_choose(key);
    }
    clear_cmd_line();
    ft_strcpy(g_data.cmd_line, tmp);
}

/*
** If no quotes found, return immediately.
** Else, go to quote loop, waiting for quote closure.
*/

 void    quotes_start(void)
{
    char    *tmp;

    tmp = ft_strdup(g_data.cmd_line);
    if (ft_strchr(g_data.cmd_line, '"') == NULL)
        return ;
    else if (check_quotes(&tmp, '\0') != OK)
        wait_quote();
    //ft_strdel(&tmp);
}