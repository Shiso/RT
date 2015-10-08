/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeniset <tdeniset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:50:50 by tdeniset          #+#    #+#             */
/*   Updated: 2013/11/26 13:46:16 by tdeniset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlen(const char *);
int		ft_strncmp(char *, const char *, size_t);

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	unsigned int	len;
	char			*str;
	unsigned int	i;

	i = 0;
	if (s2[i] == '\0')
		return ((char *)s1);
	str = (char *)s1;
	len = ft_strlen(s2);
	while (str[i] != '\0' && (i + len) <= n)
	{
		if (ft_strncmp(str + i, s2, len - 1) == 0)
			return (str + i);
		i++;
	}
	return (0);
}
