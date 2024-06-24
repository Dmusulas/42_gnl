/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:37:35 by dmusulas          #+#    #+#             */
/*   Updated: 2023/12/06 16:51:23 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * Reads a line from a file descriptor.
 *
 * This function reads from the file descriptor `fd` into a buffer, appending
 * to the provided `line` string until a newline character is found or the end
 * of the file is reached. It handles errors by freeing allocated memory and
 * returning `NULL`.
 *
 * @param line The initial string to append the read characters to.
 * @param fd The file descriptor to read from.
 * @return The resulting string with the appended characters,
	or `NULL` on error.
 */
static char	*readline(char *line, int fd)
{
	char	*buffer;
	ssize_t	bytes;
	char	*found;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	found = 0;
	while (!found)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == 0)
			break ;
		else if (bytes == -1)
		{
			free(buffer);
			free(line);
			return (NULL);
		}
		buffer[bytes] = '\0';
		line = ft_strjoin(line, buffer);
		found = ft_strchr(line, '\n');
	}
	free(buffer);
	return (line);
}

/**
 * Extracts the remainder of the line after a newline character.
 *
 * This function finds the first newline character in the provided `line`
 * string and returns the remainder of the string after the newline. The
 * original newline character is replaced with a null terminator.
 *
 * @param line The string containing the line to process.
 * @return A new string containing the remainder after the newline, or `NULL`
 *         if there is no newline character.
 */
static char	*get_remainder(char *line)
{
	char	*next_line;
	char	*remainder;

	next_line = ft_strchr(line, '\n');
	if (!next_line++)
		return (NULL);
	remainder = ft_strdup(next_line);
	*next_line = '\0';
	return (remainder);
}

/**
 * Gets the next line from the file descriptor.
 *
 * This function reads the next line from the given file descriptor `fd` by
 * utilizing static memory to handle the remainder of the line from previous
 * reads. It combines reading and processing of the line to ensure complete
 * lines are returned.
 *
 * @param fd The file descriptor to read from.
 * @return A string containing the next line from the file descriptor.
 */
char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*line;

	line = readline(remainder, fd);
	remainder = get_remainder(line);
	return (line);
}
//
// #include <stdio.h>
//
// int	main(int argc, char *argv[])
// {
// 	if (argc != 2)
// 		return (EXIT_FAILURE);
//
// 	int	file = open(argv[1], O_RDONLY);
//
// 	while (1)
// 	{
// 		char *r = get_next_line(file);
// 		if (!r)
// 			break ;
// 		else
// 			printf("%s", r);
// 		free(r);
// 	}
// 	return (EXIT_SUCCESS);
// }
