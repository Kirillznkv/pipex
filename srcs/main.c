/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 00:51:28 by kshanti           #+#    #+#             */
/*   Updated: 2021/07/31 19:21:59 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int main(int argc, char **argv, char **env)
{
    t_commands   commands;

    if (argc != 5)
        return (error("Error: argument\n"));
    if (set_commands(&commands, &(argv[1])))
        return (1);
    if (start_commands(&commands, env))
        return (1);
    return (0);
}