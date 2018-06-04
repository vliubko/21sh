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