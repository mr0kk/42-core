/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 21:43:11 by rmrok             #+#    #+#             */
/*   Updated: 2025/02/18 16:32:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h> 
# include <string.h>

char *get_next_line(int fd);

#endif
