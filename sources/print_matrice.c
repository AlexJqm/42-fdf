/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_matrice.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coremart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 15:31:53 by coremart          #+#    #+#             */
/*   Updated: 2019/01/20 15:31:54 by coremart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"
#include "libft/libft.h"

void    print_matrice(t_matrice *matrice)
{
    size_t i;

    i = 0;
    while (matrice)
    {
        i = 0;
        while (i < matrice->len)
        {
            ft_putnbr(matrice->line[i++]);
            ft_putchar(' ');
        }
        ft_putchar('\n');
        matrice = matrice->next;
    }
}