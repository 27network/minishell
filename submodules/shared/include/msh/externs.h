/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   externs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 19:09:21 by kiroussa          #+#    #+#             */
/*   Updated: 2024/02/20 21:59:57 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXTERNS_H
# define EXTERNS_H

/**
 * Allowed functions:
 *
 * readline, rl_clear_history, rl_on_new_line,
 * rl_replace_line, rl_redisplay, add_history,
 * printf, malloc, free, write, access, open, read,
 * close, fork, wait, waitpid, wait3, wait4, signal,
 * sigaction, sigemptyset, sigaddset, kill, exit,
 * getcwd, chdir, stat, lstat, fstat, unlink, execve,
 * dup, dup2, pipe, opendir, readdir, closedir,
 * strerror, perror, isatty, ttyname, ttyslot, ioctl,
 * getenv, tcsetattr, tcgetattr, tgetent, tgetflag,
 * tgetnum, tgetstr, tgoto, tputs
 */

# include <curses.h>
# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <term.h>
# include <termios.h>
# include <unistd.h>

#endif // EXTERNS_H
