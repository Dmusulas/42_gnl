/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:37:37 by dmusulas          #+#    #+#             */
/*   Updated: 2023/11/30 20:43:03 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*cdest;
	const unsigned char	*csrc;

	cdest = dest;
	csrc = src;
	if (dest == src || n == 0)
		return (dest);
	while (n--)
		*cdest++ = *csrc++;
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	char	char_c;

	char_c = (char) c;
	while (*s)
	{
		if (*s == char_c)
			return ((char *)s);
		s++;
	}
	if (*s == char_c)
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	total_len;
	size_t	s1_len;
	size_t	s2_len;
	char	*new_s;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	total_len = s1_len + s2_len + 1;
	new_s = malloc(sizeof(char) * total_len);
	if (!new_s)
		return (NULL);
	ft_memcpy(new_s, s1, s1_len);
	ft_memcpy(new_s + s1_len, s2, s2_len + 1);
	return (new_s);
}
