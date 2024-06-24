/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:37:37 by dmusulas          #+#    #+#             */
/*   Updated: 2023/12/06 16:48:00 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * Copies memory from source to destination.
 *
 * This function copies `n` bytes from the memory area `src` to the memory area
 * `dest`. The memory areas should not overlap, as this would lead to
 * undefined behavior.
 *
 * @param dest The destination memory area.
 * @param src The source memory area.
 * @param n The number of bytes to copy.
 * @return A pointer to the destination memory area.
 */
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

/**
 * Locates the first occurrence of a character in a string.
 *
 * This function searches for the first occurrence of the character `c` in
 * the string `s`. The terminating null byte is considered part of the string.
 *
 * @param s The string to search.
 * @param c The character to search for.
 * @return A pointer to the first occurrence of the character in the string,
 *         or `NULL` if the character is not found.
 */
char	*ft_strchr(const char *s, int c)
{
	char	char_c;

	char_c = (char)c;
	if (!s)
		return (NULL);
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

/**
 * Calculates the length of a string.
 *
 * This function returns the number of characters in the string `s`, excluding
 * the terminating null byte.
 *
 * @param s The string to measure.
 * @return The number of characters in the string.
 */
size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}

/**
 * Duplicates a string.
 *
 * This function allocates memory and copies the string `s` into it. The
 * memory allocated for the new string should be freed by the caller.
 *
 * @param s The string to duplicate.
 * @return A pointer to the newly allocated string, or `NULL` if the
 *         allocation fails.
 */
char	*ft_strdup(const char *s)
{
	char	*new;
	size_t	len;

	if (!s || !*s)
		return (NULL);
	len = ft_strlen(s) + 1;
	new = malloc(sizeof(char) * len);
	if (!new)
		return (NULL);
	ft_memcpy(new, s, len);
	return (new);
}

/**
 * Joins two strings into a new string.
 *
 * This function allocates memory and concatenates `s1` and `s2` into a new
 * string. The memory allocated for the new string should be freed by the
 * caller. If `s1` is not `NULL`, it will be freed.
 *
 * @param s1 The first string.
 * @param s2 The second string.
 * @return A pointer to the newly allocated string, or `NULL` if the
 *         allocation fails.
 */
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
	{
		if (s1)
			free(s1);
		return (NULL);
	}
	ft_memcpy(new_s, s1, s1_len);
	ft_memcpy(new_s + s1_len, s2, s2_len + 1);
	if (s1)
		free(s1);
	return (new_s);
}
