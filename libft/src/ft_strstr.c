/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeniset <tdeniset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 13:42:12 by tdeniset          #+#    #+#             */
/*   Updated: 2013/11/26 13:46:22 by tdeniset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	unsigned int	len;
	char			*str;
	int				i;

	i = 0;
	if (s2[i] == '\0')
		return ((char *)s1);
	str = (char *)s1;
	len = ft_strlen(s2);
	while (str[i] != '\0')
	{
		if (ft_strncmp(str + i, s2, len - 1) == 0)
			return (str + i);
		i++;
	}
	return (0);
}
