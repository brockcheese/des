/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_md5.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 16:11:45 by bpace             #+#    #+#             */
/*   Updated: 2020/01/10 19:11:21 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_MD5_H
# define FT_SSL_MD5_H
# include <fcntl.h>
# include "libft/libft.h"
# define TAB "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"

typedef struct			s_exec
{
	char				*name;
	void				(*algo)(char **);
}						t_exec;

typedef struct			s_data
{
	int					a;
	int					d;
	int					e;
	char				*k;
	int					i;
	int					o;
	int					p;
	char				*pass;
	int					q;
	int					r;
	int					s;
	char				*salt;
	char				*v;
	int					ind;
	char				*stdin;
	char				*alg;
}						t_data;

typedef struct			s_desexec
{
	char				*name;
	void				(*algo)(char **, t_data *);
}						t_desexec;

extern t_exec			g_algos[];
extern t_desexec		g_desalgos[];
extern u_int32_t		g_k[64];
extern u_int32_t		g_r[64];
extern u_int32_t		g_sha256k[64];
extern u_int64_t		g_sha512k[80];

void					md5(char **input);
void					base64(char **input, t_data *data);
int						pickaside(char *alg);
void					sha224(char **input);
void					sha256(char **input);
void					sha384(char **input);
void					sha512(char **input);
size_t					padding(char **input);
char					*getstdin(const int fd);
size_t					getfull_len(char *input);
int						initialize(t_data *data);
u_int32_t				endianness(u_int32_t hashi);
size_t					sha256padding(char **input);
size_t					sha512padding(char **input);
u_int32_t				rr(u_int32_t x, u_int32_t c);
u_int64_t				endianness64(u_int64_t hashi);
void					execute(char *str, char *alg);
u_int64_t				rr512(u_int64_t x, u_int64_t c);
void					desroute(char **argv, t_data *data);
void					freeargv(char **argv, int argcheck);
void					compress(u_int32_t *w, u_int32_t *hash);
void					compress512(u_int64_t *w, u_int64_t *hash);
void					process_w(u_int32_t *w, char *singlechunk);
void					execute2(char *str, char *alg, t_data *data);
int						dumbf(u_int32_t b, u_int32_t c, u_int32_t d);
int						dumbg(u_int32_t b, u_int32_t c, u_int32_t d);
int						dumbh(u_int32_t b, u_int32_t c, u_int32_t d);
int						dumbi(u_int32_t b, u_int32_t c, u_int32_t d);
void					fghi(u_int32_t *singlechunk, u_int32_t *hash);
void					process_w512(u_int64_t *w, char *singlechunk);
int						errorcheck(int argc, char **argv, t_data *data);
void					sha256_round(u_int32_t *w, u_int32_t *hasheight);
void					sha512_round(u_int64_t *w, u_int64_t *hasheight);
char					*ft_strncpy_unsafe(char *dest, char *src,
							unsigned int n);

#endif
