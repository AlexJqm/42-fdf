/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coremart <coremart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 00:26:43 by coremart          #+#    #+#             */
/*   Updated: 2019/01/20 20:19:24 by aljacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <mlx.h>
#include <stdlib.h>

t_data	*window_init(void)
{
	t_data	*data;

	if (!(data = (t_data*)malloc(sizeof(t_data))))
        return (0);
    if (!(data->img_info = (t_img_info*)malloc(sizeof(t_img_info))))
        return (0);
    data->mlx_ptr = mlx_init();
    data->win_ptr = mlx_new_window(data->mlx_ptr, LENGHT, HEIGHT, "FdF");
    data->img_info->img_ptr = mlx_new_image(data->mlx_ptr, LENGHT, HEIGHT);
    data->img_info->img_str = mlx_get_data_addr(data->img_info->img_ptr,
	&data->img_info->bpp, &data->img_info->len, &data->img_info->endian);
	return (data);
}

int		main(int ac, char **av)
{
	t_matrice *matrix;
	t_vector_tab *tab;
	t_data *data;

	if (ac == 2)
	{
		data = window_init();
		matrix = fill_map(av[1]);
		tab = convert_to_vector(matrix);
		mlx_loop(data->mlx_ptr);
	}
	return (0);
}
