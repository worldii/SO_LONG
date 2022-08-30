/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapark <jonghapark@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 03:31:08 by jonghapark        #+#    #+#             */
/*   Updated: 2022/08/31 03:31:08 by jonghapark       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

static int is_newline(char *buf)
{
    int i;

    i = -1;
    while (buf[++i])
    {
        if (buf[i] == '\n')
            return (i);
    }
    return (-1);
}

static char *split_line(char **backbuf, char *buf)
{
    char *line;
    int idx;
    char *temp;

    line = NULL;
    idx = is_newline(*backbuf);
    if (idx == -1)
    {
        if (*backbuf[0] != 0)
            line = ft_strndup(*backbuf, 0, ft_strlen(*backbuf));
        free(*backbuf);
        *backbuf = NULL;
    }
    else
    {
        line = ft_strndup(*backbuf, 0, idx + 1);
        temp = ft_strndup(*backbuf, idx + 1, ft_strlen(*backbuf) - idx - 1);
        free(*backbuf);
        *backbuf = temp;
    }
    free(buf);
    return (line);
}

static char *get_read_line(int fd, char *buf, char **backup)
{
    int read_size;
    char *newbackup;
    int nextidx;

    read_size = read(fd, buf, BUFFER_SIZE);
    while (read_size > 0)
    {
        buf[read_size] = 0;
        newbackup = ft_strjoin(*backup, buf);
        free(*backup);
        *backup = newbackup;
        nextidx = is_newline(*backup);
        if (nextidx != -1)
            return (split_line(backup, buf));
        read_size = read(fd, buf, BUFFER_SIZE);
    }
    return (split_line(backup, buf));
}

char *get_next_line(int fd)
{
    char *buf;
    static char *backup;

    buf = (char *)malloc(BUFFER_SIZE + 1);
    if (buf == NULL)
        return (0);
    if (BUFFER_SIZE == 0 || read(fd, buf, 0) == -1)
    {
        free(buf);
        return (0);
    }
    if (backup != NULL && is_newline(backup) != -1)
        return (split_line(&backup, buf));
    if (backup == 0)
        backup = ft_strndup("", 0, 0);
    return (get_read_line(fd, buf, &backup));
}