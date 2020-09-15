/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fghi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 21:36:57 by bpace             #+#    #+#             */
/*   Updated: 2020/01/08 21:47:52 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ssl_md5.h"

int		dumbf(u_int32_t b, u_int32_t c, u_int32_t d)
{
	return (((b) & (c)) | (~(b) & (d)));
}

int		dumbg(u_int32_t b, u_int32_t c, u_int32_t d)
{
	return (((b) & (d)) | ((c) & ~(d)));
}

int		dumbh(u_int32_t b, u_int32_t c, u_int32_t d)
{
	return ((b) ^ (c) ^ (d));
}

int		dumbi(u_int32_t b, u_int32_t c, u_int32_t d)
{
	return ((c) ^ (b | ~(d)));
}
