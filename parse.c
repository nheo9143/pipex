/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heonamjun <nheo@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:53:03 by heonamjun         #+#    #+#             */
/*   Updated: 2022/07/12 16:53:09 by heonamjun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_files(int ac, char *av[])
{
	char	**files;

	files = (char **)malloc(sizeof(char *) * (FILE_NUM + 1));
	if (!files)
		ft_error("malloc");
	files[INFILE] = ft_strdup(av[1]);
	files[OUTFILE] = ft_strdup(av[ac - 1]);
	files[FILE_NUM] = NULL;
	return (files);
}

char	**get_cmds(int ac, char *av[])
{
	char	**cmds;

	cmds = (char **)malloc(sizeof(char *) * (ac - 1));
	if (!cmds)
		ft_error("malloc");
	cmds[ac - 2] = NULL;
	while (ac > 2)
	{
		cmds[ac - 3] = ft_strdup(av[ac - 1]);
		ac--;
	}
	return (cmds);
}

char	*get_path(char *ev[])
{
	int		i;
	char	*path;

	i = 0;
	while (*ev)
	{
		if (ft_strncmp(*ev, "PATH=", 5) == 0)
		{
			path = ft_strtrim(*ev + 5);
			return (path);
		}
		ev++;
	}
	ft_error("path error");
	return (NULL);
}

char	*get_file_path(char *ev[], char *cmd)
{
	int		i;
	char	**pathes;
	char	*path1;
	char	*path2;
	char	*result;

	i = -1;
	pathes = ft_split(get_path(ev), ":");
	result = NULL;
	while (pathes[++i])
	{
		path1 = ft_strjoin(pathes[i], "/");
		path2 = ft_strjoin(path1, cmd);
		if (access(path2, F_OK) == 0)
			result = ft_strdup(path2);
		free(path1);
		free(path2);
		free(pathes[i]);
	}
	free(pathes);
	if (!result)
		ft_error(cmd);
	return (result);
}

void	ft_open_file(char *file, int *fd, int option)
{
	if (option == 'w')
		*fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	else if (option == 'r')
		*fd = open(file, O_RDONLY);
	if (*fd < 0)
		ft_error(file);
}
