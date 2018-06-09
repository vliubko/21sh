/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_replace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <vliubko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 18:27:53 by vliubko           #+#    #+#             */
/*   Updated: 2018/06/08 19:00:56 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_21sh.h"

int		ft_strchr_index(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	if (s[i] == c)
		return (i);
	return (-1);
}

char	*dollar_replace(char *needle)
{
	char	*new;

	new = get_env_value_by_name(needle);
	if (!new)
		return (NULL);
	return (new);
}

char	*replace_tail_dollar(char *str)
{
	char	*tail;
	char	*head;
	int		index;

	tail = ft_strchr(str, '$');
	index = ft_strchr_index(str, '$');
	tail = dollar_replace(++tail);
	if (!tail)
		return (NULL);
	head = ft_strsub(str, 0, index);
	ft_strdel(&str);
	return (ft_strjoin_free(head, tail, 1));
}

void	start_replace(char ***commands)
{
	char	**cmd;
	char	*str;
	int		i;
	int		j;
	char	*tmp;

	j = -1;
	while (commands[++j])
	{
		cmd = commands[j];
		i = -1;
		while (cmd[++i])
		{
			str = cmd[i];
			if (*str == '$')
			{
				tmp = str;
				cmd[i] = dollar_replace(++str);
				ft_strdel(&tmp);
			}
			else if (ft_strchr(str, '$'))
				cmd[i] = replace_tail_dollar(str);
		}
	}
}
