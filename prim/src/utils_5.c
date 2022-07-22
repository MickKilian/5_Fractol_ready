/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:50:13 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/07/19 03:57:55 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

int	ft_atoi(char *nptr)

{
	t_clcai	clc;
	int		ret;

	clc.n = 0;
	clc.sign = 1;
	clc.countzero = 0;
	clc.i = 0;
	clc.len = ft_strlen(nptr);
	while ((nptr[clc.i] >= '\t' && nptr[clc.i] <= '\r')
		|| (nptr[clc.i] == ' '))
		clc.i++;
	if (nptr[clc.i] == '-' || nptr[clc.i] == '+')
	{
		clc.sign = -2 * (nptr[clc.i] == '-') + 1;
		if (nptr[clc.i++] == '+')
			clc.countzero++;
	}
	while (nptr[clc.i++] == '0')
		clc.countzero++;
	clc.i--;
	clc = ft_atoi_b(nptr, clc);
	ret = clc.sign * clc.n;
	return ((double)ret);
}

t_clcai	ft_atoi_b(char *nptr, t_clcai clc)
{
	while ((nptr[clc.i] >= '0' && nptr[clc.i] <= '9') || nptr[clc.i] == '.')
	{
		nptr[clc.i - clc.countzero] = nptr[clc.i];
		clc.n = clc.n * 10 + nptr[clc.i++] - '0';
	}
	while (nptr[clc.i])
	{
		nptr[clc.i - clc.countzero] = nptr[clc.i];
		clc.i++;
	}
	if (clc.len == (clc.countzero + (clc.sign == -1)))
	{
		clc.countzero--;
		nptr[0] = '0';
		nptr[1] = '\0';
	}
	while (clc.countzero)
		nptr[clc.i - clc.countzero--] = '\0';
	return (clc);
}

char	*ft_itoa(int n)
{
	int		sign;
	int		nb_carac;
	char	*str;

	nb_carac = ft_getsize(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = malloc((nb_carac + 1) * sizeof(char));
	if (!str)
		return (NULL);
	sign = (n < 0);
	n = n - 2 * n * (n < 0);
	if (sign == 1)
		str[0] = '-';
	str[nb_carac] = '\0';
	while (nb_carac - sign)
	{
		str[nb_carac - 1] = n % 10 + '0';
		n = n / 10;
		nb_carac--;
	}
	return (str);
}

char	*ft_strdup(const char *s)
{
	char	*cpy;
	int		i;

	cpy = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!cpy)
		return (NULL);
	i = 0;
	while (*(s + i))
	{
		*(cpy + i) = *(s + i);
		i++;
	}
	*(cpy + i) = '\0';
	return (cpy);
}
