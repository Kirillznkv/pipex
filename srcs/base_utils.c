/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 01:02:29 by kshanti           #+#    #+#             */
/*   Updated: 2021/07/27 01:32:38 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	ft_strlen(char *str)
{
	int res;

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

// int	ft_strlcat(char *dst, char *src, int size)
// {
// 	int	len;
// 	int	i;
// 	int	j;

// 	i = ft_strlen(dst);
// 	j = 0;
// 	len = i + ft_strlen(src);
// 	if (size <= i)
// 		return (ft_strlen(src) + size);
// 	while (i < (size - 1) && src[j])
// 		dst[i++] = src[j++];
// 	dst[i] = '\0';
// 	return (len);
// }

// char    *ft_strjoin(char *s1, char *s2)
// {
// 	char	*str;

// 	if (s1 == NULL || s2 == NULL)
// 		return (NULL);
// 	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
//     str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
// 	if (str)
// 	{
// 		ft_strlcat(str, s1, ft_strlen(s1) + 1);
// 		ft_strlcat(str, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
// 	}
// 	return (str);
// }
