/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 18:27:28 by bpace             #+#    #+#             */
/*   Updated: 2020/01/10 19:15:23 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ssl_md5.h"

void	checkdesflags(char **argv, t_data *data)
{
	while (argv[++(data->ind)] && argv[data->ind][0] == '-')
	{
		data->a = (!ft_strcmp(argv[data->ind], "-a")) ? 1 : data->a;
		data->d = (!ft_strcmp(argv[data->ind], "-d")) ? 1 : data->d;
		data->e = (!ft_strcmp(argv[data->ind], "-e")) ? 1 : data->e;
		data->i = (!ft_strcmp(argv[data->ind], "-i")) ?
			open(argv[++(data->ind)], O_RDONLY) : data->i;
		data->k = (!ft_strcmp(argv[data->ind], "-k")) ?
			argv[++(data->ind)] : data->k;
		data->o = (!ft_strcmp(argv[data->ind], "-o")) ?
			open(argv[++(data->ind)], O_WRONLY) : data->o;
		data->pass = (!ft_strcmp(argv[data->ind], "-p")) ?
			argv[++(data->ind)] : data->pass;
		data->salt = (!ft_strcmp(argv[data->ind], "-s")) ?
			argv[++(data->ind)] : data->salt;
		data->v = (!ft_strcmp(argv[data->ind], "-v")) ?
			argv[++(data->ind)] : data->v;
	}
}

void	desroute(char **argv, t_data *data)
{
	checkdesflags(argv, data);
	data->stdin = getstdin(data->i);
	execute2(data->stdin, ft_strlow(data->alg), data);
	if (data->i != 0)
		close(data->i);
	if (data->o != 1)
		close(data->o);
}
