/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heonamjun <nheo@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:42:01 by heonamjun         #+#    #+#             */
/*   Updated: 2022/07/12 16:42:02 by heonamjun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

void	ft_error(char *str)
{
	perror(str);
	exit(1);
}

void	ft_error_cmd_not_found(char *cmd)
{
	write(2, "command not found: ", ft_strlen("command not found: "));
	write(2, cmd, ft_strlen(cmd));
	write(2, "\n", 1);
	exit(1);
}