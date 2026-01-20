/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 11:59:02 by anasinda          #+#    #+#             */
/*   Updated: 2026/01/20 12:03:31 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This is the entry point to test your get_next_line bonus implementation.
** The bonus version supports reading from multiple file descriptors
** simultaneously, each maintaining its own reading state.
**
** Example usage with multiple fds:
**   int fd1 = open("file1.txt", O_RDONLY);
**   int fd2 = open("file2.txt", O_RDONLY);
**   printf("%s", get_next_line(fd1));  // Line 1 from file1
**   printf("%s", get_next_line(fd2));  // Line 1 from file2
**   printf("%s", get_next_line(fd1));  // Line 2 from file1
**   // Don't forget to free each line and close fds!
**
** Compile with: make bonus
** Run with: ./program_bonus
*/

#include "get_next_line_bonus.h"

int	main(void)
{
	/* Add your test code here */
	return (0);
}
