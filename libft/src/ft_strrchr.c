/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeniset <tdeniset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:50:18 by tdeniset          #+#    #+#             */
/*   Updated: 2013/11/22 12:44:37 by tdeniset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlen(const char *str);

char	*ft_strrchr(const char *s1, int c)
{
	unsigned int	len;

	len = ft_strlen(s1);
	if ((char)c == '\0')
		return ((char *)(s1 + len));
	while (len--)
	{
		if (s1[len] == (char)c)
			return ((char *)(s1 + len));
	}
	return (0);
}
