/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coremart <coremart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 15:31:05 by coremart          #+#    #+#             */
/*   Updated: 2019/01/24 18:40:27 by aljacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <mlx.h>

#include <stdio.h>

static void    put_pixel(int x, int y, int color, char *img_str)
{
    unsigned int pixel;

    if (x >= LENGHT || y >= HEIGHT || x < 0 || y < 0)
        return ;
    pixel = (y * LENGHT + x) * 4;
    img_str[pixel] = color;
    img_str[pixel + 1] = color >> 8;
    img_str[pixel + 2] = color >> 16;
}

static void    draw_line(t_points *points, int color, char *img_str)
{
    int dx;
    int dy;
	int sign_x;
    int sign_y;
	int x;
    int y;
	int		error[2];

	dx = ft_absolute(points->x2 - points->x1);
	dy = ft_absolute(points->y1 - points->y2);
	sign_x = points->x1 < points->x2 ? 1 : -1;
	sign_y = points->y1 < points->y2 ? 1 : -1;
	error[0] = dx - dy;
    x = points->x1;
    y = points->y1;
	while (x != points->x2 || y != points->y2)
	{
		put_pixel(x, y, color, img_str);
		if ((error[1] = error[0] * 2) > -dy)
		{
			error[0] -= dy;
			x += sign_x;
		}
		if (error[1] < dx)
		{
			error[0] += dx;
			y += sign_y;
		}
	}
}

static void    add_points(t_vector_tab *tab, t_data *data, int i, int j)
{
    data->points->x1 = (int)(tab->tab[i][j].x + LENGHT / 2.0f);
    data->points->y1 = (int)(tab->tab[i][j].y + HEIGHT / 2.0f);
    if (j + 1 != tab->nb_col)
    {
        data->points->x2 = (int)(tab->tab[i][j + 1].x + LENGHT / 2.0f);
        data->points->y2 = (int)(tab->tab[i][j + 1].y + HEIGHT / 2.0f);
        draw_line(data->points, 0xFFFFFF, data->img_info->img_str);
    }
    if (i + 1 != tab->nb_lines)
    {
        data->points->x2 = (int)(tab->tab[i + 1][j].x + LENGHT / 2.0f);
        data->points->y2 = (int)(tab->tab[i + 1][j].y + HEIGHT / 2.0f);
        draw_line(data->points, 0xFFFFFF, data->img_info->img_str);
    }
}

void    draw(t_data *data)
{
    int i;
    int j;

    i = 0;
    while (i < data->tab->nb_lines)
    {
        j = 0;
        while (j < data->tab->nb_col)
            add_points(data->tab, data, i, j++);
        i++;
    }
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_info->img_ptr, 0, 0);
    print_menu(data);
    mlx_hook(data->win_ptr, 2, 0, &key_press, data);
    mlx_hook(data->win_ptr, 4, 0, &mouse_press, data->mouse);
    mlx_hook(data->win_ptr, 5, 0, &mouse_release, data->mouse);
    mlx_hook(data->win_ptr, 6, 0, &mouse_move, data);
    mlx_hook(data->win_ptr, 17, 0, &close, data);
}
