/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 19:19:38 by vliubko           #+#    #+#             */
/*   Updated: 2018/07/20 11:07:43 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_21sh.h"

int 	ft_has_redirect(char *cmd_line)
{
	int 	i;
	char 	c;

	i = 0;
	while (cmd_line[i])
	{
		c = cmd_line[i];
		if (c == '>' || c == '<')
			return (1);
		i++;
	}
	return (0);
}

char  	*ft_redirect_arrow_type(int *arrow, char **cmd)
{
	int		i;
	char	*file_name;

	i = -1;
	*arrow = 1;
	while (cmd[++i] && !(ft_strequ(cmd[i], ">")))
	{
		if (ft_strequ(cmd[i], ">>"))
		{
			*arrow = 2;
			break ;
		}
	}
	i++;
	file_name = ft_strdup(cmd[i]);
	return (file_name);
}

void	ft_redirection(char **cmd)
{
	static int		fd;
	int		arrow;
	char 	*file_name;

	file_name = ft_redirect_arrow_type(&arrow, cmd);
	if (arrow == 1)
	{
		fd = open(file_name, O_CREAT | O_RDWR | O_APPEND,
				  S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
		dup2(fd, 1);
	}
	else if (arrow == 2)
	{
		fd = open(file_name, O_CREAT | O_RDWR | O_TRUNC,
				  S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
		dup2(fd, 1);
	}
	close(fd);
	ft_strdel(&file_name);
}