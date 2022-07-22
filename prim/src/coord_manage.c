/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_manage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 01:35:13 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/07/19 03:55:17 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

int	ft_assign_coord(t_data *prm, int x, int y)
{
	prm->coord[0] = x;
	prm->coord[1] = y;
	ft_coord2cmplx(prm);
	return (0);
}

int	ft_assign_cmplx(t_data *prm, long double x, long double y)
{
	prm->cmplx[0] = x;
	prm->cmplx[1] = y;
	ft_cmplx2coord(prm);
	return (0);
}

int	ft_coord2cmplx(t_data *prm)
{
	prm->cmplx[0] = prm->min_re + (prm->coord[0] * prm->re_factor);
	prm->cmplx[1] = prm->max_im - (prm->coord[1] * prm->im_factor);
	return (0);
}

int	ft_cmplx2coord(t_data *prm)
{
	prm->coord[0] = (prm->cmplx[0] - prm->min_re) / prm->re_factor;
	prm->coord[1] = -(prm->cmplx[1] - prm->max_im) / prm->im_factor;
	return (0);
}
