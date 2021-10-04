/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_utils_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 20:10:07 by kshanti           #+#    #+#             */
/*   Updated: 2021/10/04 20:10:08 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

int	ft_strlen(char *str)
{
	int	res;

	res = 0;
	while (str && str[res])
		res++;
	return (res);
}

char	*ft_strdup(char *s)
{
	char	*str;
	int		i;

	i = -1;
	str = (char *)malloc(ft_strlen(s) + 1);
	if (str)
		str[ft_strlen(s)] = '\0';
	while (str && s[++i])
		str[i] = s[i];
	return (str);
}

int	ft_strlcat(char *dst, char *src, int size)
{
	int	len;
	int	i;
	int	j;

	i = ft_strlen(dst);
	j = 0;
	len = i + ft_strlen(src);
	if (size <= i)
		return (ft_strlen(src) + size);
	while (i < (size - 1) && src[j])
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (len);
}
