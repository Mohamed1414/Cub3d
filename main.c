/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamed <mohamed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 18:37:13 by mbahstou          #+#    #+#             */
/*   Updated: 2021/03/19 00:21:34 by mohamed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_init(t_data *data)
{
	data->resx = 0;
	data->resy = 0;
	data->ceiling = malloc(sizeof(t_color));
	data->floor = malloc(sizeof(t_color));
}

int		main(int argc, char *argv[])
{
	t_data *data;

	data = malloc(sizeof(t_data));
	ft_init(data);
	if (argc < 2 || argc >= 3 /*&& !ft_strcmp(argv[2], "--save")*/)
	////hacer stringcompare
	{
		printf("Entry missing arguments");
		return (1);
	}
	data->fd = open(argv[1], O_RDONLY);
	if (data->fd < 0)
	{
		printf("Error while opening the file");
		return (1);
	}
	description_read(data);
	return (0);
}
