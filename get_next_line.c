/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:37:35 by dmusulas          #+#    #+#             */
/*   Updated: 2023/11/30 20:47:59 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*readline(int fd, char *buff, char *remaining)
{
	int	bytes;

	while (ft_strchr(remaining, '\n') && remaining)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (!(bytes > 0))
			return (NULL);
	}
}

char	*get_next_line(int fd)
{
	static char		*line;
	char			*remaining;
	char			*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	line = readline(fd, buffer, remaining);
	return (line);
}
// #include <stdio.h>
//
// int	main(void)
// {
// 	int	file = open("test.txt", O_RDONLY);
//
// 	while (1)
// 	{
// 		char *r = get_next_line(file);
// 		if (!r)
// 			break ;
// 		else
// 			printf("%s", r);
// 	}
// 	return EXIT_SUCCESS;
// }
