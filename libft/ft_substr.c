/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:06:23 by marvin            #+#    #+#             */
/*   Updated: 2024/09/07 12:24:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*test;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	if (len + start > ft_strlen(s))
		len = ft_strlen(s) - start;
	if (ft_strlen(s) < start)
		len = 0;
	test = malloc((len + 1) * sizeof(char));
	if (test == NULL)
		return (NULL);
	while (i < len && s[i])
	{
		test[i] = s[start];
		i++;
		start++;
	}
	test[i] = '\0';
	return (test);
}
