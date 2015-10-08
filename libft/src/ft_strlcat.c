/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeniset <tdeniset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:49:52 by tdeniset          #+#    #+#             */
/*   Updated: 2013/12/06 10:51:37 by tdeniset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlen(const char *str);

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	unsigned int	len;
	unsigned int	len2;
	unsigned int	i;
	unsigned int	res;

	i = 0;
	len = ft_strlen((const char *)dst);
	len2 = ft_strlen((const char *)src);
	res = len2;
	res += (len > size) ? size : len;
	while (len + 1 < size)
	{
		dst[len] = src[i];
		len++;
		i++;
	}
	*(char *)(dst + len) = '\0';
	return (res);
}
