/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 16:10:53 by bpace             #+#    #+#             */
/*   Updated: 2020/01/09 22:13:41 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ssl_md5.h"

void		printthatshit(t_data *data, char **argv, char *str, int s)
{
	if (data->q == 0 && data->r == 0)
	{
		ft_printf("%s (", ft_strcap(data->alg));
		if (s == 1)
			ft_printf("\"%s\"", argv[data->ind]);
		else
			ft_printf("%s", argv[data->ind]);
		ft_printf(") = ");
	}
	execute(str, ft_strlow(data->alg));
	if (data->q == 0 && data->r == 1)
	{
		if (s == 1)
			ft_printf(" \"%s\"", argv[data->ind]);
		else
			ft_printf(" %s", argv[data->ind]);
	}
	ft_printf("\n");
}

void		checkflags(t_data *data, char **argv)
{
	while (argv[++(data->ind)] && argv[data->ind][0] == '-')
	{
		if (!ft_strcmp(argv[data->ind], "-p"))
		{
			data->p = 1;
			data->stdin = (data->stdin == NULL) ? getstdin(0) : data->stdin;
			ft_printf("%s", data->stdin);
			execute(data->stdin, ft_strlow(data->alg));
			ft_printf("\n");
			free(data->stdin);
			data->stdin = NULL;
		}
		if (!ft_strcmp(argv[data->ind], "-q"))
			data->q = 1;
		if (!ft_strcmp(argv[data->ind], "-r"))
			data->r = 1;
		if (!ft_strcmp(argv[data->ind], "-s"))
		{
			data->s = 1;
			printthatshit(data, argv, argv[++(data->ind)], 1);
		}
	}
}

void		eachfile(char **argv, t_data *data)
{
	int		fd;
	char	*stdin;

	fd = open(argv[data->ind], O_RDWR);
	if (fd > 0)
	{
		stdin = getstdin(fd);
		printthatshit(data, argv, stdin, 0);
		free(stdin);
	}
	else
		ft_printf("ft_ssl: %s: %s: No such file or directory\n",
		ft_strlow(data->alg), argv[data->ind]);
	data->ind++;
	close(fd);
}

void		hashroute(char **argv, t_data *data)
{
	checkflags(data, argv);
	if (!argv[data->ind] && data->p == 0 && data->s == 0)
	{
		data->stdin = (data->stdin == NULL) ? getstdin(0) : data->stdin;
		execute(data->stdin, ft_strlow(data->alg));
		ft_printf("\n");
		free(data->stdin);
		data->stdin = NULL;
	}
	while (argv[data->ind])
		eachfile(argv, data);
}

int			main(int argc, char **argv)
{
	t_data	*data;
	int		route;

	if (!(data = malloc(sizeof(t_data))))
		return (1);
	if (!errorcheck(argc, argv, data))
		return (1);
	initialize(data);
	route = pickaside(ft_strlow(data->alg));
	if (route == 1)
		hashroute(argv, data);
	else
		desroute(argv, data);
	if (argc == 1)
		free(data->alg);
	free(data);
	return (0);
}
