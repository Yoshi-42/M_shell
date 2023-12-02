/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:32:17 by artmarti          #+#    #+#             */
/*   Updated: 2023/12/02 15:32:18 by artmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int check_place_space(char *cmd)
{
    int i;

    i = 0;
    while(cmd[i])
    {
        if (cmd[i] == '=')
            return (i);
        i++;
    }
    return (-1);
}

int check_exist(char *cmd, t_env *env, int n)
{
    int i;

    i = 0;
    while (env->env_cpy[i] != NULL)
    {
        if (ft_strncmp(cmd, env->env_cpy[i], n) == 0)
            return (i);
        i++;
    }
    return (-1);
}

int     tabtab_strlen(char **tab)
{
    int i;

    i = 0;
    if (!tab)
        return (0);
    while (tab[i])
        i++;
    return (i);
}

char	**tabtab_strjoin(char *cmd, char **env)
{
    int len;
    char **dest;
    int i;

    i = 0;
    len = tabtab_strlen(env);
    dest = malloc(sizeof(char *) * (len + 2));
    while (env[i])
    {
        dest[i] = ft_strdup(env[i]);
        i++;
    }
    dest[i] = ft_strdup(cmd);
    dest[i + 1] = NULL;
    return (dest);
}

int	m_export(char **cmds, t_env *env)
{
    int	j;

	j = 1;
	if (!cmds[1])
        m_env(env->env_cpy);
    else
    {
        while (cmds[j])
        {
            if (ft_strchr(cmds[j], '=') != 0 && cmds[j][0] != '=')
            {
                if(check_exist(cmds[j], env, check_place_space(cmds[j])) >= 0)
			        env->env_cpy[check_exist(cmds[j], env, check_place_space(cmds[j]))] = ft_strdup(cmds[j]);
                else
                    env->env_cpy = tabtab_strjoin(cmds[j], env->env_cpy);
            }
            j++;
        }
    }
    return (1);
}
