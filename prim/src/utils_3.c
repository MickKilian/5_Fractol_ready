/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:35:14 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/07/19 03:57:29 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned const char	*t1;
	unsigned const char	*t2;

	t1 = (unsigned const char *)s1;
	t2 = (unsigned const char *)s2;
	while (*t1 || *t2)
	{
		if (*t1 != *t2 || !*t1 || !*t2)
			return (*t1 - *t2);
		t1++;
		t2++;
	}
	return (0);
}
