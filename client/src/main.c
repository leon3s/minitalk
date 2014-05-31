/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 19:51:34 by lverniss          #+#    #+#             */
/*   Updated: 2014/02/07 20:32:04 by lverniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "client.h"
#include <stdio.h>

typedef unsigned long int addr;

size_t	ft_strlen(const char *str)
{
		size_t	cn;

		cn = -1;
		while (str[++cn])
			;
		return (cn);
}

void	ft_error(char *msg)
{
		write(2, msg, ft_strlen(msg));
}

void	send_msg(int server_pid, char msg)
{
		char	c;

		c = -1;
		while (++c < 8)
		{
			usleep(1000);
			if (((msg >> c) & 1) == 1)
			{
				if (kill(server_pid, SIGUSR1) == -1)
				{
					ft_error("Error.\n");
					return ;
				}
			}
			else
			{
				if (kill(server_pid, SIGUSR2) == -1)
				{
					ft_error("Error.\n");
				}
			}
		}
		return ;
}

addr	return_addr(char *msg)
{
	addr	adr;

	adr = (addr)&msg;
	return (adr);
}

void	send_addr(pid_t server, addr msg)
{
	addr	c;

	c = -1;
	while (++c < 64)
	{
		usleep(1000);
		if (((msg >> c) & 1) == 1)
			kill(server, SIGUSR1);
		else
			kill(server, SIGUSR2);
	}
	return ;
}

void	init_client(char **av)
{
		int		cn;
		int		server_pid;
		const char	*msg;
		addr		amsg;

		server_pid = ft_atoi(av[1]);
		msg = av[2];
		cn = -1;
		printf("pointer msg : %p\n", &msg);
		amsg = return_addr(av[2]);
		printf("addrmsg : %li", amsg);
		send_addr(server_pid, amsg);
		while (msg[++cn])
			send_msg(server_pid, msg[cn]);
		send_msg(server_pid, msg[cn]);
		return ;
}

int		main(int ac, char **av)
{
	if (ac != 3)
	{
		ft_error("Usage : ./client PIDSERVER message\n");
		return (0);
	}
	init_client(av);
	return (0);
}
