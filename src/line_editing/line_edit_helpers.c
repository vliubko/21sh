/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_edit_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 13:41:55 by vliubko           #+#    #+#             */
/*   Updated: 2018/05/30 14:35:21 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_21sh.h"

void	clear_cmd_line(void)
{
	ft_bzero(g_data.cmd_line, 4096);
}

void	realloc_cmd_line(char *head, char *new_tail)
{
	clear_cmd_line();
	ft_strcat(g_data.cmd_line, head);
	ft_strcat(g_data.cmd_line, new_tail);
	ft_strdel(&new_tail);
	ft_strdel(&head);
}