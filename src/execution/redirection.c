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


/*
** Check if any redirection symbol in cmd_line
** Works only with first element of pipeline - d3_tab[0][i]
**
*/

int 	ft_has_redirect(char ***d3_tab)
{
	int 	i;
	int 	j;
	char 	*line;
	char 	c;

	i = 0;
	while (d3_tab[0][i])
	{
		line = d3_tab[0][i];
		j = 0;
		while (line[j])
		{
			c = line[j];
			if (c == '>' || c == '<')
				return (1);
			j++;
		}
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
	//var_dump(cmd);
	while (cmd[++i] && !(ft_strequ(cmd[i], ">")))
	{
		if (ft_strequ(cmd[i], ">>"))
		{
			*arrow = 2;
			break ;
		}
	}
	i++;
	if (!cmd[i])
		return NULL;
	file_name = ft_strdup(cmd[i]);
	return (file_name);
}

int		ft_redirection(char ***d3_tab)
{
	static int		fd;
	int		arrow;
	char 	*file_name;

	file_name = ft_redirect_arrow_type(&arrow, d3_tab[0]);
	if (file_name == NULL)
	{
		ft_putendl("Parse error");
		return (1);
	}
	if (arrow == 1)
	{
		fd = open(file_name, O_CREAT | O_RDWR | O_APPEND,
				  S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);

	}
	else if (arrow == 2)
	{
		fd = open(file_name, O_CREAT | O_RDWR | O_TRUNC,
				  S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	}
	close(1);
	dup(fd);
	//ft_putstr("File name: ");
	//ft_putendl(file_name);
	ft_strdel(&file_name);
	return (fd);
}