/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapark <jonghapark@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 03:31:41 by jonghapark        #+#    #+#             */
/*   Updated: 2022/08/31 03:31:41 by jonghapark       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>
#define BUFFER_SIZE 1
char *get_next_line(int fd);
int ft_strlen(const char *str);
char *ft_strjoin(char const *s1, char const *s2);
char *ft_strndup(const char *src, int start, int num);

#endif
