/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heonamjun <nheo@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:43:48 by heonamjun         #+#    #+#             */
/*   Updated: 2022/07/12 16:44:06 by heonamjun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <fcntl.h>

void	check_ac_num(int ac)
{
	if (ac != 5)
	{
		ft_error("wrong number of arguments");
		exit(ERROR);
	}
}

int	main(int ac, char *av[], char *ev[])
{
	char	**files;
	char	**cmds;

	check_ac_num(ac);
	files = get_files(ac, av);
	cmds = get_cmds(ac, av);
	pipex(files, cmds, ev, ac - 3);
	return (0);
}
