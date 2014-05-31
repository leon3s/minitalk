/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 19:20:30 by lverniss          #+#    #+#             */
/*   Updated: 2014/02/07 20:31:06 by lverniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "server.h"

typedef unsigned long int addr;

void		decode(int bin)
{
	static char	c;
	static int	i;

	c += (bin << i++);
	if (i > 7)
	{
		ft_putchar((c == '\0') ? '\n' : c);
		c = 0;
		i = 0;
	}
}

void		sig(int	sign)
{
	if (sign == SIGUSR1)
		decode(1);
	if (sign == SIGUSR2)
		decode(0);
}

void	init_sig(void)
{
	usleep(1000);
	if (signal(SIGUSR1, sig) == SIG_ERR)
	{
		printf("SIGUSR1 ERROR\n");
		return ;
	}
	if (signal(SIGUSR2, sig) == SIG_ERR)
	{
		printf("SIGUSR2 ERROR\n");
		return ;
	}
}

void	decode_addr(int bin)
{
	static addr	i;
	static addr	adr;

	adr += (bin << i++);
	if (i > 63)
	{
		printf("%li\n", adr);
		adr = 0;
		i = 0;
	}
}

void	sig_addr(int sign)
{
	if (sign == SIGUSR1)
		decode_addr(1);
	if (sign == SIGUSR2)
		decode_addr(2);
}

void	init_addr_msg(void)
{
	usleep(1000);
	if (signal(SIGUSR1, sig_addr) == SIG_ERR)
	{
		printf("SIGUSR1 ERROR\n");
		return ;
	}
	if (signal(SIGUSR2, sig_addr) == SIG_ERR)
	{
		printf("SIGUSR2 ERROR\n");
		return ;
	}
}

void	init_server(void)
{
	printf("Server PID : %d\n", getpid());
}

int		main(void)
{
	printf("%li\n", sizeof(pid_t));
	init_addr_msg();
	init_sig();
	printf("%li\n", sizeof(unsigned long int));
	init_server();
	while (42)
		pause();
	return (0);
}
