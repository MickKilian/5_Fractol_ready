/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_convert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 03:44:20 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/07/19 03:54:38 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

int	ft_trgb2val(t_color *color)
{
	color->val = color->trgb[0] << 24 | color->trgb[1] << 16
		| color->trgb[2] << 8 | color->trgb[3];
	return (0);
}

int	ft_val2trgb(t_color *color)
{
	color->trgb[0] = ((color->val >> 24) & 0xFF);
	color->trgb[1] = ((color->val >> 16) & 0xFF);
	color->trgb[2] = ((color->val >> 8) & 0xFF);
	color->trgb[3] = ((color->val) & 0xFF);
	return (0);
}

int	ft_thsv2trgb(t_color *c)
{
	double	m;
	double	n;
	double	z;
	int		k;

	m = 255 * c->thsv[3];
	n = m * (1 - c->thsv[2]);
	z = (m - n) * (1 - ft_abs(ft_modulo((c->thsv[1] / 60), 2) - 1));
	z += n;
	k = c->thsv[1] / 60 + 1;
	c->trgb[0] = c->thsv[0];
	c->trgb[1] = (k == 1 || k == 6) * m + (k == 3 || k == 4) * n
		+ (k == 2 || k == 5) * z;
	c->trgb[2] = (k == 2 || k == 3) * m + (k == 5 || k == 6) * n
		+ (k == 1 || k == 4) * z;
	c->trgb[3] = (k == 4 || k == 5) * m + (k == 1 || k == 2) * n
		+ (k == 3 || k == 6) * z;
	ft_trgb2val(c);
	return (0);
}
