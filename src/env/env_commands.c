/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 14:26:14 by vliubko           #+#    #+#             */
/*   Updated: 2018/06/04 14:28:13 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_21sh.h"

char	*get_env_value_by_name(char *key)
{
	t_env	*tmp;

	tmp = g_env;
	while (tmp)
	{
		if (ft_strequ(tmp->key, key))
			return (ft_strdup(tmp->value));
		tmp = tmp->next;
	}
	return (NULL);
}

void	change_env_value_by_name(char *key, char *value)
{
	t_env	*tmp;
	char	*leak_remove;

	tmp = g_env;
	while (tmp)
	{
		if (ft_strequ(tmp->key, key))
		{
			leak_remove = tmp->value;
			tmp->value = ft_strdup(value);
			ft_strdel(&leak_remove);
			return ;
		}
		tmp = tmp->next;
	}
}

void	add_env_value(char *key, char *value)
{
	t_env	*tmp;
	t_env	*new_node;

	tmp = g_env;
	new_node = (t_env*)ft_memalloc(sizeof(t_env));
	new_node->key = ft_strdup(key);
	new_node->value = ft_strdup(value);
	new_node->next = NULL;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_node;
}

void	remove_env_value_by_name(char *key)
{
	t_env	*tmp;
	t_env	*prev;

	tmp = g_env;
	prev = NULL;
	while (!(ft_strequ(tmp->key, key)) && tmp->next != NULL)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (ft_strequ(tmp->key, key))
	{
		if (prev)
			prev->next = tmp->next;
		else
			g_env = tmp->next;
		ft_strdel(&tmp->key);
		ft_strdel(&tmp->value);
		free(tmp);
	}
}
