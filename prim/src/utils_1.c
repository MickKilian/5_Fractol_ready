/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 22:58:35 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/07/19 03:57:23 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

double	ft_abs(double a)
{
	if (a < 0)
		a = a * (-1);
	return (a);
}

double	ft_modulo(double x, double y)
{
	int	res;

	res = (int)(x / y);
	if (y)
		return (x - res * y);
	else
		return (-1);
}
