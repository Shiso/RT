/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeniset <tdeniset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:25:48 by tdeniset          #+#    #+#             */
/*   Updated: 2013/11/22 11:37:34 by tdeniset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlen(char *s1);

char	*ft_strcat(char *s1, const char *s2)
{
	unsigned int	len;
	unsigned int	len2;
	unsigned int	i;

	i = 0;
	len = ft_strlen((char *)s1);
	len2 = len + ft_strlen((char *)s2);
	while (len <= len2)
	{
		*(char *)(s1 + len) = *(char *)(s2 + i);
		len++;
		i++;
	}
	return (s1);
}
