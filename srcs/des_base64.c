/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   des_base64.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 19:33:58 by bpace             #+#    #+#             */
/*   Updated: 2020/01/10 20:45:37 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ssl_md5.h"

void	transblock(char *block, int letters, t_data *data)
{
	int		bits;
	int		i;
	int		mask;

	bits = 0x000000;
	mask = 0x00003f;
	i = -1;
	while (++i < 3)
	{
		bits <<= 8;
		bits |= (i < letters) ? block[i] : 0;
	}
	i = 4;
	while (letters-- >= 0)
		write(data->o, &(TAB[(bits >> (--i * 6)) & mask]), 1);
	while (--i >= 0)
		write(data->o, "=", 1);
}

void	base64e(char **input, t_data *data)
{
	char	block[3];
	int		i;
	int		num;

	i = -1;
	num = 0;
	while ((*input)[++i])
	{
		if ((*input)[i] != ' ' && (*input)[i] != 11 && (*input)[i] != 13)
			block[num++] = (*input)[i];
		if (num == 3 || !((*input)[i + 1]))
		{
			transblock(block, num, data);
			num = 0;
		}
	}
	write(data->o, "\n", 1);
}

char	*dtransblock(char *block)
{
	int		bits;
	int		i;
	char	*ans;
	int		mask;

	bits = 0x000000;
	i = -1;
	while (++i < 4)
	{
		bits <<= 6;
		mask = -1;
		while (block[i] != '=' && TAB[++mask] != block[i])
			;
		bits ^= (mask == -1) ? 0 : mask;
	}
	mask = 0x0000ff;
	i = 3;
	ans = malloc(sizeof(char) * 4);
	ans[3] = '\0';
	ans[2] = ' ';
	ans[1] = ' ';
	while (--i > -1 && block[3 - i] != '=')
		ans[2 - i] = (char)((bits >> (i * 8)) & mask);
	return (ans);
}

char	*base64d(char **input)
{
	char	block[4];
	int		i;
	int		num;
	char	*temp;
	char	*ans;

	i = -1;
	num = 0;
	ans = ft_memalloc(sizeof(char) * 1);
	while ((*input)[++i])
	{
		if ((*input)[i] != ' ' && (*input)[i] != 11 && (*input)[i] != 13)
			block[num++] = (*input)[i];
		if (num == 4)
		{
			temp = dtransblock(block);
			ft_strcpy(block, temp);
			free(temp);
			temp = ft_strjoin(ans, block);
			free (ans);
			ans = temp;
			num = 0;
		}
	}
	return (ans);
}

void	base64(char **input, t_data *data)
{
	char	*ans;
	char	*temp;

	if (data->d == 1)
	{
		temp = base64d(input);
		ans = ft_strtrim(temp);
		free(temp);
		write(data->o, ans, ft_strlen(ans));
		free (ans);
	}
	else
		base64e(input, data);
}
