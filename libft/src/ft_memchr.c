/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeniset <tdeniset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:46:58 by tdeniset          #+#    #+#             */
/*   Updated: 2013/11/26 14:35:27 by tdeniset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s1, int c, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n && *(char *)s1 != '\0')
	{
		if (*(char *)(s1 + i) == (char)c)
			return ((void *)(s1 + i));
		i++;
	}
	return (NULL);
}
