/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamed <mohamed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 12:54:05 by mbahstou           #+#    #+#             */
/*   Updated: 2021/01/25 12:54:06 by mbahstou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

//comprueba si el mapa es valido ###crear funcion para gestionar los returns###
/*int check_map (t_data *data, int i, int j)
{
    if (data->copy[i][j] == '0')
    {
        data->copy[i][j] = '.';
        if (check_map(data, i, j + 1) || check_map(data, i, j - 1) ||
            check_map(data, i + 1, j) || check_map(data, i - 1, j))
                return (1);
        else
                return (0);
    }
    else if (data->copy[i][j] == '1' || data->copy[i][j] == '.')
        return (0);
    else if (data->copy[i][j] == ' ' || data->copy[i][j] == '\0')
        return (1);
    return (1);
}*/
//                             funciones provisionales
void to_zero (t_data *data, int i, int j)
{

    data->copy[i][j] = '0';
    check_valid(data, i - 1, j);
    check_valid(data, i + 1, j);
    check_valid(data, i, j - 1);
    check_valid(data, i, j + 1);
}
void check_valid (t_data *data, int i, int j)
{
    int ord;

    ord = 0;
    if (i < 0 || j < 0)
        return ;
    if (i > data->rows - 1)
        return ;
    if (data->copy[i][j] != '1')
        return ;
    if (i > 0)
        if (data->copy[i - 1][j] == '1')
            ord++;
    if (i < data->rows - 1)
        if (data->copy[i + 1][j] == '1')
            ord++;
    if (j > 0)
        if (data->copy[i][j - 1] == '1')
            ord++;
    if (data->copy[i][j + 1] == '1')
        ord++;
    if (ord < 2)
        to_zero(data, i, j);
}

void check_map2(t_data *data)
{
    int i;
    int j;
    i = 0;
    while (i < data->rows)
	{
		j = 0;
		while (data->copy[i][j] != '\0')
		{
			if (data->copy[i][j] == '1')
                check_valid(data, i, j);
			j++;
		}
		i++;
	}
}
//                             funciones provisionales

//encuentra la orientación del jugador
void p_position (t_data *data, int i, int j)
{
    data->player->posx = i;
    data->player->posy = j;
    if (data->copy[i][j] == 'N')
        data->player->dir = 'N';
    else if (data->copy[i][j] == 'S')
        data->player->dir = 'S';
    else if (data->copy[i][j] == 'E')
        data->player->dir = 'E';
    else if (data->copy[i][j] == 'W')
        data->player->dir = 'W';
    data->copy[i][j] = '0';
    //check_map2(data);
}
// encuentra la posicion del jugador
void p_finder (t_data *data)
{
    int i;
    int j;

    i = 0;
    while (i < data->rows)
    {
        j = 0;
        while (data->copy[i][j] != '\0')
        {
            if (data->copy[i][j] == 'N' || data->copy[i][j] == 'S'
            || data->copy[i][j] == 'E' || data->copy[i][j] == 'W')
            {
                //p_position(data, i, j);
                data->copy[i][j] = '0';
                check_map2(data);
            }
            else if (data->copy[i][j] == '2')
                data->copy[i][j] = '0';
            j++;
        }
        i++;
    }
}
//copia el mapa para hacer en la copia las comprobaciones
void map_errors (t_data *data)
{
    int i;
    int j;

    i = 0;
    if (!(data->copy = (char**)malloc( data->rows * sizeof(char*))))
		printf("fail allocating memory");
	while (i < data->rows)
	{
		if (!(data->copy[i] = (char*)malloc(data->cols * sizeof(char))))
			printf("fail allocating memory");
		i++;
	}
    i = 0;
    while (i < data->rows)
	{
		j = 0;
		while (j < data->cols)
		{
			data->copy[i][j] = data->matrix_map[i][j];
			j++;
		}
		i++;
	}
    p_finder(data);
}
