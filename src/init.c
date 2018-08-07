/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 13:00:38 by vliubko           #+#    #+#             */
/*   Updated: 2018/07/07 15:44:54 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_21sh.h"

void	shell_init(char **av)
{
	g_data.pos = PROMPT_LEN;
	g_data.multi_line_count = 0;
	clear_cmd_line();
	ft_bzero(g_data.buf_cmd_line, 4096);
	history_init();
	if (!(av[1]) && !(ft_strequ(av[1], "-d")))
		set_raw_mode();
}
