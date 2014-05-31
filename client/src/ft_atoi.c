/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 03:39:35 by lverniss          #+#    #+#             */
/*   Updated: 2014/02/07 20:02:57 by lverniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "client.h"

int		ft_atoi(const char *str)
{
		int		returned_value;
		int		counter;
		int		negativ;

		returned_value = 0;
		counter = 0;
		negativ = 1;
		while (str[counter] == '-')
		{
			negativ = -1;
			counter++;
		}
		while (str[counter] == '+')
			counter++;
		while (str[counter] >= '0' && str[counter] <= '9')
		{
			returned_value *= 10;
			returned_value += (str[counter] - '0');
			counter++;
		}
		return (returned_value * negativ);
}
