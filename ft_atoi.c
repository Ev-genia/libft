/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 11:56:39 by mlarra            #+#    #+#             */
/*   Updated: 2021/10/19 15:59:30 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long int	ft_strnbr(const char *str)
{
	long int	nbr;
	int			k;
	int			i;

	nbr = 0;
	k = 1;
	i = 0;
	while (*str >= '0' && *str <= '9')
	{
		if (nbr < 0 && nbr * 10 > nbr)
			return (0);
		if (nbr > nbr * 10)
			return (-1);
		nbr = nbr * k + (*str - '0');
		k = 10;
		str++;
		i++;
	}
	return (nbr);
}

int	ft_atoi(const char *str)
{
	int			minus;
	long int	nbr;

	while (*str == '\t' || *str == '\n' || *str == '\v'\
		|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	minus = 1;
	if (*str == '-')
	{
		minus = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	nbr = ft_strnbr(str);
	return ((int)(nbr * minus));
}
