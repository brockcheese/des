/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 02:42:59 by bpace             #+#    #+#             */
/*   Updated: 2020/01/09 22:32:44 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ssl_md5.h"

void		execute(char *str, char *alg)
{
	int	i;

	i = -1;
	while (++i < 5)
	{
		if (!ft_strcmp(g_algos[i].name, alg))
			g_algos[i].algo(&str);
	}
	free(str);
}

void		execute2(char *str, char *alg, t_data *data)
{
	int	i;

	i = -1;
	while (++i < 1)
		if (!ft_strcmp(g_desalgos[i].name, alg))
			g_desalgos[i].algo(&str, data);
	free(str);
}

int			pickaside(char *alg)
{
	int	i;

	i = -1;
	while (++i < 5)
		if (!ft_strcmp(g_algos[i].name, alg))
			return (1);
	i = -1;
	while (++i < 1)
	{
		if (!ft_strcmp(g_desalgos[i].name, alg))
			return (2);
	}
	return (-1);
}
