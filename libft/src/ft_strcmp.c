/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeniset <tdeniset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:51:19 by tdeniset          #+#    #+#             */
/*   Updated: 2013/11/25 15:09:34 by tdeniset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	while ((s2[i] != '\0') && (s1[i] != '\0') && (s1[i] == s2[i]))
		i++;
	if (s1[i] > s2[i] || s1[i] < s2[i])
		return (s1[i] - s2[i]);
	return (0);
}
