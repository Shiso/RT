/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeniset <tdeniset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:51:28 by tdeniset          #+#    #+#             */
/*   Updated: 2013/12/31 18:44:16 by tdeniset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		i;

	i = 0;
	if ((!s2[i]) && (!s1[i]) && !n)
		return (0);
	while (s1[i] && s2[i] && (n--))
	{
		if (s1[i] < s2[i])
			return (s1[i] - s2[i]);
		else if (s1[i] > s2[i])
			return ((char)s1[i] - (char)s2[i]);
		i++;
	}
	if (!n)
		return (0);
	return ((char)s1[i] - (char)s2[i]);
}
