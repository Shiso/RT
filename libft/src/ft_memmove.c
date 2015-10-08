/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeniset <tdeniset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 12:01:35 by tdeniset          #+#    #+#             */
/*   Updated: 2013/11/21 16:53:58 by tdeniset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *s1, const void *s2, size_t n);

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	char		*dest;
	const char	*src;

	dest = s1;
	src = s2;
	if (!n)
		return (s1);
	if (s1 <= s2)
		return ((void *)ft_memcpy(s1, s2, n));
	dest += n;
	src += n;
	while (n--)
		*--dest = *--src;
	return (s1);
}
