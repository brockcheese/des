/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dataman.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 17:54:14 by bpace             #+#    #+#             */
/*   Updated: 2020/01/10 19:16:00 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ssl_md5.h"

int			initialize(t_data *data)
{
	data->a = 0;
	data->d = 0;
	data->e = 0;
	data->i = 0;
	data->k = NULL;
	data->o = 1;
	data->p = 0;
	data->pass = NULL;
	data->q = 0;
	data->r = 0;
	data->s = 0;
	data->salt = NULL;
	data->v = NULL;
	data->stdin = NULL;
	return (1);
}
