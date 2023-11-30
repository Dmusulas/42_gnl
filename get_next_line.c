/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:37:35 by dmusulas          #+#    #+#             */
/*   Updated: 2023/11/30 18:36:51 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*readline(int fd, char *buff, char *remaining)
{
	int	bytes;

	bytes = read(fd, buff, BUFFER_SIZE);
	if (ft_strchr(buff, '\n'))
		return (buff);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*line;
	char		*remaining;

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
