/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vliubko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 12:53:19 by vliubko           #+#    #+#             */
/*   Updated: 2018/06/08 12:53:19 by vliubko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_21sh.h"

char	**list_to_array(void)
{
	t_env	*list;
	char	**ret;
	char	*tmp;
	int		new_size;

	list = g_env;
	new_size = ft_count_elems((t_list*)list, NULL, 1);
	ret = (char**)malloc((sizeof(char*) * (new_size + 1)));
	new_size = 0;
	while (list)
	{
		tmp = ft_strjoin(list->key, "=");
		ret[new_size] = ft_strjoin(tmp, list->value);
		ft_strdel(&tmp);
		new_size++;
		list = list->next;
	}
	ret[new_size] = NULL;
	return (ret);
}

void	env_init(int ac, char **av, char **envp)
{
	int		i;
	t_env	*head;

	(void)ac;
	(void)av;
	i = 0;
	g_env = (t_env*)ft_memalloc(sizeof(t_env));
	head = g_env;
	while (envp[i])
	{
		g_env->key = ft_strsub(envp[i], 0, ft_strchr(envp[i], '=') - envp[i]);
		g_env->value = ft_strdup(ft_strchr(envp[i], '=') + 1);
		if (!envp[++i])
			break ;
		g_env->next = (t_env*)ft_memalloc(sizeof(t_env));
		g_env = g_env->next;
	}
	g_env = head;
}
