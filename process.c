/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heonamjun <nheo@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:51:28 by heonamjun         #+#    #+#             */
/*   Updated: 2022/07/12 16:51:30 by heonamjun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	outfile_process(char **files, char *cmds, int *fd, char **ev)
{
	int		outfile_fd;
	char	*file_path;
	char	**options;

	close(fd[WRITE]);
	ft_open_file(files[OUTFILE], &outfile_fd, 'w');
	dup2(fd[READ], STDIN_FILENO);
	dup2(outfile_fd, STDOUT_FILENO);
	close(outfile_fd);
	close(fd[READ]);
	options = ft_split(cmds, " \t\v\r\f\n");
	file_path = get_file_path(ev, options[0]);
	execve(file_path, options, ev);
	ft_error("execve");
}

void	infile_process(char **files, char *cmds, int *fd, char *ev[])
{
	int		infile_fd;
	char	*file_path;
	char	**options;

	close(fd[READ]);
	ft_open_file(files[INFILE], &infile_fd, 'r');
	dup2(infile_fd, STDIN_FILENO);
	dup2(fd[WRITE], STDOUT_FILENO);
	close(infile_fd);
	close(fd[WRITE]);
	options = ft_split(cmds, " \t\v\r\f\n");
	file_path = get_file_path(ev, options[0]);
	execve(file_path, options, ev);
	ft_error("execve");
}

void	wait_process(int pipe_num)
{
	while (pipe_num--)
		wait(NULL);
}

void	pipex(char **files, char **cmds, char *ev[], int pipe_num)
{
	int		i;
	int		fd[2];
	pid_t	pid[2];

	i = -1;
	if (pipe(fd) == -1)
		ft_error("pipe");
	while (++i < pipe_num)
	{
		pid[i] = fork();
		if (i == 0 && pid[i] == 0)
			infile_process(files, cmds[0], fd, ev);
		else if (pid[i] == 0)
			outfile_process(files, cmds[1], fd, ev);
	}
	close(fd[0]);
	close(fd[1]);
	wait_process(pipe_num);
}
